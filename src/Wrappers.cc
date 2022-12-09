#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset()
#ifdef _WIN32
#include <cstdarg>
#else
#include <stdarg.h>
#endif
#include "../include/Wrappers.h"
#include "../include/__Logs.h"


// Przestarzale
void PrintDebug(const char* format, ...)
{
    va_list arg;
    va_start(arg, format);

    vfprintf(stdout, format, arg);
    fflush(stdout);

    va_end(arg);
}


// Przestarzale
void PrintStatus(const char* format, ...)
{
    va_list arg;
    va_start(arg, format);

    vfprintf(stdout, format, arg);
    fflush(stdout);

    va_end(arg);  
}


// Przestarzale
void Print(const char* format, ...)
{
    va_list arg;
    va_start(arg, format);

    vfprintf(stdout, format, arg);
    fflush(stdout);

    va_end(arg);
}


void CleanWindow()
{

#ifdef _WIN32
    system("cls");

    // Ekwiwalent do system("cls");
    // std::cout << "\x1B[2J\x1B[H";
#else
    system("clear");
#endif
}


void* Malloc(size_t size)
{
    void* ptr;

    if ((ptr = malloc(size)) == NULL) {
        fprintf(stderr, "Nie zaalokowano pamieci w %s -> %d [ \x1B[31mBLAD\x1B[0m ]\n", __FILE__, __LINE__);
        logging->writeError("Malloc() -> blad podczas allokacji pamieci", true);
        fflush(stderr);
        __EXIT_FAILURE;
    }

    logging->writeLog("Pamiec zostala zaalokowana");

    return ptr;
}


void ZeroMemory(void *src, size_t size)
{
    void* ptr;

    if ((ptr = memset(src, 0, size)) == NULL) {
        fprintf(stderr, "Nie mozna wyczyscic zadanego obszaru pamieci %s -> %d [ \x1B[31mBLAD\x1B[0m ]\n", __FILE__, __LINE__);
        logging->writeError("ZeroMemory() -> blad podczas wypelniania bloku pamieci zerami 0x00", true);
        fflush(stderr);
        __EXIT_FAILURE;
    }

    logging->writeLog("Blok pamieci zostal wypelniony zerami");
}