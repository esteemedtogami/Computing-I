/*********************************************************
    Author: Sam Pickell
    Date: 9/21/15

    Answer to question: A number like 500000 isn't a 
    problem for this program. Since while loops can loop 
    infinitely, the program is able to handle any number 
    provided that the computer has enough memory to handle
    it. This is different from daily7 where the function
    could only call itself a certain number of times 
    before encountering a stack overflow.
********************************************************/

#include <stdio.h>

void loop_down_to_zero(int number);

void loop_up_to_int(int number);

int main(int argc, char* argv[])
{
    static int number = 0;
    //-----------------
    printf("Please enter a positive integer.");
    scanf("%d", &number);
    loop_down_to_zero(number);
    printf("****\n");
    loop_up_to_int(number);
  
    
    
    return 0;
}

void loop_down_to_zero(int number)
{
    while (number >= 0)
    {
        printf("%d\n", number);
        number = number - 1;
    }
    
    return;
}

void loop_up_to_int(int number)

{
    
    int count = number;
    //---------------------
    while ((number - count) <= number)
    {
        printf("%d\n", (number - count));
        count = count - 1;
       
    }
    
    return;
}