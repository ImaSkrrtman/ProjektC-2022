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
    u_int _totalPoints;

    std::list<u_short> _points;
    std::list<u_short> _pointsX;
    std::list<u_short> _pointsY;

    Chest _chest;
    PlayerModel _playerModel;
    PlayerAppearance _playerAppearance;
    ChestAppearance _chestAppearance;

    DefaultPlayersPositionOnTheBoard _defaultPlayersPositionOnTheBoard;
    CurrentPlayersPositionOnTheBoard _currentPlayersPositionOnTheBoard;
    PreviousPlayersPositionOnTheBoard _previousPlayersPositionOnTheBoard;

public:
    Board(); // Konstruktor
    ~Board(); // Destruktor

    void renderBoard();
    void putAplayerOnTheBoard(char (*)[ROWS][COLUMNS], u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int, u_int);
    void printBoard();
    void changePlayersPosition(char, bool);
    void Clean();

    u_int getTotalPoints();
};

#endif /* _BOARD_H */