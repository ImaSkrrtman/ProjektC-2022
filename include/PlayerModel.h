#ifndef _PLAYERMODEL_H
#define _PLAYERMODEL_H
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */

#define LEVEL_EASY_MOVES_COUNT 1000
#define LEVEL_MEDIUM_MOVES_COUNT 500
#define LEVEL_HARD_MOVES_COUNT 150

typedef struct
{
    char head;
    char rightArm;
    char body;
    char leftArm;
    char legs;
} PlayerAppearance;

class PlayerModel
{
public:
    PlayerModel(); // Konstruktor
    ~PlayerModel(); // Destruktor

    void setPlayersAppearance(char, char, char, char, char);

    PlayerAppearance getPlayersAppearance();

private:
    PlayerAppearance _playerAppearance;
};

#endif /* _PLAYERMODEL_H */