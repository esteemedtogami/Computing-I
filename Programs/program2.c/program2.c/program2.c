/*****************************************
 Author: Sam Pickell
 Date: 10/7/15
 
 Purpose: Use the Fibonacci Sequence to
 calculate the population of green crud
 after the user inputs the inital size
 of the crud population and the number
 of days that it will grow for.
 
 Time Spent: 1 hour and 43 minutes.
*****************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void clear_keyboard_buffer(void);

int check_for_validity_size(int number);

int check_for_validity_days(int number);

int calculate_crud(int size, int days);

int main(int argc, char* argv[])
{
    char continue_calculating = 'y';
    
    while (continue_calculating == 'y' || continue_calculating == 'Y')
    {
        int size = 0, days = 0;
        char continue_calculating;
        
        
        printf("Please enter the initial size of the green crud: ");
        scanf("%d", &size);
        clear_keyboard_buffer();
        size = check_for_validity_size(size);
    
        printf("Please enter the number of days (characters will count as 0): ");
        scanf("%d", &days);
        clear_keyboard_buffer();
        days = check_for_validity_days(days);
    
        printf("With an initial population of %d pounds of crud growing for %d days, \n", size, days);
        printf("The final population would be %d pounds.\n", calculate_crud(size, days));
        
        printf("Would you like to continue? (y/n): ");
        scanf("%c", &continue_calculating);
        clear_keyboard_buffer();
        
        if (continue_calculating == 'y' || continue_calculating == 'Y')
        {
            
        }
        else
        if (continue_calculating == 'n' || continue_calculating == 'N')
        {
            break;
        }
        else
        {
            printf("I'm sorry, that answer is unrecognized.\n");
            printf("Would you like to continue? (y/n): ");
            scanf("%c", &continue_calculating);
            clear_keyboard_buffer();
        }
    }
    
    return 0;
}

int check_for_validity_size(int number)
{
    if (number <= 0)
    {
        while (number <= 0)
        {
            printf("I'm sorry, that value is unrecognized or negative.\n");
            printf("Please enter the initial size of the green crud: ");
            scanf("%d", &number);
            clear_keyboard_buffer();
            
            if (number > 0)
            {
                break;
            }
        }
    }
    
    return number;
    
}

int check_for_validity_days(int number)
{
    
    // If a user enters a character, assume they know it counts as 0
    if (number < 0)
    {
        while (number < 0)
        {
            printf("I'm sorry, that value is unrecognized or negative.\n");
            printf("Please enter the number of days: ");
            scanf("%d", &number);
            clear_keyboard_buffer();
            
            if (number >= 0)
            {
                break;
            }
        }
    }
    
    return number;
    
}


int calculate_crud(int size, int days)
{
    int new_value = 0, old_value = size, current_value = 0, count_two = 0, calc_iterations = (days / 5);
    
    if (count_two >= calc_iterations)
    {
        return old_value;
    }
    else
    {
        
    while (count_two <= calc_iterations)
    {
        new_value = current_value + old_value;
        old_value = current_value;
        current_value = new_value;
        count_two ++;
    }
        
        
        return new_value;
    }
    
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