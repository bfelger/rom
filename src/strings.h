///////////////////////////////////////////////////////////////////////////////
// strings.h
// 
// Helper functions for string handling.
///////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef ROM__STRINGS_H
#define ROM__STRINGS_H

#include <ctype.h>

// All strings in ROM are 7-bit POSIX Locale, with the sign bit reserved for 
// special telnet characters. These macros keep 'ctype.h' functions copacetic
// with char* strings under -Wall.

#ifdef __CYGWIN__
    #define ISALPHA(c) isalpha((unsigned char)c)
    #define ISDIGIT(c) isdigit((unsigned char)c)
    #define ISPRINT(c) isprint((unsigned char)c)
    #define ISSPACE(c) isspace((unsigned char)c)
    #define ISUPPER(c) isupper((unsigned char)c)
#else
    #define ISALPHA(c) isalpha(c)
    #define ISDIGIT(c) isdigit(c)
    #define ISPRINT(c) isprint(c)
    #define ISSPACE(c) isspace(c)
    #define ISUPPER(c) isupper(c)
#endif

// isascii() is marked OB by POSIX, but we still need to test for telnet-
// friendly characters.
#define ISASCII(c) ((unsigned char)(c) & ~0x7F)

#endif // !ROM__STRINGS_H
