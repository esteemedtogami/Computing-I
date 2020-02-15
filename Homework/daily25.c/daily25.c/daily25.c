/*******************************************
 Author: Sam Pickell
 Date: 11/17/15
 
 Purpose: Compare two sequences from an input 
    file and print the matching characters 
    to the screen.
 
 Sources of Help: read_string and Chapter 8
 
 Time Spent: 2 Hours 20 Minutes
*******************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 21

int compare(int* i, int* j, char array2[], char array4[]);

char* read_string(char* array, int size, FILE* fp);

int main (int argc, char* argv[])
{
    FILE* fp;
    char array1[81];
    char array2[SIZE];
    char array3[81];
    char array4[SIZE];
    int i = 0, j = 1;
    char* pBuffer;
    
    fp = fopen("input.txt", "r");
    
    if (fp == NULL)
    {
        printf("The file did not open correctly.\n");
        return 1;
    }
    
    pBuffer = read_string(array1, 81, fp);
    strncpy(array2, array1, 20);
    pBuffer = read_string(array3, 81, fp);
    strncpy(array4, array3, 20);
    
    compare(&i, &j, array2, array4);
    while (j == 1)
    {
        printf("%c", array2[i]);
        i ++;
        compare(&i, &j, array2, array4);
    }
    
    fclose(fp);
    
    return 0;
}

int compare(int* i, int* j, char array2[], char array4[])
{
    if (array2[*i] != array4[*i])
    {
        printf("\n");
        *j = 0;
    }

    return *i;
}


char* read_string(char* array, int size, FILE* fp)
{
    char c;
    int number_of_conversions;
    int i = 0;
    
    if (fp == NULL)
    {
        return NULL;
    }
    
    number_of_conversions = fscanf(fp, " %c", &c);
    while (number_of_conversions == 1 && i < size - 1 && !isspace(c))
    {
        array[i] = c;
        i ++;
        number_of_conversions = fscanf(fp, "%c", &c);
    }
    
    if (number_of_conversions != EOF)
    {
        ungetc(c, fp);
    }
    
    array[i] = '\0';
    
    if (i == 0)
    {
        return NULL;
    }
    
    return array;
}
