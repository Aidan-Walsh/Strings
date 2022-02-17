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
    size_t count= 0; 
    assert(st1 != NULL || st2 != NULL);
    while (st1[count] != '\0' && st2[count] != '\0') {
        if (st1[count] < st2[count]) {
            return -1;
        }
        else if (st1[count] > st2[count]) {
            return 1; 
        }
        count++; 
    }
    if (st1[count] == '\0' && st2[count] == '\0') {
        return 0; 
    }
    if (st1[count] == '\0') {
        return -1; 
    }
    return 1; 
}

char *Str_search(const char *haystack, const char *needle) {
   assert(haystack != NULL || needle != NULL);
    size_t countH = 0; 
    size_t needleSize = Str_getLength(needle);
    size_t countN = 0; 
    int contained = 0;
        while (haystack[countH] != '\0') {
        if (haystack[countH] == needle[countN] && needle[countN]!= '\0')
 {
            contained = 1;
            countN++; 
        }
        else if (needle[countN] == '\0' && contained) { 
                return (char*) &haystack[countH-needleSize];  
                }
        else {
            if (contained) {
                countH = countH - countN; 
                contained = 0;
                countN = 0; 
            } 
        }
        countH++; 
    }
    /* case where needle is located at end of haystack */
if ((contained == 1 && needle[countN] == '\0')) {
       return (char *)&haystack[countH-needleSize]; 
    }
    /* case where needle is just "" */
    else if (needleSize == 0) {
                    return (char *)haystack; 
    }
    else {
        return NULL; 
}
}

