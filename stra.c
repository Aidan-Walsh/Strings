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
    size_t size = Str_getLength(dest) + Str_getLength(source) + 1;
    char *concat;
    concat = (char*)malloc(size);
    concat[0] = 'a';
    Str_copy(concat, dest); 
    size_t count = Str_getLength(dest); 
    size_t countS = 0; 
    assert(dest != NULL || source != NULL);
    while (count < size) {
        concat[count] = source[countS];
        count++; 
        countS++; 
    }
    concat[size] = '\0';
    return concat; 
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
   assert(haystack != NULL || needle != NULL);
    size_t countH = 0; 
    size_t needleSize = Str_getLength(needle);
    size_t totalSize= needleSize + 1 + Str_getLength(haystack); 
    size_t countN = 0; 
    int contained = 0;
    int fullyContained = 0; 
    int i; 
    char *returned;
    returned = (char*)malloc(totalSize);
        while (haystack[countH] != '\0') {
        if (haystack[countH] == needle[countN] && needle[countN] != '\0') {
            contained = 1;
            countN++; 
        }
        else if (needle[countN] == '\0' && contained) {
            /* place needle into returned array */
                    for (i = 0; i < needleSize; i++) {
                        returned[i] = needle[i]; 
                    }
                    returned[countN] =  haystack[countH];
                    countN++;
                    fullyContained = 1; 
                    contained = 0; 
                }
        else if (fullyContained) {
            returned[countN] =  haystack[countH];
            countN++; 
        }
        else {
            if (contained) {
                contained = 0;
                countN = 0; 
            } 

        }
        countH++; 
    }
    if (fullyContained ) {
        returned[countN] = '\0';
        return returned;
    }
    else if ((contained == 1 && needle[countN] == '\0')) {
       return Str_copy(returned, needle);
    }
    else {
        return NULL; 
}
}
/* instead make it so that go through to see if within, and if it is, then put the string in, and everything after */

