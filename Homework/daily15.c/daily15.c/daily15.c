/*****************************************************************************
 Author: Sam Pickell
 Date: 10/13/15
 
 
 Purpose: Write a program that accepts user input for two masses and a
    distance, then calculate the total gravitational force with the input
    and the universal gravitational constant G. Allows user to use the 
    program so long as they choose to continue.
 Sources of Help: None used this time.
 Gravitational force in dynes of the moon on the earth: 1.98164e25 dynes.
    In order to get this answer, the two masses must be 
    5.972e27 and 7.34767309e25, and the distance must be 3.844e10 to 
    properly use the information given as it is in kilograms and kilometers.
 Time Spent: 1 hour and 30 minutes
*****************************************************************************/

#include <stdio.h>
#include <math.h>

const double UNIVERSAL_GRAVITATIONAL_CONSTANT = 6.673e-8;

void clear_keyboard_buffer(void);

double check_for_validation(double number);

char check_for_continue(char letter);

double gravitational_force(double mass1, double mass2, double distance);

int main(int argc, char* argv[])
{
    char user_wishes_to_continue = 'y';
    
    while (user_wishes_to_continue == 'y' || user_wishes_to_continue == 'Y')
    {
        double mass1 = 0.0, mass2 = 0.0, distance = 0.0, total_gravitational_force = 0.0;
        char user_wishes_to_continue = 0;
    
        printf("Please enter the mass (in grams) of the first body: ");
        scanf("%lg", &mass1);
        clear_keyboard_buffer();
        mass1 = check_for_validation(mass1);
    
        printf("Please enter the mass (in grams) of the second body: ");
        scanf("%lg", &mass2);
        clear_keyboard_buffer();
        mass2 = check_for_validation(mass2);
    
        printf("Please enter the distance (in centimeters) between the two bodies: ");
        scanf("%lg", &distance);
        clear_keyboard_buffer();
        distance = check_for_validation(distance);
    
        total_gravitational_force = gravitational_force(mass1, mass2, distance);

        printf("The gravitational attractive force between a body with mass %lg grams\n", mass1);
        printf("and another body with mass %lg grams\n", mass2);
        printf("at a distance of %lg centimeters\n", distance);
        printf("is %lg dynes.\n", total_gravitational_force);
        
        printf("Would you like to continue (y or n)? : ");
        scanf("%c", &user_wishes_to_continue);
        clear_keyboard_buffer();
        
        if (user_wishes_to_continue == 'n' || user_wishes_to_continue == 'N')
        {
            break;
        }
        else if (user_wishes_to_continue == 'y' || user_wishes_to_continue == 'Y')
        {
            
        }
        else
        {
            user_wishes_to_continue = check_for_continue(user_wishes_to_continue);
        }
    }
    return 0;
}

double gravitational_force(double mass1, double mass2, double distance)
{
   long double force;
    
    force = (UNIVERSAL_GRAVITATIONAL_CONSTANT * mass1 * mass2)/(pow(distance, 2.0));
    
    return force;
}

double check_for_validation(double number)
{
    double check = number;
    
    if (check <= 0)
    {
        while (check <= 0)
        {
            printf("I'm sorry, that number was unrecognized or out of range.\n");
            printf("Please enter a new number: ");
            scanf("%lg", &check);
            clear_keyboard_buffer();
        
        }
    }
    
    return check;
}

char check_for_continue(char letter)
{

    char check = letter;
    
    while (check != 'n' || check != 'N' || check != 'y' || check != 'Y')
    {
        printf("I'm sorry, that response was unrecognized.\n");
        printf("Would you like to continue (y or n)? : ");
        scanf("%c", &check);
        clear_keyboard_buffer();
    
        if (check == 'n' || check == 'N')
        {
            break;
        }
        else if (check == 'y' || check == 'Y')
        {
            break;
        }
    
    }
    
    return check;
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