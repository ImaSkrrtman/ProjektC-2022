#ifndef _TYPES_H
#define _TYPES_H
#include <string> // std::string

// Moze sie kiedys przydadza zamiast wpisywac unsigned ..., to wystarczy wpisac u_int itd...

typedef unsigned int u_int;
typedef unsigned short u_short;
typedef unsigned char u_char;
typedef unsigned char byte;
typedef std::string String; // Ja bym go nie uzywal lepiej uzywac, const char* albo c_p_char jak na dole
typedef char* p_char;
typedef const char* c_p_char;

#endif /* _TYPES_H */