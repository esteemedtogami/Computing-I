/*
 Programmer: Sam Pickell
 Date: 9/12/15
 Filename: daily4.c
 Purpose: Print an integer, character, and floating point number using special characters.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("%d is an integer and can be printed using %%d.\n\n", 42);
    printf("The character '%c' can be printed by using %%c.\n\n", 'J');
    printf("Floating point numbers use %%f. %f is an example.\n\n", 3.14159);
    return 0;
    
}
 
