/****************************************************
 Author: Sam Pickell
 Date: 10/28/15

 Purpose: Add to, modify, and print the contents of 
    an array with a for loop going up and down;
 Sources of Help: None this time
 Time Spent: 24 minutes
****************************************************/

#include <stdio.h>

#define SIZE 20

int main(int argc, char* argv[])
{
    int numbers[SIZE];
    int i, count = 0;
    
    for (i = 0; i < SIZE; i++)
    {
        numbers[i] = i * 2;
        printf("%7d", numbers[i]);
        count ++;
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
    
    printf("*****\n");
    count = 0;
    
    for (i = SIZE - 1; i >= 0; i--)
    {
        numbers[i] = i * 2;
        printf("%7d", numbers[i]);
        count ++;
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
    
    return 0;
}