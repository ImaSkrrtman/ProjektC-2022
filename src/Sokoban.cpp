#include <stdio.h>
#include <stdlib.h>
#ifndef _WRAPPERS_INCL
#define _WRAPPERS_INCL
#include "../include/Wrappers.h"
#endif /* _WRAPPERS_INCL */
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "../include/Types.h"
#endif /* _TYPES_INCL */


#define _AUTHOR "Filip Cybulski 188891"


int main(int argc, const char* argv[])
{
    // Test czy wszystko dziala poprawnie
    c_p_char message = "hi mom";
    Print("%s\n", message);
    PrintDebug("DEBUG: %s\n", message);
    PrintStatus("STATUS: %s\n", message);

    int* x = (int*)Malloc(sizeof(int));
    free(x);

    int y[32];
    ZeroMemory(&y, sizeof(y));

    int yArrayLength = 32;

    for (auto i = 0; i < yArrayLength; i++) {
        Print("%d -> 0x%04x\n", i, y[i]);
    }

    Print("%sGREEN%s\n", GREEN, RESET);
    Print("%sRED%s\n", RED, RESET);
    Print("%sYELLOW%s\n", YELLOW, RESET);
    Print("%sBLUE%s\n", BLUE, RESET);

    return 0;
}