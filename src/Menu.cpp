#include "../include/Menu.h"
#include "../include/Wrappers.h"


// Konstruktor
Menu::Menu()
{
    this->_selectedOption = 0;
}


// Destruktor
Menu::~Menu()
{

}


void Menu::printBanner()
{
    Print("\t\t %s#####\n"                                            
         "\t\t#     #  ####  #    #  ####  #####    ##   #    #\n" 
         "\t\t#       #    # #   #  #    # #    #  #  #  ##   #\n" 
         "\t\t #####  #    # ####   #    # #####  #    # # #  #\n" 
         "\t\t      # #    # #  #   #    # #    # ###### #  # #\n" 
         "\t\t#     # #    # #   #  #    # #    # #    # #   ##\n" 
         "\t\t #####   ####  #    #  ####  #####  #    # #    #%s\n\n", BLUE, RESET); 
}


void Menu::printMenu()
{
    Print("[  %sCTRL+C%s Aby wyjsc  ]\n", GREEN, RESET);
    Print("%s1.%s %sZacznij Gre%s\n", GREEN, RESET, YELLOW, RESET);
    Print("%s2.%s %sWyswietl Pomoc%s\n", GREEN, RESET, YELLOW, RESET);
    Print("%s3.%s %sUstawienia%s\n", GREEN, RESET, YELLOW, RESET);
    Print("%s4.%s %sAutor%s\n", GREEN, RESET, YELLOW, RESET);
    Print("%s5.%s %sWyczysc okno%s\n", GREEN, RESET, YELLOW, RESET);
}


void Menu::printSettings()
{

}


void Menu::printHelp()
{
    Print("\nPomoc:\n");
    Print("W -> Idz do gory\n");
    Print("S -> Idz w dol\n");
    Print("A -> Idz w lewo\n");
    Print("D -> Idz w prawo\n\n");
}


void Menu::printAuthor()
{
    Print("\n%s\n\n", _AUTHOR);
}


u_short Menu::getOption(u_short userOption)
{
    this->_selectedOption = userOption;

    switch (this->_selectedOption) {
        case 1:
            this->_selectedOption = 1;
        break;
        case 2:
            this->printHelp();
            this->_selectedOption = 2;
        break;
        case 3:
            this->printSettings();
            this->_selectedOption = 3;
        break;
        case 4:
            this->printAuthor();
            this->_selectedOption = 4;
        break;
        case 5:
            this->_selectedOption = 5;
        break;
        default:
            Print("%s\nNieprawidlowa opcja%s\n\n", RED, RESET);
            this->_incorrectOptions++;

            if (this->_incorrectOptions == 5) {
                CleanWindow();
                Print("Opuszczanie...\n");
                Print("Zbyt duzo razy zostala wybrana niepoprawna opcja lub wystapil inny blad krytyczny\n");
                __EXIT_FAILURE;
            }
        break;
    }

    return this->_selectedOption;
}