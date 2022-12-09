#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../include/Sokoban.h"


bool settingsChanged = false;


#if defined(_WIN32)
int __cdecl main(int argc, const char* argv[])
#else
int main(int argc, const char* argv[])
#endif
{
#if defined(_WIN32)
#if defined(_WIN64)
logging->writeLog("OS: Windows x64");
#else
logging.writeLog("OS: Windows x32")
#endif
#elif defined(__linux__)
logging.writeLog("OS: Linux");
#else
#error "Nieobslugiwany system operacyjny"
#endif
    Sokoban* sokoban = new Sokoban;

    sokoban->menuEntryPoint();
    
    u_short userOption;
    u_short settingsOption;

    logging->writeLog("Wejscie do petli wyboru opcji");

    do 
    {
        userOption = sokoban->optionsSelection();
    } while (userOption != 49);

    logging->writeLog("Rozpoczynanie gry");

    sokoban->startGame();

    char userInput;

    static int movesMade = 0;
    static int movesLeft = LEVEL_EASY_MOVES_COUNT;
    static int redo = 0;
    static int points;

    logging->writeLog("Wejscie do petli glownej");

    do 
    {
        userInput = sokoban->mainLoop(movesLeft, movesMade, redo);
    } while (userInput != 'q');


    logging->writeLog("Wychodzenie z gry");

    delete sokoban;
    delete logging;

    return 0;
}