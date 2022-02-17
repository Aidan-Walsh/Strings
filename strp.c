/*--------------------------------------------------------------------*/
/* strp.c                                                          */
/* Author: Aidan Walsh                                                */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

size_t Str_getLength(const char *s) {
    const char *end; 
    assert(s != NULL); 
    end = s; 
    while (*end != '\0' ) {
        end++; 
    }
    return (size_t)(end - s); 
}

char *Str_copy(char *dst, const char *src) {
    char* first = dst; 
    assert(dst != NULL || src != NULL);
    while (*src != '\0') {
        *dst = *src; 
        dst++; 
        src++; 
    }
    if (*src == '\0') {
        *dst = '\0'; 
        
    }
    return first; 
}

char *Str_concat(char *dest, const char *source) {
    const char* trackSource = source; 
    char* first = dest; 
     assert(dest != NULL || source != NULL);
    while (*dest != '\0') {
        dest++; 
    }
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
    return first; 
}

int Str_compare(const char *st1, const char *st2) {
    const char* pst1 = st1; 
    const char* pst2 = st2; 
    
    assert(st1 != NULL || st2 != NULL);
    while (*pst1 != '\0' && *pst2 != '\0') {
        if (*pst1 < *pst2) {
            return -1; 
        }
        else if (*pst1 > *pst2) {
            return 1; 
        }
        pst1++; 
        pst2++; 
    }
    if (*pst1 == '\0' && *pst2 != '\0') {
        return -1;
    }
    else if (*pst1 != '\0' && *pst2 == '\0') {
        return 1; 
    }
    return 0; 
}

char *Str_search(const char *haystack, const char *needle) {
   const char* phaystack = haystack; 
   const char* pneedle = needle; 
   const char* location = haystack; 
   int contained = 0; 
   assert(haystack != NULL || needle != NULL);
   while (*phaystack != '\0') {
       if (*phaystack == *pneedle) {
           if (contained == 0) {
               location =  phaystack; 
           }
            
           contained = 1; 
           pneedle++; 
       }
       else if (*pneedle == '\0' && contained) {  
           
           return (char*) location; 

       }
       else {
           if (contained) {
               phaystack = location; 
           }
           contained = 0; 
           pneedle = needle; 
       }
       phaystack++; 
   }
   if (Str_getLength(needle) == 0) {
       return (char*) haystack; 
   }
   if (contained && *pneedle == '\0') {
       
       return (char*) location; 
   } 
   return NULL; 
}

