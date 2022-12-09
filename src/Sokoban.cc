#include <iostream>
#include "../include/Sokoban.h"

#if defined(_WIN32)
#include <conio.h>
#elif defined(__linux__)
#include <termios.h>
#include <unistd.h>

static char getch()
{
    char buf = 0;
    struct termios old = { 0 };

    fflush(stdout);

    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");

    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");

    if (read(0, &buf, 1) < 0)
        perror("read()");

    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    
    return buf;
}
#else
#error "Nieobslugiwany system operacyjny"
#endif


// Konstruktor
Sokoban::Sokoban()
{
    this->_menu = new Menu;
    this->_movement = new Movement;
    this->_board = new Board;

    this->_settingsChanged = false;
}


// Destruktor
Sokoban::~Sokoban()
{
    delete this->_board;
    delete this->_menu;
    delete this->_movement;
}


void Sokoban::menuEntryPoint()
{
    this->_menu->printBanner();
    this->_menu->printMenu();
}


u_short Sokoban::optionsSelection()
{
        std::cout << "-> Wybierz opcje: ";

#if defined(_WIN32) 
        this->_userOption = _getch();
#elif defined(__linux__)
        this->_userOption = getch();
#endif

        if (this->_userOption == 48)
        {
            CleanWindow();
            this->_menu->printBanner();
            this->_menu->printMenu();
        }

        if (_userOption == 51) 
        {
            this->_menu->printSettings(&_movement->userSettings);

            std::cout << "[" << GREEN << "+" << RESET << "] " << "Personalisacja ustawien: ";

#if defined(_WIN32)
            this->_settingsOption = _getch();
#elif defined(__linux__)
            this->_settingsOption = getch();
#endif
            
            switch (this->_settingsOption) 
            {
                case 49:
                    this->_movement->changeMovementToArrows();
                    this->_settingsChanged = true;
                    std::cout << "\nUstawienia zostaly zmienione\n\n";

                    logging->writeLog("Zmieniono ustawienia sterowania");
                break;
                case 50:
                    this->_settingsChanged = false;
                    std::cout << "\nNic nie zmieniono\n";

                    logging->writeLog("Ustawienia, Opcja [2] -> Nic nie zmieniono");
                break;
                case 51:
                    this->_settingsChanged = false;
                    std::cout << "\nPrzywrocono domyslne\n";
                    this->_movement->reset();

                    logging->writeLog("Przywrocono ustawienia sterowania do ustawien domyslnych");
                break;
                default:
                break;
            }
        }

        if (this->_userOption == 53)
        {
            CleanWindow();            

            this->_menu->printBanner();
            this->_menu->printMenu();
        }

        if (this->_userOption == 'q' || this->_userOption == 3)
        {
            CleanWindow();
            __EXIT_SUCCESS;
        }

        this->_menu->getOption(this->_userOption, this->_movement->userSettings);

    return this->_userOption;
}


void Sokoban::startGame()
{
    CleanWindow();

    std::cout << "Rozpoczynanie...\n";
    std::cout << "Tworzenie mapy...\n";
    
    CleanWindow();

    this->_board->renderBoard();
}


char Sokoban::mainLoop(int& movesLeft, int& movesMade, int& redo)
{
        this->_menu->printInlineGameHelp(movesLeft, movesMade, 0);
        this->_board->printBoard();

#if defined(_WIN32)
        this->_userInput = _getch();
#else
        this->_userInput = getch();
#endif
        int currentPosition = this->_board->changePlayersPosition(this->_userInput, settingsChanged);

        if (movesMade == LEVEL_EASY_MOVES_COUNT)
        {
            CleanWindow();
            std::cout << "Przegrales\n";
            __EXIT_SUCCESS;
        }

        if ((this->_userInput == this->_movement->userSettings.goDOWN || this->_userInput == this->_movement->userSettings.goUP
            || this->_userInput == this->_movement->userSettings.goRIGHT || this->_userInput == this->_movement->userSettings.goLEFT) && currentPosition != 1)
        {
            movesLeft--;
            movesMade++;
        }
        else if (this->_userInput == this->_movement->userSettings.undo)
        {
            if (movesMade != 0 && movesLeft != LEVEL_EASY_MOVES_COUNT)
            {
                movesLeft += movesMade;
                movesMade = 0;
            }
        }
        else if (this->_userInput == this->_movement->userSettings.redo)
        {
            if (movesMade != 0 && movesLeft != LEVEL_EASY_MOVES_COUNT && redo <= 10) 
            {
                movesLeft += 1;
                movesMade--;
                redo++;
            }
        }
        else
            ;

        CleanWindow();
    
    return this->_userInput;
}