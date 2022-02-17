/*--------------------------------------------------------------------*/
/* str.h                                                          */
/* Author: Aidan Walsh                                               */
/*--------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>
size_t Str_getLength(const char *s);
char *Str_copy(char *dst, const char *src);
char *Str_concat(char *dest, const char *source);
int Str_compare(const char *st1, const char *st2); 
char *Str_search(const char *haystack, const char *needle); 
#endif