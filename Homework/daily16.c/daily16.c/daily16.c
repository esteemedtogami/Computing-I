/*******************************************
 Author: Sam Pickell
 Date: 10/14/15
 
 Purpose: Calculate how long it takes to 
    pay off a stereo based on a monthly 
    payment and interest rate, as well as
    the total interest paid over the life
    of the life of the stereo. List the 
    amount of the final payment.
 Sources of Help: None used this time.
 Time Spent: 57 minutes
*******************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int month = 0;
    double old_balance = 1000.00, new_balance = old_balance, total_interest = 0.0,
        final_monthly_payment = 50;
    const double interest = .015, monthly_payment = 50.0, paid_off = 0.0;
    
    while (old_balance > paid_off)
    {
        if (old_balance <= monthly_payment)
        {
            final_monthly_payment = old_balance;
            total_interest += old_balance * interest;
            new_balance = old_balance - (final_monthly_payment - (interest * old_balance));
            month ++;
            break;
        }
        total_interest += old_balance * interest;
        new_balance = old_balance - (monthly_payment - (interest * old_balance));
        old_balance = new_balance;
        month ++;
    }
    
    printf("The total amount of months it takes to pay off the stereo system is: %d\n", month);
    printf("The total amount of interest paid over the life of the loan is: $%.2lf\n", total_interest);
    printf("The final payment was: $%.2lf\n", old_balance);
    
    return 0;
}