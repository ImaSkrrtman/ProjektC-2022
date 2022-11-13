#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset()
#include <cstdarg>
#include "../include/Wrappers.h"


// Uzywaj jej do wypisywania informacji do debugowania
void PrintDebug(const char* format, ...)
{
    va_list arg;
    va_start(arg, format);

    vfprintf(stdout, format, arg);
    fflush(stdout);

    va_end(arg);
}


// Uzywaj jej do wypisywania informacji roznych, zamiast std::cout itd...
void PrintStatus(const char* format, ...)
{
    va_list arg;
    va_start(arg, format);

    vfprintf(stdout, format, arg);
    fflush(stdout);

    va_end(arg);  
}


// To samo co PrintStatus() tyle ze chyba lepsze
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
    Print("\x1B[2J\x1B[H");
}


// Dynamiczna allokacja pamieci
void* Malloc(size_t size)
{
    void* ptr;

    if ((ptr = malloc(size)) == NULL) {
        fprintf(stderr, "Unable to allocate memory in %s -> %d [ \x1B[31mFAILED\x1B[0m ]\n", __FILE__, __LINE__);
        fflush(stderr);
        __EXIT_FAILURE;
    }

    return ptr;
}


// Wypelnianie bloku pamieci zerami np. int x[32] -> w pamieci = 0x1234 po uzyciu ZeroMemory(&x, sizeof(x)) -> 0x00000 w pamieci
void ZeroMemory(void *src, size_t size)
{
    void* ptr;

    if ((ptr = memset(src, 0, size)) == NULL) {
        fprintf(stderr, "Unable to set zero memory in %s -> %d [ \x1B[31mFAILED\x1B[0m ]\n", __FILE__, __LINE__);
        fflush(stderr);
        __EXIT_FAILURE;
    }
}