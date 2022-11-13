/*
* Wrapper to funkcja ktora robi to samo
* co inna funkcja tylko ma jakas dodatkowa
* wlasnosc np. sprawdza czy zaalokowana
* pamiec jest rowna NULL albo czy cos 
* zwrocilo jeden
*
* Chyba ten plik bedzie includowany wszedzie
*
! Umieszczaj w nim funkcje, makra, zmienne globalne
! ktore beda uzywane wiecej niz raz
*/

#ifndef _WRAPPERS_H
#define _WRAPPERS_H
#include <random>

#define __EXIT_FAILURE exit(EXIT_FAILURE)
#define __EXIT_SUCCESS exit(EXIT_SUCCESS)

#define u16rand() ((unsigned short)rand())
#define u32rand() ((unsigned int)rand())

#ifndef _COLORS
#define _COLORS
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define BLUE "\x1B[34m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"
#endif /* _COLORS */

#ifdef __cplusplus
extern "C" {
#endif

/* 
* Zamiast std::cout, printf(...), fprintf(...),
* uzywaj tych funkcji
*/
void PrintDebug(const char*, ...);
void PrintStatus(const char*, ...);
void Print(const char*, ...);
void CleanWindow();

void* Malloc(size_t);
void ZeroMemory(void*, size_t);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _WRAPPERS_H */