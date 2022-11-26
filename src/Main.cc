#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#ifndef _WRAPPERS_INCL
#define _WRAPPERS_INCL
#include "../include/Wrappers.h"
#endif /* _WRAPPERS_INCL */
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "../include/Types.h"
#endif /* _TYPES_INCL */
#include "../include/menu.h"
#include "../include/board.h"
#include "../include/Movement.h"
#include "../include/__Logs.h"
#ifdef _WIN32
#include <conio.h> // To nie jest standardowa biblioteka ale jest tam zejebista funkcja ktora przyjmuje znak i nie czeka na enter _getch() <- to ona
#else
#include <termios.h>

static char getch()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
#endif


bool settingsChanged = false;


volatile static int abortSignal = 0;
static void abortHandler(int __abortSignal)
{
    logging.writeLog("Przerwanie dzialania przez sygnal");
    abortSignal = 1;
}


inline static void handleQuitSignals()
{
    signal(SIGINT, abortHandler);
    signal(SIGTERM, abortHandler);
}


#ifdef _WIN32
int __cdecl main(int argc, const char* argv[])
#else
int main(int argc, const char* argv[])
#endif
{
    Menu menu;
    Movement movement;

    menu.printBanner();
    menu.printMenu();
    
    u_short userOption;
    u_short settingsOption;

    logging.writeLog("Wejscie do petli wyboru opcji");

    do 
    {
        std::cout << "Wybierz opcje: ";
        handleQuitSignals();
  
        if (abortSignal == 1) 
        {
            CleanWindow();
            std::cout << "Opuszczanie...\n";
            __EXIT_SUCCESS;
        }
        
        std::cin >> userOption;

        if (userOption == 3) 
        {
            menu.printSettings(&movement.userSettings);

            std::cout << "Personalisacja ustawien: ";
            std::cin >> settingsOption;
            
            switch (settingsOption) 
            {
                case 1:
                    movement.changeMovementToArrows();
                    settingsChanged = true;
                    std::cout << "\nUstawienia zostaly zmienione\n\n";

                    logging.writeLog("Zmieniono ustawienia sterowania");
                break;
                case 2:
                    settingsChanged = false;
                    std::cout << "\nNic nie zmieniono\n";

                    logging.writeLog("Ustawienia, Opcja [2] -> Nic nie zmieniono");
                break;
                case 3:
                    settingsChanged = false;
                    std::cout << "\nPrzywrocono domyslne\n";
                    movement.reset();

                    logging.writeLog("Przywrocono ustawienia sterowania do ustawien domyslnych");
                break;
            }
        }

        if (userOption == 5)
        {
            CleanWindow();            

            menu.printBanner();
            menu.printMenu();
        }

        menu.getOption(userOption, movement.userSettings);
    } while (userOption != 1);

    logging.writeLog("Rozpoczynanie gry");

    Board board;
    
    CleanWindow();

    std::cout << "Rozpoczynanie...\n";
    
    // system("timeout 1 > NULL");
    std::cout << "Tworzenie mapy...\n";
    // system("timeout 2 > NULL");
    CleanWindow();

    board.renderBoard();

    char userInput;

    static int movesMade = 0;
    static int movesLeft = LEVEL_EASY_MOVES_COUNT;
    static int redo = 0;

    logging.writeLog("Wejscie do petli glownej");

    while (userInput != 'q') 
    {
        menu.printInlineGameHelp(movesLeft, movesMade, 0);
        board.printBoard();
        handleQuitSignals();
#ifdef _WIN32
        userInput = _getch();
#else
        userInput = getch();
#endif
        board.changePlayersPosition(userInput, settingsChanged);

        if (userInput == movement.userSettings.goDOWN || userInput == movement.userSettings.goUP
            || userInput == movement.userSettings.goRIGHT || userInput == movement.userSettings.goLEFT)
        {
            movesLeft--;
            movesMade++;
        }
        else if (userInput == movement.userSettings.undo)
        {
            if (movesMade != 0 && movesLeft != LEVEL_EASY_MOVES_COUNT)
            {
                movesLeft += movesMade;
                movesMade = 0;
            }
        }
        else if (userInput == movement.userSettings.redo)
        {
            if (movesMade != 0 && movesLeft != LEVEL_EASY_MOVES_COUNT && redo <= 10) 
            {
                movesLeft += 1;
                movesMade--;
                redo++;
            }
        }
        else
        {
            // pass;
        }

        CleanWindow();
    }

    board.Clean();

    logging.writeLog("Wychodzenie z gry");

    return 0;
}