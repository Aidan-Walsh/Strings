/*--------------------------------------------------------------------*/
/* stra.c                                                          */
/* Author: Aidan Walsh                                                */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

/* return size_t that is the length of the char array (string) s where 
size ends with null character. Assert no null arguments */
size_t Str_getLength(const char s[]) {
    size_t count = 0;
    assert(s != NULL);

    /* start at beginning and iterate through, with counter,
    until null */
    while (s[count] != '\0') {
        count++; 
    }
    return count; 
}

/* return char array (string) that is the copy of src into dst. End 
with null character. Assert no null arguments */
char *Str_copy(char dst[], const char src[]) {
    size_t count = 0;
    assert(dst != NULL && src != NULL);

    /* assuming dst is large enough, just place src at 
    index count into index count in dst since we just copy over*/
    while (src[count] != '\0') {
        dst[count] = src[count];
        count++;  
    }

    dst[count] = '\0';
    return dst; 


}

/* return char array with source appended onto end of dst. End with
 null character. Assert no null arguments */
char *Str_concat(char dest[], const char source[]) {
    /* store size of dest and source because we want to just add
    source onto end of dest where we start to iterate through dest
    right after it's last char */
    size_t size = Str_getLength(dest);
    size_t totalSize = Str_getLength(dest) + Str_getLength(source) + 1;
    size_t countS = 0; 
    assert(dest != NULL && source != NULL);

    /* start at end of dest and just iterate through beginning of 
    source, appending index of source onto incremented end of dest*/
   while (size < totalSize) {
        dest[size] = source[countS];
        size++; 
        countS++; 
    } 
    return dest; 
}

/* return int where int is neg if char arr st1 is numerically less 
than st2, return pos if st1 > st2, and 0 if equal. Assert no null 
arguments */
int Str_compare(const char st1[], const char st2[]) {
    size_t count= 0; 
    assert(st1 != NULL && st2 != NULL);

    /* iterate through both st1 and st2 at same index */
    while (st1[count] != '\0' && st2[count] != '\0') {
        /* if st1 is less at index, then return neg value, 
        else if greater, then return 1 */
        if (st1[count] < st2[count]) {
            return -1;
        }
        else if (st1[count] > st2[count]) {
            return 1; 
        }
        count++; 
    }
    /* since we have reached the end of one, we return 0 if 
    we ended up hitting a null value for both */
    if (st1[count] == '\0' && st2[count] == '\0') {
        return 0; 
    }
    /* if we only reached the end of st1, we know it is shorter,
    thus return neg value */
    if (st1[count] == '\0') {
        return -1; 
    }
    /* return 1 in all other cases since we have accounted for all cases
    of -1 and 0 */
    return 1; 
}

/* return char array (string) that is the first occurence of needle 
in haystack. If needle is empty, return haystack. Assert no null
arguments. */
char *Str_search(const char haystack[], const char needle[]) {
    size_t countH = 0; 
    size_t needleSize = Str_getLength(needle);
    size_t countN = 0; 
    /* contained is used to know whether or not we are in the middle
    of comparing needle and haystack */
    int contained = 0;
    assert(haystack != NULL && needle != NULL);
    /* we iterate through the haystack until reach end*/
        while (haystack[countH] != '\0') {
            /* if we have a matching value between haystack and needle, 
            then we increment index of countN since we need to move along
            needle, and set contained to 1 */
        if (haystack[countH] == needle[countN] && needle[countN]!= '\0')
 {
            contained = 1;
            countN++; 
        }
        /* if we reach the end of needle and we know it was matching, 
        then it is within and we must return the beginning of where we 
        found the needle. We return the address at this location  */
        else if (needle[countN] == '\0' && contained) { 
                return (char*) &haystack[countH-needleSize];  
                }
        else {
            /* all other cases, we have no match between needle char an
            haystack char, thus reset contained, set needle index to 0
            and set back countH in case we have repeating chars */
            if (contained) {
                countH = countH - countN; 
                contained = 0;
                countN = 0; 
            } 
        }
        countH++; 
    }
    /* case where needle is located at end of haystack and so return end 
    of haystack*/
if ((contained == 1 && needle[countN] == '\0')) {
       return (char *)&haystack[countH-needleSize]; 
    }
    /* case where needle is just "" and so return whole haystack*/
    else if (needleSize == 0) {
                    return (char *)haystack; 
    }
    else {
        /* all other cases are where needle is not contained so
        return null */
        return NULL; 
}
}

