/*****************************************
Author: Sam Pickell
Date: 10/04/15
 
Purpose: Enhanced rock-paper-scissors
 program that checks for validity,
 accepts user input, keeps score, and
 lets the user replay the game if
 they choose to.
 
Time Spent: 2 hours and 5 minutes
*****************************************/
#include <stdio.h>

enum choice{ROCK, PAPER, SCISSORS};
typedef enum choice Choice;

void clear_keyboard_buffer(void);
void check_for_validity(char c);
void check_for_continue(char c);
void player_choice(char p1, char p2);


int main(int argc, char* argv[])
{
    char player_one = 'c';
    char player_two = 'd';
    char keep_playing = 'y';
    
    while (keep_playing == 'y' || keep_playing == 'Y')
    {
        printf("Player 1 it is your turn!\n");
        printf("Please enter your choice, (r)ock, (p)aper, or (s)cissors: ");
        scanf("%c", &player_one);
        clear_keyboard_buffer();
        check_for_validity(player_one);

        printf("Player 2 it is your turn!\n");
        printf("Please enter your choice, (r)ock, (p)aper, or (s)cissors: ");
        scanf("%c", &player_two);
        clear_keyboard_buffer();
        check_for_validity(player_two);

        player_choice(player_one, player_two);
        
        printf("Do you wish to continue? (y/n): ");
        scanf("%c", &keep_playing);
        clear_keyboard_buffer();
        check_for_continue(keep_playing);
    }
    
    return 0;
}


void player_choice(char p1, char p2)
{
    Choice player_one;
    
    
    if (p1 == 'r' || p1 == 'R')
    {
        player_one = ROCK;
    }
    else
        if (p1 == 'p' || p1 == 'P')
        {
            player_one = PAPER;
        }
        else
            if (p1 == 's' || p1 == 'S')
            {
                player_one = SCISSORS;
            }
        
    
    switch (player_one)
    {
    case ROCK:
        if (p2 == 'r' || p2 == 'R')
        {
            printf("Draw. Nobody wins.\n");
        }
        else
            if (p2 == 'p' || p2 == 'P')
            {
                printf("Player 2 wins. Paper covers rock.\n");
            }
            else
                if (p2 == 's' || p2 == 'S')
                {
                    printf("Player 1 wins. Rock breaks Scissors.\n");
                }
        break;
    case PAPER:
        if (p2 == 'r' || p2 == 'R')
        {
            printf("Player 1 wins. Paper covers rock.\n");
        }
        else
            if (p2 == 'p' || p2 == 'P')
            {
                printf("Draw. Nobody wins.\n");
            }
            else
                if (p2 == 's' || p2 == 'S')
                {
                    printf("Player 2 wins. Scissors cut paper.\n");
                }
        break;
    case SCISSORS:
        if (p2 == 'r' || p2 == 'R')
        {
            printf("Player 2 wins. Rock breaks scissors.\n");
        }
        else
            if (p2 == 'p' || p2 == 'P')
            {
                printf("Player 1 wins. Scissors cut paper.\n");
            }
            else
                if (p2 == 's' || p2 == 'S')
                {
                    printf("Draw. Nobody wins.\n");
                }
        break;
    }
}


void check_for_validity(char c)
{
    int check = 0;
    
    while (check == 0)
    if (c == 'r' || c == 'R' || c == 'p' || c == 'P' || c == 's' || c == 'S')
    {
        check ++;
    }
    
    else
    {
        printf("I'm sorry, I do not understand.\n");
        printf("Please enter your choice, (r)ock, (p)aper, or (s)cissors: ");
        scanf("%c", &c);
        clear_keyboard_buffer();
        
    }
    return;
}


void check_for_continue(char c)
{
    int check = 0;
    
    while (check == 0)
        if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
        {
            check ++;
        }
    
        else
        {
            printf("I'm sorry, I do not understand.\n");
            printf("Do you wish to continue? (y/n): ");
            scanf("%c", &c);
            clear_keyboard_buffer();
            
        }
    return;
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