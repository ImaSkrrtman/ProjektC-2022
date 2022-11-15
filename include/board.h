#ifndef _BOARD_H
#define _BOARD_H
#ifndef _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */
#include "Chest.h"
#include "PlayerModel.h"

#define ROWS 25
#define COLUMNS 80

class Board
{
private:
    char _charBoard[ROWS][COLUMNS];
    char _board[ROWS][COLUMNS];
    u_short* _positionX;
    u_short* _positionY;

    Chest _chest;
    PlayerModel _playerModel;

public:
    Board(); // Konstruktor
    ~Board(); // Destruktor

    void renderBoard();
    void printBoard();
};

#endif /* _BOARD_H */