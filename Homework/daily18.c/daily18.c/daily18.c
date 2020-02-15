/************************************************************
 Author: Sam Pickell
 Date: 10/21/15
 Resubmit Date: 10/25/15
 Reason for resubmit: Wasn't displaying all options to the
    user. Added printf statements in the convert_lengths
    and convert_weights functions that prompt the user to
    enter 0 to return to the main menu.
 
 Purpose: Further use of Top Down Approach: continuing to
    use stub functions in order to better break down the
    problem at hand and make it more manageable
 Sources of Help: None this time
 Time: 1 hour
 ************************************************************/


#include <stdio.h>

//Precondition: None
//Postcondition: Keyboard buffer is cleared
void clear_keyboard_buffer(void);

//Precondition: None
//Postcondition: Displays the conversion based on
//  usr input
void user_input(int number);

//Precondition: None
//Postcondition: Input is sorted
//  to the function specified
void convert_lengeths(void);

//Precondition: None
//Postcondition: Units of weight are converted
void convert_weights(void);

//Precondition: None
//Postcondition: Units of length are converted to metric
//  from US
void length_to_metric(void);

//Precondition: None
//Postcondition: Units of length are converted to US
//  from metric
void length_to_us(void);

//Precondition: None
//Postcondition: Units of weight are converted to metric
//  from US
void weight_to_metric(void);

//Precondition: None
//Postcondition: Units of weight are converted to US
//  from metric
void weight_to_us(void);

int main(int argc, const char * argv[])
{
    
    int user_wishes_to_continue = 42, user_choice;
    
    
    do
    {
        printf("Would you like to convert values that are lengths (1) or weights (2)? (0 will exit): ");
        scanf("%d", &user_choice);
        clear_keyboard_buffer();
        user_wishes_to_continue = user_choice;
        user_input(user_choice);
        
        
    } while (user_wishes_to_continue != 0);
    
    return 0;
}

void user_input(int number)
{
    if (number == 1)
    {
        convert_lengeths();
    }
    else if (number == 2)
    {
        convert_weights();
    }
    else if (number == 0)
    {
        
    }
    else
    {
        printf("I'm sorry. That is unrecognized or out of bounds.\n");
    }
    return;
}

void convert_lengeths(void)
{
    int user_choice;
    
    printf("Would you like to convert from: \n");
    printf("1) Feet/inches to meters/centimeters, \n");
    printf("2) Meters/centimeters to feet/inches, or \n");
    printf("0) To return to main menu.\n");
    scanf("%d", &user_choice);
    clear_keyboard_buffer();
    
    do
    {
        if (user_choice == 1)
        {
            length_to_metric();
            printf("Would you like to convert from: \n");
            printf("1) Feet/inches to meters/centimeters, \n");
            printf("2) Meters/centimeters to feet/inches, or \n");
            printf("0) To return to main menu.\n");
            scanf("%d", &user_choice);
            clear_keyboard_buffer();
        }
        else if (user_choice == 2)
        {
            length_to_us();
            printf("Would you like to convert from: \n");
            printf("1) Feet/inches to meters/centimeters, \n");
            printf("2) Meters/centimeters to feet/inches, or \n");
            printf("0) To return to main menu.\n");
            scanf("%d", &user_choice);
            clear_keyboard_buffer();
        }
        else if (user_choice == 0)
        {
            printf("\n");
        }
        else
        {
            printf("Error. Please enter: \n");
            printf("1) To convert from feet/inches.\n");
            printf("2) To convert from meters/centimeters.\n");
            printf("0) To return to main menu.\n");
            scanf("%d", &user_choice);
            clear_keyboard_buffer();
        }
    } while (user_choice != 0);
    return;
}

void convert_weights(void)
{
    int user_choice;
    
    printf("Would you like to convert from: \n");
    printf("1) Pounds/ounces to kilograms/grams,  \n");
    printf("2) Kilograms/grams to pounds/ounces, or \n");
    printf("0) To return to main menu.\n");
    scanf("%d", &user_choice);
    clear_keyboard_buffer();
    
    do
    {
        if (user_choice == 1)
        {
            weight_to_metric();
            printf("Would you like to convert from: \n");
            printf("1) Pounds/ounces to kilograms/grams,  \n");
            printf("2) Kilograms/grams to pounds/ounces, or \n");
            printf("0) To return to main menu.\n");
            scanf("%d", &user_choice);
            clear_keyboard_buffer();
        }
        else if (user_choice == 2)
        {
            weight_to_us();
            printf("Would you like to convert from: \n");
            printf("1) Pounds/ounces to kilograms/grams,  \n");
            printf("2) Kilograms/grams to pounds/ounces, or \n");
            printf("0) To return to main menu.\n");
            scanf("%d", &user_choice);
            clear_keyboard_buffer();
        }
        else if (user_choice == 0)
        {
            printf("\n");
        }
        else
        {
            printf("Error. Please enter: \n");
            printf("1) To convert from pounds/ounces.\n");
            printf("2) To convert from kilograms/grams.\n");
            printf("0) To return to main menu.\n");
            scanf("%d", &user_choice);
            clear_keyboard_buffer();
        }
    } while (user_choice != 0);
    return;
}

void length_to_metric(void)
{
    printf("I convert lengths from US to metric!\n");
    printf("\n");
    return;
}

void length_to_us(void)
{
    printf("I convert lengths from metric to US!\n");
    printf("\n");
    return;
}

void weight_to_metric(void)
{
    printf("I convert weights from US to metric!\n");
    printf("\n");
    return;
}

void weight_to_us(void)
{
    printf("I convert weights from metric to US!\n");
    printf("\n");
    return;
}

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        
        scanf("%c", &c);
        
    }while (c != '\n');
    return;
}
