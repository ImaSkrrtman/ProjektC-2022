#ifndef _PLAYERMODEL_H
#define _PLAYERMODEL_H
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */

/*
*               | y
*               |
*               |
*               |     * <--- gracz
*               |
*--------------------------------> x
*               |
*               |
*               |
*               |
*
*
* Zalozmy ze gracz ma wspolrzedne (5, 4) to wtedy odpowiednio
* bedzie trzeba zmieniac polozenie w strukture whereIsX = 5, whereIsY = 4
* np.
* Do struktury chcemy miec pelen dostep a nie kopie to chyba
* uzyjemy wskaznika do niej
*
* Traktujemy plansze jako uklad wspolrzednych
*/

typedef struct
{
    u_int whereIsX;
    u_int whereIsY;
    u_short movesLeft;
} PlayersPositionOnTheBoard;

class PlayerModel
{
private:
public:
    PlayerModel(); // Konstruktor
    ~PlayerModel(); // Destruktor
};

#endif /* _PLAYERMODEL_H */