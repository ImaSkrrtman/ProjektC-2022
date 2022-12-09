#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "menu.h"
#include "Movement.h"
#include "board.h"
#include "PlayerModel.h"
#include "__Logs.h"
#include "Wrappers.h"
#include "Types.h"

#if defined(__linux__)
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