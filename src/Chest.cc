#include <iostream>
#include "../include/Chest.h"
#include "../include/Wrappers.h"
#include "../include/__Logs.h"


// Konstruktor
Chest::Chest()
{
    ZeroMemory(&this->_chestAppearance, sizeof(this->_chestAppearance));
}

// Destruktor
Chest::~Chest()
{
    ZeroMemory(&this->_chestAppearance, sizeof(this->_chestAppearance));

    logging.writeLog("Zniszczono klase Chest"); 
}


void Chest::setChestAppearance(char left, char middle, char right)
{
    if (left != '[')
        this->_chestAppearance.left = left;

    if (middle != '#')
        this->_chestAppearance.middle = middle;

    if (right != ']')
        this->_chestAppearance.right = right;
}


void Chest::setDefaultChestAppearance()
{
    this->_chestAppearance.left = '[';
    this->_chestAppearance.middle = '#';
    this->_chestAppearance.right = ']';
}


ChestAppearance Chest::getChestAppearance()
{
    return this->_chestAppearance;
}