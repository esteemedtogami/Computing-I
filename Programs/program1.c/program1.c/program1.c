/****************************************************
 Author: Sam Pickell
 Date: 9/30/15

 Purpose: Create a program that takes two integers
 (a start point and an end point) and using the
 Collatz Conjecture, calculates how many steps
 it takes each number to get the number being viewed 
 to 1.
 Time Spent: 1 hour and 6 minutes
****************************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);

int calculate_steps(int number);

int main(int argc, char* argv[])
{
    int start_point, end_point, count = 0;
    
    //printf("+%d4%+-20d%+3d%-5d\n", 42, 742, 30, 56);
    printf("Enter a starting point: ");
    scanf("%d", &start_point);
    clear_keyboard_buffer();
    
    while (start_point < 2)
    {
        printf("Error. Please choose an integer greater than 1: ");
        scanf("%d", &start_point);
        clear_keyboard_buffer();
    }
    
    printf("Enter an ending point: ");
    scanf("%d", &end_point);
    clear_keyboard_buffer();
    
    while (end_point > 9999)
    {
        printf("Error. Please choose an integer less than 10,000: ");
        scanf("%d", &end_point);
        clear_keyboard_buffer();
        printf("\n");
    }
    
    while (start_point <= end_point)
    {
        if (start_point % 2 == 1)
        {
            printf("%5d:%-5d", start_point, calculate_steps(start_point));
            count ++;
        }
        else
            if (start_point % 2 ==0)
            {
                printf("%5d:%-5d", start_point, calculate_steps(start_point));
                count ++;
            }
        if (count == 7)
        {
            printf("\n");
            count = 0;
        }
        
        start_point ++;
    }
    
    return 0;
}

int calculate_steps(int number)
{
    int counter = 0;
    while (number != 1)
    {
        if (number % 2 == 1)
        {
            number = ((number * 3) + 1);
            counter ++;
        }
        else
            if (number % 2 == 0)
            {
                number = number / 2;
                counter ++;
            }
    }
    
    return counter;
}

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        scanf("%c", &c);
        
        
    } while (c != '\n');
    
    
    
    return;
}