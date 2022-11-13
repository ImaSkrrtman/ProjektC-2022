#include <stdio.h>
#include <stdlib.h>


#define _AUTHOR "Filip Cybulski 188891"


int main(int argc, const char* argv[])
{
    fprintf(stdout, "%s\n", _AUTHOR);
    fflush(stdout);

    return 0;
}
