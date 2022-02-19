/*--------------------------------------------------------------------*/
/* strp.c                                                          */
/* Author: Aidan Walsh                                                */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

/* return size_t that is the length of the char array (string) s where 
size ends with null character. Assert no null arguments */
size_t Str_getLength(const char *s) {
    const char *end; 
    assert(s != NULL); 
    end = s; 
     /* start at beginning and iterate through, with pointer,
    until null */
    while (*end != '\0' ) {
        end++; 
    }
    /* size is difference between end pointer and beginning pointer */
    return (size_t)(end - s); 
}

/* return char array (string) that is the copy of src into dst. End 
with null character. Assert no null arguments */
char *Str_copy(char *dst, const char *src) {
    char* first = dst; 
    assert(dst != NULL && src != NULL);
    /* assuming dst is large enough, just place value of src into value of 
    pointer at dst and increment both pointers*/
    while (*src != '\0') {
        *dst = *src; 
        dst++; 
        src++; 
    }
    if (*src == '\0') {
        *dst = '\0'; 
        
    }
    /* first points to beginning so just return it */
    return first; 
}

/* return char array with source appended onto end of dst. End with
 null character. Assert no null arguments */
char *Str_concat(char *dest, const char *source) {
    const char* trackSource = source; 
    char* first = dest; 
     assert(dest != NULL && source != NULL);

     /* we just increment the pointer of dest until we reach the end
     so that we may append source */
    while (*dest != '\0') {
        dest++; 
    }
    /* once at end, we then increment pointer of tracksource which
    first points to the front of source and increment pointer of dest
    and place value of tracksource into dest until we reach the end of 
    tracksource. */
    if (*dest == '\0') {
        while (*trackSource != '\0') {
            *dest = *trackSource; 
            dest++; 
            trackSource++; 
        }
    }
    if (*trackSource == '\0') {
        *dest = '\0';
    }
    /* first points to beginning of dest, so just return it */
    return first; 
}

/* return int where int is neg if char arr st1 is numerically less 
than st2, return pos if st1 > st2, and 0 if equal. Assert no null 
arguments */
int Str_compare(const char *st1, const char *st2) {
    const char* pst1 = st1; 
    const char* pst2 = st2; 
    
    assert(st1 != NULL && st2 != NULL);
    /* increment pointers to st1 and st2 until we reach 
    the end of either */
    while (*pst1 != '\0' && *pst2 != '\0') {
        /* if value of pointer at st1 is less, then return neg */
        if (*pst1 < *pst2) {
            return -1; 
        }
        /* if greater, return pos */
        else if (*pst1 > *pst2) {
            return 1; 
        }
        pst1++; 
        pst2++; 
    }
    /* if reach end of pointer 1 but not pointer 2, then we know pointer 1
    is shorter, thus return neg */
    if (*pst1 == '\0' && *pst2 != '\0') {
        return -1;
    }

    /* in the flipped case, return pos */
    else if (*pst1 != '\0' && *pst2 == '\0') {
        return 1; 
    }
    /* all other cases result in them being equal, thus return 0 */
    return 0; 
}

/* return char array (string) that is the first occurence of needle 
in haystack. If needle is empty, return haystack. Assert no null
arguments. */
char *Str_search(const char *haystack, const char *needle) {
    /* using pointers that point into both haystack and needle. 
    Two are used for haystack because we increment one, and use the 
    other to keep track of where we find the beginning of a needle */
   const char* phaystack = haystack; 
   const char* pneedle = needle; 
   const char* location = haystack; 
   /* contained used to let us know if we are just hitting the 
   beginning of a needle and to know if we are in the middle of 
   comparison */
   int contained = 0; 
   assert(haystack != NULL && needle != NULL);
   /* increment pointer to haystack until we reach the end */
   while (*phaystack != '\0') {
       /* if pointer values to needle and haystack are equal, we may 
       have found potential needle and if we have just found the 
       beginning of a potential needle, then set pointer of location
       to this beginning point */
       if (*phaystack == *pneedle) {
           if (contained == 0) {
               location =  phaystack; 
           }
            
           contained = 1; 
           pneedle++; 
       }
       /* if we have hit the end of needle and were comparing, then 
       needle is contained and so we just return location which points
       to the beginning of the needle! */
       else if (*pneedle == '\0' && contained) {  
           
           return (char*) location; 

       }
       else {
           /* needle is no longer matching with haystack so reset 
           needle pointer and haystack pointer and contained */
           if (contained) {
               phaystack = location; 
           }
           contained = 0; 
           pneedle = needle; 
       }
       phaystack++; 
   }

   /* if needle is empty, return haystack */
   if (Str_getLength(needle) == 0) {
       return (char*) haystack; 
   }
   /* if we have reached the end of needle and it was contained
   then needle is at the end, so return where we found the start 
   of the needle */
   if (contained && *pneedle == '\0') {
       
       return (char*) location; 
   } 
   /* have not found needle so return null */
   return NULL; 
}

