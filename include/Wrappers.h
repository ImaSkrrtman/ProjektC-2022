/*
* Wrapper to funkcja ktora robi to samo
* co inna funkcja tylko ma jakas dodatkowa
* wlasnosc np. sprawdza czy zaalokowana
* pamiec jest rowna NULL albo czy cos 
* zwrocilo jeden
*/

#ifndef _WRAPPERS_H
#define _WRAPPERS_H

#define __EXIT_FAILURE exit(EXIT_FAILURE)
#define __EXIT_SUCCESS exit(EXIT_SUCCESS)

#ifdef __cplusplus
extern "C" {
#endif

/* 
* Zamiast std::cout, printf(...), fprintf(...),
* uzywaj tych funkcji
*/
void PrintDebug(const char*, ...);
void PrintStatus(const char*, ...);

void* Malloc(size_t);
void ZeroMemory(void*, size_t);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _WRAPPERS_H */