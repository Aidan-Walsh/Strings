/*--------------------------------------------------------------------*/
/* stra.c                                                          */
/* Author: Aidan Walsh                                                */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

size_t Str_getLength(const char s[]) {
    size_t count = 0;
    assert(s != NULL);
    while (s[count] != '\0') {
        count++; 
    }
    return count; 
}

char *Str_copy(char dst[], const char src[]) {
    size_t count = 0;
    assert(dst != NULL || src != NULL);
    while (src[count] != '\0') {
        dst[count] = src[count];
        count++;  
    }
    dst[count] = '\0';
    return dst; 


}

char *Str_concat(char dest[], const char source[]) {
    size_t size = Str_getLength(dest);
    size_t totalSize = Str_getLength(dest) + Str_getLength(source) + 1;
    /*  char *concat  concat = (char*)malloc(size); */
    size_t countS = 0; 
    assert(dest != NULL || source != NULL);
    /* Str_copy(concat, dest);*/ 
   while (size < totalSize) {
        dest[size] = source[countS];
        size++; 
        countS++; 
    } 
    return dest; 
}

int Str_compare(const char st1[], const char st2[]) {
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

char *Str_search(const char haystack[], const char needle[]) {
    size_t countH = 0; 
    size_t needleSize = Str_getLength(needle);
    size_t countN = 0; 
    int contained = 0;
    assert(haystack != NULL || needle != NULL);
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

