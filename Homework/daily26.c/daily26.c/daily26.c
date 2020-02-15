/*****************************************
 Author: Sam Pickell
 Date: 11/23/15
 
 Purpose: Use malloc to create a dynamic
    array and display the contents
    backwards and forwards on the screen.
 
 Sources of Help: None this time.
 
 Time Spent: 43 minutes
*****************************************/
#include <stdio.h>
#include <stdlib.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int* pInt;
    int n, i, j;
    
    printf("Please enter the number of elements in the dynamic array: ");
    scanf("%d", &n);
    clear_keyboard_buffer();
    
    while (n < 1)
    {
        printf("Invalid input. Please enter a number greater than 0: ");
        scanf("%d", &n);
        clear_keyboard_buffer();
    }
    
    j = n;
    
    pInt = (int*) (malloc(sizeof(n)));
    
    if (pInt == NULL)
    {
        printf("Memory was not allocated properly.\n");
        return 1;
    }
    
    for (i = n - 1; i >= 0; i --)
    {
        n --;
        pInt[i] = n;
        printf("Element at index %d: %d\n", i, pInt[i]);
    }
    
    printf("***\n");
    
    for (i = 0; i < j; i++)
    {
        printf("Element at index %d: %d\n", i, *pInt);
        *pInt ++;
    }
    
    
    return 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        scanf("%c", &c);
        
    } while (c != '\n');
}