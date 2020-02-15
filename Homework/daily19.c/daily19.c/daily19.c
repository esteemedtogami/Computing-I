/***********************************************
 Author: Sam Pickell
 Date: 10/24/15
 
 Purpose: Use pointers to use a single function 
    that returns the number of each type of coin
    based on a total number of cents.
 
 Sources of Help: None this time.
 
 Time Spent: 54 minutes
 ***********************************************/
#include <stdio.h>

//Precondition: None
//Postcondition: Return number of quarters,
//  dimes, nickels, pennies
void get_change(int total, int* quarters, int* dimes, int* nickels, int* pennies);

int main(int argc, char * argv[]) {
    int totalCents;
    int numQuarters = 0, numDimes = 0, numNickels = 0, numPennies = 0;
    
    printf("Please enter the total number of cents (0-1000): ");
    scanf("%d", &totalCents);
    
    get_change(totalCents, &numQuarters, &numDimes, &numNickels, &numPennies);
    
    
    //print the result to the screen
    printf("The total number of quarters is: %d\n", numQuarters);
    printf("The total number of dimes is: %d\n", numDimes);
    printf("The total number of nickels is: %d\n", numNickels);
    printf("The total number of pennies is: %d\n", numPennies);
    
    return 0;
}

void get_change(int total, int* quarters, int* dimes, int* nickels, int* pennies)
{
    
    while (total >= 25)
    {
        total -= 25;
        *quarters += 1;
    }
    while (total >= 10 && total < 25)
    {
        total -= 10;
        *dimes += 1;
    }
    while (total >= 5 && total < 10)
    {
        total -= 5;
        *nickels += 1;
    }
    while (total >= 1 && total < 5)
    {
        total -= 1;
        *pennies += 1;
    }
    return;
}
