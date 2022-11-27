#ifndef _WRAPPERS_H
#define _WRAPPERS_H
#if defined(_WIN32)
#include <random>
#elif defined(__linux__)
typedef unsigned long size_t;
#endif


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

void PrintDebug(const char*, ...) __attribute__((deprecated));
void PrintStatus(const char*, ...) __attribute__((deprecated));
void Print(const char*, ...) __attribute__((deprecated));
void CleanWindow();

void* Malloc(size_t);
void ZeroMemory(void*, size_t);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _WRAPPERS_H */