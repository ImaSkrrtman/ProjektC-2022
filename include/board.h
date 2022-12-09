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
public:
    Board(const Board&) = delete;
    Board& operator =(const Board&) = delete;

    Board(); // Konstruktor
    ~Board(); // Destruktor

    void renderBoard();
    void putAplayerOnTheBoard(char (*)[ROWS][COLUMNS], u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int);
    void putChestsOnTheBoard(char (*)[ROWS][COLUMNS]);
    void printBoard();
    
    int changePlayersPosition(char, bool);
    
    void Clean();

private:
    char _charBoard[ROWS][COLUMNS];
    char _board[ROWS][COLUMNS];

    u_int _pointsX[8];
    u_int _pointsY[8];
    u_int _chestX[8];
    u_int _chestY[8];

    Chest _chest;
    PlayerModel _playerModel;
    PlayerAppearance _playerAppearance;
    ChestAppearance _chestAppearance;

    DefaultPlayersPositionOnTheBoard _defaultPlayersPositionOnTheBoard;
    CurrentPlayersPositionOnTheBoard _currentPlayersPositionOnTheBoard;
    PreviousPlayersPositionOnTheBoard _previousPlayersPositionOnTheBoard;
};

#endif /* _BOARD_H */