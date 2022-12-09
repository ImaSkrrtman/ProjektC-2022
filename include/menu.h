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

#define _AUTHOR "\x1B[32mFilip Cybulski\x1B[0m \x1B[33m188891\x1B[0m"

class Menu 
{
public:
    Menu(const Menu&) = delete;
    Menu& operator =(const Menu&) = delete;

    Menu(); // Konstruktor
    ~Menu(); // Destruktor
    
    void printBanner();
    void printMenu();

    void printSettings(UserSettings*);
    void printHelp(UserSettings*);
    void printAuthor();
    void printInlineGameHelp(u_int, u_int, u_int);
    
    u_short getOption(u_short, UserSettings);

private:
    u_short _selectedOption;
    u_short _incorrectOptions;

    const char* _goUP;
    const char* _goDOWN;
    const char* _goLEFT;
    const char* _goRIGHT;
};

#endif /* _MENU_H */