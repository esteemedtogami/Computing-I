/************************************************************
 Author: Sam Pickell
 Date: 10/19/15
 
 Purpose: Use stub functions to output the user's choice of
 lengths or weights to keep "main" as minimal as possible.
 Sources of Help: None this time.
 Time: 24 minutes
************************************************************/
 

#include <stdio.h>

void clear_keyboard_buffer(void);

void user_input(int number);

void convert_lengeths(void);

void convert_weights(void);

int main(int argc, const char * argv[])
{
    
    int user_wishes_to_continue = 42, user_choice;
    
    
    do
    {
        printf("Would you like to convert values that are lengths (1) or weights (2)? (0 will exit): ");
        scanf("%d", &user_choice);
        clear_keyboard_buffer();
        user_wishes_to_continue = user_choice;
        user_input(user_choice);
        
        
    } while (user_wishes_to_continue != 0);
    
    return 0;
}

void user_input(int number)
{
    if (number == 1)
    {
        convert_lengeths();
    }
    else if (number == 2)
    {
        convert_weights();
    }
    else if (number == 0)
    {
        
    }
    else
    {
        printf("I'm sorry. That is unrecognized or out of bounds.\n");
    }
    return;
}

void convert_lengeths(void)
{
    printf("You chose lengths!\n");
    return;
}

void convert_weights(void)
{
    printf("You chose weights!\n");
    return;
}

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        
        scanf("%c", &c);
        
    }while (c != '\n');
    return;
}
