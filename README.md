# Strings

This contains interfaces and implementations of string methods (a pointer version and array version). This also contains a c file 
"replace.c" that takes two strings from the command line where the program swaps every occurrence of the first string argument with the second string argument. The text that is to be read and changed is read from stdin, the text with the replaced strings is sent to stdout, and the number of replacements is sent to stderr. 

# To use

1. Download all of the .h files and .c files except for "teststr.c".
2. You have a choice to use either "stra.c" (uses arrays) or "strp.c" (uses pointers) so they are interchangeable. To compile:
    - "gcc replace.c stra.c -o replace"
3. Run the executable with the text file "text.txt" where every occurrence of "hi" is to be replaced with "hello", and this change is to be saved in a new text file "new.txt" and the number of occurrences is saved to "number.txt":
    - "./replace hi hello < text.txt > new.txt 2> number.txt"
    - If you do not wish to save the number of occurrences, you can just remove the "2> number.txt"
    - Note that if you are running Linux, then you may have to add "sudo" to the beginning of the command to gain super-user privileges.


