#include "../include/Movement.h"
#include "../include/__Logs.h"


// Konstruktor
Movement::Movement()
{
    this->reset();
}


// Destruktor
Movement::~Movement()
{
    this->reset();

    logging.writeLog("Zniszczono klase Movement");
}


void Movement::reset()
{
    this->userSettings.goUP = this->_movementKeys.up = 'w';
    this->userSettings.goDOWN = this->_movementKeys.down = 's';
    this->userSettings.goLEFT = this->_movementKeys.left = 'a';
    this->userSettings.goRIGHT = this->_movementKeys.right = 'd';
    this->userSettings.redo = this->_movementKeys.redo = 'r';
    this->userSettings.undo = this->_movementKeys.undo = 'u';
}


char Movement::getMovementSettingsUP()
{
    return this->_movementKeys.up;
}


char Movement::getMovementSettingsDOWN()
{
    return this->_movementKeys.down;
}


char Movement::getMovementSettingsLEFT()
{
    return this->_movementKeys.left;
}


char Movement::getMovementSettingsRIGHT()
{
    return this->_movementKeys.right;
}


void Movement::changeMovementToArrows()
{
    this->userSettings.goUP = this->_movementKeys.up = UP_ARROW;
    this->userSettings.goDOWN = this->_movementKeys.down = DOWN_ARROW;
    this->userSettings.goLEFT = this->_movementKeys.left = LEFT_ARROW;
    this->userSettings.goRIGHT = this->_movementKeys.right = RIGHT_ARROW;
}