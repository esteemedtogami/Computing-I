/*******************************************
 Author: Sam Pickell
 Date: 9/30/15
 
 Purpose: Prompt the user to enter how many
 asterisks they want printed in each line, 
 and how many lines they want printed.
 Time Spent: 27 minutes
*******************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);

void draw_box (int asterisks, int lines);

int main (int argc, char* argv[])
{
    int number_of_asterisks, number_of_lines;
    
    printf("Please enter the number of asterisks you want in your line: ");
    scanf("%d", &number_of_asterisks);
    clear_keyboard_buffer();
    
    while (number_of_asterisks < 1 || number_of_asterisks > 79)
    {
        printf("I'm sorry, that number is unrecognized or out of range. Try [1-79]: ");
        scanf("%d", &number_of_asterisks);
        clear_keyboard_buffer();
    }
    
    printf("Please enter the number of lines you want in your box: ");
    scanf("%d", &number_of_lines);
    clear_keyboard_buffer();
    
    while (number_of_lines < 1 || number_of_lines > 23)
    {
        printf("I'm sorry, that number is unrecognized or out of range. Try [1-23]: ");
        scanf("%d", &number_of_lines);
        clear_keyboard_buffer();
    }
    
    draw_box(number_of_asterisks, number_of_lines);
    
    return 0;
}

void draw_box (int asterisks, int lines)
{
    int count_lines = 0;
    
    while (count_lines < lines)
    {
        int count_asterisks;
        count_asterisks = asterisks;
            
        while (count_asterisks > 0)
        {
            printf("*");
            count_asterisks --;
        }
            printf("\n");
        count_lines ++;
    }
    
    return;
    
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