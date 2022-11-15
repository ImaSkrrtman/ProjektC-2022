#include <iostream>
#include "../include/Menu.h"
#include "../include/Wrappers.h"
#include "../include/__Logs.h"


// Konstruktor
Menu::Menu()
{
    this->_selectedOption = 0;
    this->_goUP = "W - Idz w gore";
    this->_goDOWN = "S - Idz w dol";
    this->_goLEFT = "A - Idz w lewo";
    this->_goRIGHT = "D - Idz w prawo";

}


// Destruktor
Menu::~Menu()
{

}


void Menu::printBanner()
{
    std::cout << BLUE << "\t\t #####\n"                                            
         << "\t\t#     #  ####  #    #  ####  #####    ##   #    #\n" 
         << "\t\t#       #    # #   #  #    # #    #  #  #  ##   #\n" 
         << "\t\t #####  #    # ####   #    # #####  #    # # #  #\n" 
         << "\t\t      # #    # #  #   #    # #    # ###### #  # #\n" 
         << "\t\t#     # #    # #   #  #    # #    # #    # #   ##\n" 
         << "\t\t #####   ####  #    #  ####  #####  #    # #    #\n\n" << RESET << std::flush; 
}


void Menu::printMenu()
{
    std::cout << "[  " << GREEN << "CTRL+C" << RESET << " Aby wyjsc  ]\n";
    std::cout << GREEN << "1." << RESET << " " << YELLOW << "Zacznij Gre\n" << RESET;
    std::cout << GREEN << "2." << RESET << " " << YELLOW << "Wyswietl Pomoc\n" << RESET;
    std::cout << GREEN << "3." << RESET << " " << YELLOW << "Ustawienia\n" << RESET;
    std::cout << GREEN << "4." << RESET << " " << YELLOW << "Autor\n" << RESET;
    std::cout << GREEN << "5." << RESET << " " << YELLOW << "Wyczysc okno\n" << RESET;
}


void Menu::printSettings(UserSettings* userSettings)
{
    switch (userSettings->goUP) {
        case 'w':
            this->_goUP = "W - Idz w gore";
        break;
        case UP_ARROW:
            this->_goUP = "Strzalka w gore - Idz w gore";
        break;
    }

    switch (userSettings->goDOWN) {
        case 's':
            this->_goDOWN = "S - Idz w dol";
        break;
        case DOWN_ARROW:
            this->_goDOWN = "Strzalka w dol - Idz w dol";
        break;
    }

    switch (userSettings->goLEFT) {
        case 'a':
            this->_goLEFT = "A - Idz w lewo";
        break;
        case LEFT_ARROW:
            this->_goLEFT = "Strzalka w lewo - idz w lewo";
        break;
    }

    switch (userSettings->goRIGHT) {
        case 'd':
            this->_goRIGHT = "D - Idz w prawo";
        break;
        case RIGHT_ARROW:
            this->_goRIGHT = "Strzalka w prawo - idz w prawo";
        break;
    }

    std::cout << "\n" << this->_goUP << "\n";
    std::cout << this->_goDOWN << "\n";
    std::cout << this->_goLEFT << "\n";
    std::cout << this->_goRIGHT << "\n";
    std::cout << "u - Cofnij\n";
    std::cout << "r - Ponow\n\n";

    std::cout << "Czy chcesz zmienic ustawienia sterowania? 1. Tak, 2. Nie, 3. Przywroc domyslne\n";
}


void Menu::printHelp(UserSettings* userSettings)
{
    std::cout << "\nPomoc:\n";

    switch (userSettings->goUP) {
        case 'w':
            this->_goUP = "W - Idz w gore";
        break;
        case UP_ARROW:
            this->_goUP = "Strzalka w gore - Idz w gore";
        break;
    }

    switch (userSettings->goDOWN) {
        case 's':
            this->_goDOWN = "S - Idz w dol";
        break;
        case DOWN_ARROW:
            this->_goDOWN = "Strzalka w dol - Idz w dol";
        break;
    }

    switch (userSettings->goLEFT) {
        case 'a':
            this->_goLEFT = "A - Idz w lewo";
        break;
        case LEFT_ARROW:
            this->_goLEFT = "Strzalka w lewo - idz w lewo";
        break;
    }

    switch (userSettings->goRIGHT) {
        case 'd':
            this->_goRIGHT = "D - Idz w prawo";
        break;
        case RIGHT_ARROW:
            this->_goRIGHT = "Strzalka w prawo - idz w prawo";
        break;
    }

    std::cout << "\n" << this->_goUP << "\n";
    std::cout << this->_goDOWN << "\n";
    std::cout << this->_goLEFT << "\n";
    std::cout << this->_goRIGHT << "\n";
    std::cout << "u - Cofnij\n";
    std::cout << "r - Ponow\n\n";
}


void Menu::printAuthor()
{
    std::cout << "\n" << _AUTHOR << "\n\n";
}


void Menu::printInlineGameHelp()
{
    std::cout << "\n\n\n\n" << this->_goUP << ", " << this->_goDOWN << ", " << std::endl 
              << this->_goLEFT << ", " << this->_goRIGHT << ", " << std::endl 
              << "u -> Cofnij (undo), r - Ponow ruch (redo), q - Wyjdz\n\n";
}


u_short Menu::getOption(u_short userOption, UserSettings userSettings)
{
    this->_selectedOption = userOption;

    switch (this->_selectedOption) {
        case 0:
        break;
        case 1:
            this->_selectedOption = 1;

            logging.writeLog("Wybrano opcje 1");
        break;
        case 2:
            this->printHelp(&userSettings);
            this->_selectedOption = 2;

            logging.writeLog("Wybrano opcje 2");
        break;
        case 3:
            this->printSettings(&userSettings);
            this->_selectedOption = 3;

            logging.writeLog("Wybrano opcje 3");
        break;
        case 4:
            this->printAuthor();
            this->_selectedOption = 4;

            logging.writeLog("Wybrano opcje 4");
        break;
        case 5:
            this->_selectedOption = 5;

            logging.writeLog("Wybrano opcje 5");
        break;
        default:
            std::cout << RED << "Nieprawidlowa opcja" << RESET<< "\n\n";
            this->_incorrectOptions++;

            if (this->_incorrectOptions == 5) {
                CleanWindow();
                std::cout << "Opuszczanie...\n";
                std::cout << "Zbyt duzo razy zostala wybrana niepoprawna opcja lub wystapil inny blad krytyczny\n";
                __EXIT_FAILURE;
            }

            logging.writeError("Wybrano nieprawidlowa opcje", false);
        break;
    }

    return this->_selectedOption;
}