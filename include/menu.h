#ifndef _MENU_H
#define _MENU_H
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */
#ifndef _MOVEMENT_INCL
#define _MOVEMENT_INCL
#include "Movement.h"
#endif /* _MOVEMENT_INCL */

#define _AUTHOR "Filip Cybulski 188891"

class Menu
{
private:
    u_short _selectedOption;
    u_short _incorrectOptions;

    const char* _goUP;
    const char* _goDOWN;
    const char* _goLEFT;
    const char* _goRIGHT;

public:
    Menu(); // Konstruktor
    ~Menu(); // Destruktor
    
    void printBanner();
    void printMenu();

    //? Dodac mozliwosc zmiany wygladu skrzynek i avatara
    void printSettings(UserSettings*);
    void printHelp(UserSettings*);
    void printAuthor();
    void printInlineGameHelp(u_int, u_int, u_int);
    
    u_short getOption(u_short, UserSettings);
};

#endif /* _MENU_H */