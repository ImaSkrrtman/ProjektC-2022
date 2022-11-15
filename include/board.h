#ifndef _BOARD_H
#define _BOARD_H
#ifndef _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */

#define ROWS 25
#define COLUMNS 80

class Board
{
private:
    char _charBoard[ROWS][COLUMNS];
    u_short* _positionX;
    u_short* _positionY;

public:
    Board(); // Konstruktor
    ~Board(); // Destruktor

    void renderBoard();

    void pushPoint(struct WhereIsPointOnTheBoard**, u_short, u_short);
    void printPointsList(struct WhereIsPointOnTheBoard*);
};

#endif /* _BOARD_H */