/*--------------------------------------------------------------------*/
/* str.h                                                          */
/* Author: Aidan Walsh                                               */
/*--------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>
/* return size_t that is the length of the char array (string) s where 
size ends with null character. Assert no null arguments */
size_t Str_getLength(const char *s);
/* return char array (string) that is the copy of src into dst. End 
with null character. Assert no null arguments */
char *Str_copy(char *dst, const char *src);
/* return char array with source appended onto end of dst. End with
 null character. Assert no null arguments */
char *Str_concat(char *dest, const char *source);
/* return int where int is neg if char arr st1 is numerically less 
than st2, return pos if st1 > st2, and 0 if equal. Assert no null 
arguments */
int Str_compare(const char *st1, const char *st2); 
/* return char array (string) that is the first occurence of needle 
in haystack. If needle is empty, return haystack. Assert no null
arguments. */
char *Str_search(const char *haystack, const char *needle); 
#endif