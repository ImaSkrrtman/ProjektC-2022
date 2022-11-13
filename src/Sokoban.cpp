#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#ifndef _WRAPPERS_INCL
#define _WRAPPERS_INCL
#include "../include/Wrappers.h"
#endif /* _WRAPPERS_INCL */
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "../include/Types.h"
#endif /* _TYPES_INCL */
#include "../include/Menu.h"


static volatile int abortSignal = 0;
static void abortHandler(int __abortSignal)
{
    abortSignal = 1;
}


static inline void handleQuitSignals()
{
    signal(SIGINT, abortHandler);
    signal(SIGTERM, abortHandler);
}


int main(int argc, const char* argv[])
{
    Menu menu;
    
    menu.printBanner();
    menu.printMenu();
    
    u_short userOption;

    do {
        Print("Wybierz opcje: ");
        handleQuitSignals();
  
        if (abortSignal == 1) {
            CleanWindow();
            Print("Opuszczanie...\n");
            __EXIT_SUCCESS;
        }

        fscanf_s(stdin, "%1d", &userOption);

        if (userOption == 5) {
            CleanWindow();            

            menu.printBanner();
            menu.printMenu();
        }

        menu.getOption(userOption);
    } while (userOption != 1);

    return 0;
}