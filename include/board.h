#ifndef _BOARD_H
#define _BOARD_H
#ifndef _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */
#include "Chest.h"
#include "PlayerModel.h"
#include <list>

#define ROWS 25
#define COLUMNS 80

typedef struct
{
    int headX;
    int headY;

    int leftArmX;
    int leftArmY;

    int bodyX;
    int bodyY;

    int rightArmX;
    int rightArmY;

    int legsX;
    int legsY;
} CurrentPlayersPositionOnTheBoard;

typedef struct
{
    int headX;
    int headY;

    int leftArmX;
    int leftArmY;

    int bodyX;
    int bodyY;

    int rightArmX;
    int rightArmY;

    int legsX;
    int legsY;
} PreviousPlayersPositionOnTheBoard;

typedef struct
{
    int headX;
    int headY;

    int leftArmX;
    int leftArmY;

    int bodyX;
    int bodyY;

    int rightArmX;
    int rightArmY;

    int legsX;
    int legsY;
} DefaultPlayersPositionOnTheBoard;


class Board
{
private:
    char _charBoard[ROWS][COLUMNS];
    char _board[ROWS][COLUMNS];
    u_short* _pointsX;
    u_short* _pointsY;
    u_int _totalPoints;

    std::list<u_short> _points;

    Chest _chest;
    PlayerModel _playerModel;
    ChestAppearance _chestAppearance;

    DefaultPlayersPositionOnTheBoard _defaulltPlayersPositionOnTheBoard;

public:
    Board(); // Konstruktor
    ~Board(); // Destruktor

    void renderBoard();
    void putAplayerOnTheBoard(char (*)[ROWS][COLUMNS], u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int);
    void printBoard();
    void Clean();

    u_int getTotalPoints();
};

#endif /* _BOARD_H */