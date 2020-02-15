/*****************************************
 Author: Sam Pickell
 Date: 11/8/15
 Resubmit Date: 11/15/15
 
 Reason for resubmit: Didn't terminate
    my string with a null terminator
    in the last version.
 
 Purpose: Store user input in an array
    and then call a function to convert
    all lower case characters to upper 
    case
 
 Sources of Help: An email from Dr. Adams

 Time Spent: 4 Hours and 30 Minutes
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 81

char* convert_string(char array[], int size);

int main (int argc, char* argv[])
{
    char array[SIZE];
    char* pBuffer;
    
    printf("Please enter characters: ");
    printf("%s", fgets(array, SIZE - 1, stdin));
    pBuffer = convert_string(array, SIZE - 1);
    printf("%s", pBuffer);
    return 0;
}

char* convert_string(char array[], int size)
{
    char c;
    int i = 0;
    
    while (i < size)
    {
        c = toupper(array[i]);
        array[i] = c;
        i ++;
    }
    
    return array;
}
