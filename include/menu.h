#ifndef _MENU_H
#define _MENU_H

/*
* Chyba nic prywatnego w menu nie bedzie, tylko funkcje wypisujace jak
* uzywac program, sterowanie itd., 
? moze jakis baner?
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
public:
    Menu(); // Konstruktor
    void printBanner();
    void printOptions();
    void printHelp();
    void printAuthor();
    ~Menu(); // Destruktor
};

#endif /* _MENU_H */