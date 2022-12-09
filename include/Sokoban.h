#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "Menu.h"
#include "Movement.h"
#include "Board.h"
#include "PlayerModel.h"
#include "__Logs.h"
#include "Wrappers.h"
#include "Types.h"

#if defined(__linux__)
#include <termios.h>

static char getch();
#endif

class Sokoban
{
public:
    Sokoban(const Sokoban&) = delete;
    Sokoban& operator =(const Sokoban&) = delete;

    Sokoban();
    ~Sokoban();

    void menuEntryPoint();
    void startGame();
    
    char mainLoop(int&, int&, int&);
    
    u_short optionsSelection();

private:
    Menu* _menu;
    Movement* _movement;
    Board* _board;

    u_short _userOption;
    u_short _settingsOption;

    bool _settingsChanged;

    char _userInput;
};

#endif /* _SOKOBAN_H */