/************************************************************
 Program: program3.c
 Author: Sam Pickell
 Date: 10/28/15
 Time Spent: 3 hours
 Sources of Help: None this time
 Purpose: Finishing daily18.c and making it a complete
    program that converts units of length and weight
    from US measurements to metric measurements and
    vice versa using the top down approach.
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

//Precondition: None
//Postcondition: Received user input
void input_length_to_metric(int* feet, double* inches);

//Precondition: None
//Postcondition: Length in US measurements
//  converted to metric
void convert_length_to_metric(int* feet, double * inches, int* meters, double* centimeters);

//Precondition: None
//Postcondition: Converted length is displayed
void output_length_to_metric(int* meters, double* centimeters);

//Precondition: None
//Postcondition: Received user input
void input_length_to_us(int* meters, double* centimeters);

//Precondition: None
//Postcondition: Length in metric measurements
//  converted to US measurements
void convert_length_to_us(int* feet, double * inches, int* meters, double* centimeters);

//Precondition: None
//Postcondition: Converted length is displayed
void output_length_to_us(int* feet, double* inches);

//Precondition: None
//Postcondition: Received user input
void input_weight_to_metric(int* pounds, double* ounces);

//Precondition: None
//Postcondition: Weight in US measurements
//  converted to metric measurements
void convert_weight_to_metric(int* pounds, double* ounces, int* kilograms, double* grams);

//Precondition: None
//Postcondition: Converted weight is displayed
void output_weight_to_metric(int* kilograms, double* grams);

//Precondition: None
//Postcondition: Received user input
void input_weight_to_us(int* kilograms, double* grams);

//Precondition: None
//Postcondition: Weight in metric measurements
//  converted to US measurements
void convert_weight_to_us(int* pounds, double* ounces, int* kilograms, double* grams);

//Precondition: None
//Postcondition: Converted weight is displayed
void output_weight_to_us(int* pounds, double* ounces);

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
    int feet = 0, meters = 0;
    double inches = 0.0, centimeters = 0.0;
    
    printf("\n");
    input_length_to_metric(&feet, &inches);
    convert_length_to_metric(&feet, &inches, &meters, &centimeters);
    output_length_to_metric(&meters, &centimeters);
    printf("\n");
    
    return;
}

void length_to_us(void)
{
    int feet = 0, meters = 0;
    double inches = 0.0, centimeters = 0.0;
    
    printf("\n");
    input_length_to_us(&meters, &centimeters);
    convert_length_to_us(&feet, &inches, &meters, &centimeters);
    output_length_to_us(&feet, &inches);
    printf("\n");
    
    return;
}

void weight_to_metric(void)
{
    int pounds, kilograms;
    double ounces, grams;
    
    printf("\n");
    
    input_weight_to_metric(&pounds, &ounces);
    convert_weight_to_metric(&pounds, &ounces, &kilograms, &grams);
    output_weight_to_metric(&kilograms, &grams);
    
    printf("\n");
    return;
}

void weight_to_us(void)
{
    int pounds, kilograms;
    double ounces, grams;
    
    printf("\n");
    
    input_weight_to_us(&kilograms, &grams);
    convert_weight_to_us(&pounds, &ounces, &kilograms, &grams);
    output_weight_to_us(&pounds, &ounces);
    
    printf("\n");
    return;
}

void input_length_to_metric(int* feet, double* inches)
{
    printf("Enter the length: \n");
    printf("Feet: ");
    scanf("%d", feet);
    printf("Inches: ");
    scanf("%lf", inches);
    
    return;
}

void convert_length_to_metric(int* feet, double * inches, int* meters, double* centimeters)
{
    *inches = *inches + (*feet * 12);
    *meters = (int)((*inches / 12) * .3048);
    *centimeters = (((*inches / 12.0) * .3048) - *meters) * 100;

    return;
}

void output_length_to_metric(int* meters, double* centimeters)
{
    printf("The converted length is: %d meters and %lf centimeters.\n", *meters, *centimeters);
    
    return;
}

void input_length_to_us(int* meters, double* centimeters)
{
    printf("Enter the length: \n");
    printf("Meters: ");
    scanf("%d", meters);
    printf("Centimeters: ");
    scanf("%lf", centimeters);
    
    return;
}

void convert_length_to_us(int* feet, double * inches, int* meters, double* centimeters)
{
    *centimeters = *centimeters + (*meters * 100);
    *feet = (int)((*centimeters) / 30.48);
    *inches = ((*centimeters / 30.48) - *feet) * 12;
    
    return;
}

void output_length_to_us(int* feet, double* inches)
{
    printf("The converted length is: %d feet and %lf inches.\n", *feet, *inches);
    
    return;
}

void input_weight_to_metric(int* pounds, double* ounces)
{
    printf("Enter the weight: \n");
    printf("Pounds: ");
    scanf("%d", pounds);
    printf("Ounces: ");
    scanf("%lf", ounces);
    
    return;
}

void convert_weight_to_metric(int* pounds, double* ounces, int* kilograms, double* grams)
{
    *ounces = *ounces + (*pounds * 16);
    *kilograms = (int)((*ounces / 16) / 2.2046);
    *grams = (((*ounces / 16.0) / 2.2046) - *kilograms) * 1000;
    
    return;
}

void output_weight_to_metric(int* kilograms, double* grams)
{
    printf("The converted weight is: %d kilograms and %lf grams.\n", *kilograms, *grams);
    
    return;
}

void input_weight_to_us(int* kilograms, double* grams)
{
    printf("Enter the weight: \n");
    printf("Kilograms: ");
    scanf("%d", kilograms);
    printf("Grams: ");
    scanf("%lf", grams);
    
    return;
}

void convert_weight_to_us(int* pounds, double* ounces, int* kilograms, double* grams)
{
    *grams = *grams + (*kilograms * 1000);
    
    printf("grams: %lf\n", *grams);
    
    *pounds = (int)(((*grams) * .0022046));
    
    printf("pounds: %d\n", *pounds);
    
    *ounces = ((*grams * .0022046) - *pounds) * 16;
    
    printf("ounces: %lf\n", *ounces);
    
    return;
}

void output_weight_to_us(int* pounds, double* ounces)
{
    printf("The converted weight is: %d pounds and %lf ounces.\n", *pounds, *ounces);
    
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
