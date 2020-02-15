/*****************************************
    Author: Sam Pickell
    Date: 9/18/15
 
    Answer to question: The computer will
    encounter a "stack overflow".
 ****************************************/

#include <stdio.h>

void recursive_down_to_zero(int number);
void recursive_up_to_int(int number);

int main(int argc, char* argv[])
{
    
    static int number = 0;
    
    printf("Please enter a positive integer:");
    scanf("%d", &number);
    recursive_down_to_zero(number);
    printf("****\n");
    recursive_up_to_int(number);
    
    return 0;
}

void recursive_down_to_zero(int number)
{
    if(number >= 0)
    {
        printf("%d\n", number);
        recursive_down_to_zero(number - 1);
    }
    return;
}

void recursive_up_to_int(int number)
{
    if(number >= 0)
    {
        recursive_up_to_int(number - 1);
        printf("%d\n", number);
    }
    
    return;
}