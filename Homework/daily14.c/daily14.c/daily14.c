/*****************************************
 Author: Sam Pickell
 Date: 10/05/15
 
 Purpose: Get user input using a function
 that accepts positive integers greater 
 than 0, and then find the largest positve
 integer that evenly divides the two input
 numbers.
 
 Time spent: 1 hour and 4 minutes
*****************************************/
#include <stdio.h>

void clear_keyboard_buffer(void);

int get_user_input(void);

int check_for_validity(int input);

int largest_int(int num1, int num2);

int main(int argc, char* argv[])
{
    int number_one, number_two;
    
    number_one = get_user_input();
    number_two = get_user_input();
    
    printf("The largest integer that divides both %d and %d is: %d\n", number_one, number_two,
           largest_int(number_one, number_two));
    
    return 0;
}


int get_user_input(void)
{
    int number = 0;
    
    printf("Please enter a positive integer: ");
    scanf("%d", &number);
    clear_keyboard_buffer();
    
    if (number <= 0)
    {
    number = check_for_validity(number);
    }
    
    return number;
}

int check_for_validity(int input)
{
    int new_num = input;
    
    while (new_num <= 0)
    {
        printf("I'm sorry, that number is unrecognized or not positive.\n");
        printf("Please enter a positive integer: ");
        scanf("%d", &new_num);
        clear_keyboard_buffer();
    }
    return new_num;
}


int largest_int(int num1, int num2)
{
    int divisor, count_num_one = num1, count_num_two = num2;
    
    if (num1 < num2)
    {
        while (count_num_one >= 1)
        {
            if ((count_num_two % count_num_one == 0) && (count_num_one % 2 == 0))
            {
                break;
            }
            
            count_num_one --;
        }
        
        divisor = count_num_one;
    }
    else
        if (num2 < num1)
        {
            while (count_num_two >= 1)
            {
                if ((count_num_one % count_num_two == 0) && (count_num_two % 2 == 0))
                {
                    break;
                }
                
                count_num_two --;
            }
            
            divisor = count_num_two;
        }
    
    return divisor;
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