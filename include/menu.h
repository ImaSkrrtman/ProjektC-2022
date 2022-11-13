#ifndef _MENU_H
#define _MENU_H
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */

#define _AUTHOR "Filip Cybulski 188891"

/*
*
*        #####                                            
*       #     #  ####  #    #  ####  #####    ##   #    # 
*       #       #    # #   #  #    # #    #  #  #  ##   # 
*        #####  #    # ####   #    # #####  #    # # #  # 
*             # #    # #  #   #    # #    # ###### #  # # 
*       #     # #    # #   #  #    # #    # #    # #   ## 
*        #####   ####  #    #  ####  #####  #    # #    # 
*
* 1. Zacznij Gre
* 2. Wyswietl Pomoc
* 3. Ustawienia
* 4. Autor
*/

class Menu
{
private:
    u_short _selectedOption;
    u_short _incorrectOptions;

public:
    Menu(); // Konstruktor
    ~Menu(); // Destruktor
    
    void printBanner();
    void printMenu();
    void printSettings();
    void printHelp();
    void printAuthor();
    
    u_short getOption(u_short);
};

#endif /* _MENU_H */