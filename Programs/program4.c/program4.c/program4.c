/***********************************************
 Author: Sam Pickell
 Date: 11/12/15
 
 Purpose: Read string data from quiz.txt,
    rewrite it to average.txt with a reorder
    of names, and a calculated average. Then
    copy the data from average.txt to quiz.txt
 
 Sources of Help: read_string.c, posted in Dr. 
    Adam's handout section on Blackboard
 
 Time Spent: 8 hours, 15 minutes
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Precondition: Two arrays, size, file pointer,
//  and indication of first or last name
//  must all be initialized
//Postcondition: The data from input is displayed
//  in output
char* read_string(char* fname, char* lname, int size, FILE* fp, int name_type);

//Precondition: An array, size, and file pointer
//  must all be initialized
//Postcondition: The grades from input are stored
//  in output
int* get_ints(char* buffer, int size, FILE* fp, double* average, FILE* fp3);

char* read_string2(char* buffer, int size, FILE* fp);

#define SIZE 20

int main(int argc, char* argv[])
{
    FILE* fp;
    FILE* fp3;
    char fname[SIZE];
    char lname[SIZE];
    char array[SIZE];
    char* pBuffer;
    int* pInts;
    int name_type = 2, count = 0;
    double average;
    
    fp = fopen("quiz.txt", "r");
    fp3 = fopen("average.txt", "w");
    
    //Check to see if the files open
    if(fp == NULL)
    {
        printf("Unable to open quiz.txt\n");
        exit(1);
    }
    
    if(fp3 == NULL)
    {
        printf("Unable to open average.txt\n");
        exit(1);
    }
    
    //Set up the header
    fprintf(fp3, "Name");
    fprintf(fp3, "%30s", "Scores");
    fprintf(fp3, "%40s\n", "Average");
    
    //Read in the names
    pBuffer = read_string(fname, lname, SIZE, fp, name_type);
    while(pBuffer != NULL)
    {
        if (name_type == 2)
        {
            name_type ++;
        }
        else if (name_type == 3)
        {
            name_type --;
            if (isalpha(fname[0]))
            {
                fprintf(fp3, "%s, %s", lname, fname);
                pInts = get_ints(pBuffer, 11, fp, &average, fp3);
                fprintf(fp3, "%10.2f\n", average / 10.0);
                average = 0;
            }
        }
        pBuffer = read_string(fname, lname, SIZE, fp, name_type);
    }
    fclose(fp);
    fclose(fp3);
    
    fp = fopen("average.txt", "r");
    fp3 = fopen("quiz.txt", "w");
    
    //Check to see if the files open
    if(fp == NULL)
    {
        printf("Unable to open average.txt\n");
        exit(1);
    }
    
    if(fp3 == NULL)
    {
        printf("Unable to open quiz.txt\n");
        exit(1);
    }
    
    //Set up the header
    fprintf(fp3, "Name");
    fprintf(fp3, "%30s", "Scores");
    fprintf(fp3, "%18s\n", "Average");
    
    fclose(fp);
    fclose(fp3);
    
    fp = fopen("average.txt", "r");
    fp3 = fopen("quiz.txt", "a");
    
    //Check to see if the files open
    if(fp == NULL)
    {
        printf("Unable to open average.txt\n");
        exit(1);
    }
    
    if(fp3 == NULL)
    {
        printf("Unable to open quiz.txt\n");
        exit(1);
    }
    
    //Already have header, eat up
    pBuffer = read_string2(array, SIZE, fp);
    pBuffer = read_string2(array, SIZE, fp);
    pBuffer = read_string2(array, SIZE, fp);
    
    //Read from average.txt and copy to quiz.txt
    pBuffer = read_string2(array, SIZE, fp);
    while(pBuffer != NULL)
    {
        fprintf(fp3, "%s ", array);
        count ++;
        if (count == 13)
        {
            fprintf(fp3, "\n");
            count = 0;
        }
        pBuffer = read_string2(array, SIZE, fp);
    }
    
    
    
    fclose(fp);
    fclose(fp3);
    
    return 0;
}

char* read_string(char* fname, char* lname, int size, FILE* fp, int name_type)
{
    char c;
    int number_of_conversions;
    int index = 0;
    char* pFinal_Array;
    
    //First name
    if (name_type == 2)
    {
        if(fname == NULL || size <= 1)
        {
            return NULL;
        }
        number_of_conversions = fscanf(fp, " %c", &c);
        while(number_of_conversions == 1 && index < size - 1 && !isspace(c))
        {
            fname[index] = c;
            index++;
            number_of_conversions = fscanf(fp, "%c", &c);
        }
        
        if(number_of_conversions != EOF)
        {
            ungetc(c, fp);
        }
        
        fname[index] = '\0';
        if(index == 0)
        {
            return NULL;
        }
        pFinal_Array = fname;
        
        *fname = *pFinal_Array;
    }
    //Last name
    else if (name_type == 3)
    {
        if(lname == NULL || size <= 1)
        {
            return NULL;
        }
        number_of_conversions = fscanf(fp, " %c", &c);
        while(number_of_conversions == 1 && index < size - 1 && !isspace(c))
        {
            lname[index] = c;
            index++;
            number_of_conversions = fscanf(fp, "%c", &c);
        }
        
        if(number_of_conversions != EOF)
        {
            ungetc(c, fp);
        }
        
        lname[index] = '\0';
        if(index == 0)
        {
            return NULL;
        }
        pFinal_Array = lname;
        
        *lname = *pFinal_Array;
    }
    return pFinal_Array;
}

int* get_ints(char* buffer, int size, FILE* fp, double* average, FILE* fp3)
{
    int number_of_conversions;
    int index = 0, i;
    int numbers[10];
    int count = 0;
    
    if(buffer == NULL || size <= 1)
    {
        return NULL;
    }
    
    //Convert the string numbers to integers
    number_of_conversions = fscanf(fp, " %d", &i);
    while(number_of_conversions == 1 && index < size - 1 && !isspace(i))
    {
        numbers[index] = i;
        fprintf(fp3, " %4d", numbers[index]);
        *average += numbers[index];
        index++;
        count ++;
        number_of_conversions = fscanf(fp, "%d", &i);
    }
    
    //Insert 0 into empty elements if there are any
    while (count < 10)
    {
        numbers[index] = 0;
        fprintf(fp3, " %4d", numbers[index]);
        *average += numbers[index];
        index++;
        count ++;
    }
    
    if(number_of_conversions != EOF)
    {
        ungetc(i, fp);
    }
    
    buffer[index] = '\0';
    if(index == 0)
    {
        return NULL;
    }
    return numbers;
}

char* read_string2(char* buffer, int size, FILE* fp)
{
    char c;
    int number_of_conversions;
    int index = 0;
    
    if(buffer == NULL || size <= 1)
    {
        return NULL;
    }
    number_of_conversions = fscanf(fp, " %c", &c);
    while(number_of_conversions == 1 && index < size - 1 && !isspace(c))
    {
        buffer[index] = c;
        index++;
        number_of_conversions = fscanf(fp, "%c", &c);
    }
    
    if(number_of_conversions != EOF)
    {
        ungetc(c, fp);
    }
    
    buffer[index] = '\0';
    if(index == 0)
    {
        return NULL;
    }
    return buffer;
}