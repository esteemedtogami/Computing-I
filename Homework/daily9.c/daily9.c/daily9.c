/*****************************************
 Author: Sam Pickell
 Date: 9/23/15
 
 Purpose: Write a program that prompts
 the user to enter a positive integer
 greater than 0 and use a while loop
 to trap any invalid inputs.

 Time spent: 17 minutes
****************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int number;
    
    printf("Please enter a positive integer: ");
    scanf("%d", &number);
    clear_keyboard_buffer();
    
    while (number <= 0)
    {
        printf("I'm sorry, please enter a positive integer greater than 0: ");
        scanf("%d", &number);
        clear_keyboard_buffer();
    }
    
    printf("The positive integer was: %d\n", number);
    
    return 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    do
    {
        scanf("%c", &c);
        
        
    }while(c != '\n');
        
        return;
}