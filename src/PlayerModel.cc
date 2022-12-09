#include "../include/PlayerModel.h"
#include "../include/__Logs.h"
#include "../include/Wrappers.h"


// Konstruktor
PlayerModel::PlayerModel()
{
    ZeroMemory(&this->_playerAppearance, sizeof(this->_playerAppearance));
}


// Destruktor
PlayerModel::~PlayerModel()
{
    ZeroMemory(&this->_playerAppearance, sizeof(this->_playerAppearance));

    logging->writeLog("Zniszczono klase PlayerModel");   
}


void PlayerModel::setPlayersAppearance(char head, char rightArm, char body, char leftArm, char legs)
{
    if (head != '0')
        this->_playerAppearance.head = head;
    else
        this->_playerAppearance.head = '0';

    if (rightArm != '|')
        this->_playerAppearance.rightArm = rightArm;
    else
        this->_playerAppearance.rightArm = '|';

    if (body != 'U')
        this->_playerAppearance.body = body;
    else
        this->_playerAppearance.body = 'U';

    if (leftArm != '|')
        this->_playerAppearance.leftArm = leftArm;
    else
        this->_playerAppearance.leftArm = '|';

    if (legs != 'M')
        this->_playerAppearance.legs = legs;
    else
        this->_playerAppearance.legs = 'M';
}


PlayerAppearance PlayerModel::getPlayersAppearance()
{
    return this->_playerAppearance;
}