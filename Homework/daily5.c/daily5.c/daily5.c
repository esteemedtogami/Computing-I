/*
Programmer: Sam Pickell
Date: 9/15/15
Filename: daily5.c
Purpose: Create a function that can be called and printed on screen
*/

#include <stdio.h>

void smile(void);

int main(int argc, char* argv[])
{
    smile();
    smile();
    smile();
    return 0;
    
}

void smile(void)
{
 
    printf("   ****\n");
    printf("  * . . *\n");
    printf(" *        *\n");
    printf(" *  \\_/   *\n");
    printf("  *      *\n");
    printf("    ****\n");
    return;
    
}
