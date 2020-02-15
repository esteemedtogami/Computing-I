/***********************************************
 Author: Sam Pickell
 Date: 10/31/15
 
 Purpose: Have the user fill in an array with 
    integers and then a function will determine 
    and display the index of the largest integer 
    in the array.
 
 Sources of Help: None this time.
 
 Time Spent: 53 minutes
***********************************************/

#include <stdio.h>

#define SIZE 10

void clear_keyboard_buffer(void);

//Precondition: There must be a full array
//  that can be sent to this function
//Postcondition: The index for the maximum
//  number in the array is displayed.
void return_max(int list[], int size);

int main(int argc, char* argv[])
{
    int numbers[SIZE];
    int i, user_input;
    
    printf("Enter 10 integer values...\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Value %d: ", i + 1);
        scanf("%d", &user_input);
        clear_keyboard_buffer();
        numbers[i] = user_input;
    }
    
    return_max(numbers, SIZE);
    
    
    return 0;
}

void return_max(int list[], int size)
{
    int i, index_with_largest_number = 0, largest_number = list[0];
    
    for (i = 0; i < size; i++)
    {
        if (list[i] > largest_number)
        {
            index_with_largest_number = i;
            largest_number = list[i];
        }
    }
    
    printf("The index for the maximum is: %d.\n", index_with_largest_number);
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