/***************************************************
 Author: Sam Pickell
 Original Date: 9/28/15
 Resubmit Date: 10/12/15
 
 Purpose: Create a rock-paper-scissors game that
 keeps score and accepts user input.
 
 Reason for Resubmit: Fixing else if statements
 so as not to fall into bad practice.
 
 Time Spent: 37 minutes
***************************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    char player_one;
    char player_two;
    
    printf("Player 1, it's your turn!\n");
    printf("Please enter your choice, (p)aper, (r)ock, or (s)cissors: ");
    scanf("%c", &player_one);
    clear_keyboard_buffer();
    printf("Player 2, it's your turn!\n");
    printf("Please enter your choice, (p)aper, (r)ock, or (s)cissors: ");
    scanf("%c", &player_two);
    clear_keyboard_buffer();
    
    
    if ((player_one == 'p' || player_one == 'P') && (player_two == 'r' || player_two == 'R'))
    {
        printf("Player 1 wins! Paper covers rock.\n");
    }
    else if ((player_one == 'p' || player_one == 'P') && (player_two == 's' || player_two == 'S'))
    {
        printf("Player 2 wins! Scissors cut paper.\n");
    }
    else if ((player_one == 'r' || player_one == 'R') && (player_two == 'p' || player_two == 'P'))
    {
        printf("Player 2 wins! Paper covers rock.\n");
    }
    else if ((player_one == 'r' || player_one == 'R') && (player_two == 's' || player_two == 'S'))
    {
        printf("Player 1 wins! Rock breaks scissors.\n");
    }
    else if ((player_one == 's' || player_one == 'S') && (player_two == 'r' || player_two == 'R'))
    {
        printf("Player 2 wins! Rock breaks scissors.\n");
    }
    else if ((player_one == 's' || player_one == 's') && (player_two == 'p' || player_two == 'P'))
    {
        printf("Player 1 wins! Scissors cut paper.\n");
    }
    else if ((player_one == 'p' || player_one == 'P') && (player_two == 'p' || player_two == 'P'))
    {
        printf("Draw. Nobody wins.\n");
    }
    else if ((player_one == 'r' || player_one == 'R') && (player_two == 'r' || player_two == 'R'))
    {
        printf("Draw. Nobody wins.\n");
    }
    else if ((player_one == 's' || player_one == 'S') && (player_two == 's' || player_two == 'S'))
    {
        printf("Draw. Nobody wins.\n");
    }
    else
        printf("An incorrect key was pressed.\n");
    
    
    return 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    do{
        scanf("%c", &c);
        
    } while (c != '\n');
    
    return;
}
