/************************************************************************
    Author: Sam Pickell
    Date: 9/16/15
 
    Purpose: Create a variable that can be changed with user input,
    and has a basic use of the Collapse Conjecture using an if statement.
************************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int number;
    
    printf("Enter a positive integer value.\n");
    scanf("%d", &number);
    
    if(number % 2 == 0)
    {
        number = number / 2;
    }
    else
    {
        number = (number * 3) + 1;
    }
    
    printf("The next value of the number is: %d\n", number);
    return 0;
}