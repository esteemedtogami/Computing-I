/**************************************************
    Author: Sam Pickell
    Date: 9/25/15
 
    Purpose: Prompt the user to enter the number
    of asterisks they would like to have displayed
    on screen. Trap them in a loop if their number
    is outside of the range. Use a function to
    display the asterisks once they enter an
    appropriate number.
 
    Time Spent: 31 minutes
**************************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);

void draw_line(int number);

int main(int argc, char* argv[])
{
    
    static int number;
    
    printf("Please enter the number of asterisks you want in your line: ");
    scanf("%d", &number);
    clear_keyboard_buffer();
    
    while (number < 1 || number > 79)
    {
        printf("I'm sorry, that number is unrecognized or out of range, try [1-79]: ");
        scanf("%d", &number);
        clear_keyboard_buffer();
        
    }
    
    draw_line(number);
    
    return 0;
}

void draw_line(int number)
{
    if (number >= 1 && number <= 79)
    {
        int count;
        count = number;
        
        while (count > 0)
        {
            printf("*");
            count --;
        }
        printf("\n");
    }
}


void clear_keyboard_buffer(void)
{
    char c;
    
    do{
        scanf("%c", &c);
        
    } while (c != '\n');
    
    return;
}