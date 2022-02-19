/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Aidan Walsh                                                */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   /* newline contains our string that contains our from value */
   char *newLine = Str_search(pcLine, pcFrom);
   /* use pointer to pcLine that lets us iterate through */
   const char *pointTo = pcLine; 

   /* calculate sizes of all strings for future use */
   size_t len_from = Str_getLength(pcFrom); 
   size_t len_to = Str_getLength(pcTo); 
   size_t originalLine = Str_getLength(pcLine);
   size_t len_newLine = 0; 
   
   /* values that we use to store indexes */
   size_t totalReplaces = 0; 
   size_t i; 
   assert(pcLine != NULL && pcFrom != NULL && pcTo != NULL); 

   /* if length of FROM is 0, then we just print the whole line and 
   return 0 since no replacements */
    if (Str_getLength(pcFrom) == 0) {
      printf("%s", pcLine); 
      return 0; 
   }
   else {

      /* we iterate through our newline variable which contains the 
      string containing our FROM and continually search for the string.
      If newline is null then there are no more FROM values and so we 
      may exit */
      while (newLine != NULL) {

         /* adjust len_newLine so we know how long this new string is */
         len_newLine = Str_getLength(newLine);
         
         /* this loop iterates through the string that comes before our
         FROM value. These characters are from where our pointTo is 
         pointing to, all the way up to the difference between our 
         last found string and the new searched string */
         for (i = 0; i < originalLine - len_newLine; i++) {
            printf("%c", *pointTo);
            pointTo++;  
         }

         /* this iterates and prints the FROM string because 
         we have just printed from our last used string all the way
         up to the from value */
         for (i = 0; i < len_to; i++) {
            printf("%c", pcTo[i]); 
         }

         /* now we move our pointer so that it points ahead of the FROM
         because we want the pointer to point at the next segment of 
         the string to find the next occurrence. */
         for (i = 0; i < len_from; i++) {
            pointTo++; 
         } 

         /* the length of our next og string for testing is given by the 
         size of the string we searched for and the length of FROM. 
         This is because when we found the occurrence of the FROM, it is
         still contained in len_newline */
         originalLine = len_newLine - len_from;

         /* get the next searched string ready for the next iteration! */
         newLine = Str_search(pointTo, pcFrom);

         /* we just replaced so increment */
         totalReplaces++; 
      } 

      /* we no longer have any more FROM within the line, so we 
      use the pointer to print the rest of the characters left */
      for (i = 0; i < originalLine; i++) {
         printf("%c", *pointTo); 
         pointTo++; 
      }
      return totalReplaces; 
   }
}


/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3}; 
   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {
      /* we just call the method for each line and continue 
      incrementing the count value */
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo); 
   }
   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   
   return 0;
}
