#include <cs50.h>
#include <stdio.h>
#include <math.h>

int credit_len(long n);
bool sum_of_card_numbers(long credit_card_num);
bool valid_or_not(long credit_numbers);
void print_brand(long credit_card_num);

int main(void)
{
    long credit_numbers;
    do
    {
        credit_numbers = get_long("Enter Credit Card Number: ");
    }
    while (credit_numbers < 0);

    //Checking if the card is valid
    if (valid_or_not(credit_numbers))
    {
        //Print the brand of the card if the card is valid
        print_brand(credit_numbers); //Print the brand of the card if the card is valid
    }


    //If the card is not valid, return INVALID
    else
    {
        printf("INVALID\n");
    }

}

// Function use to find the length of the credit card
int credit_len(long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}

// Function use to find the sum of the credit card numbers
bool sum_of_card_numbers(long credit_card_num)
{
    int sum = 0;
    for (int i = 0; credit_card_num != 0; i++, credit_card_num /= 10)
    {
        // Adding every other digits starting from the last digit
        if (i % 2 == 0)
        {
            sum += credit_card_num % 10;
        }

        else
        {
            int digit = 2 * (credit_card_num % 10); // Multiplying the digits by 2 starting with the number’s second-to-last digit
            sum += digit / 10 + digit % 10; // Adding those products’ digits (i.e., not the products themselves) together
        }
    }
    // Return the number if the last digit of the sum is 0
    return (sum % 10) == 0;
}

// Check if the card is valid or not using the Sum of the credit card numbers and the length of the card
bool valid_or_not(long credit_numbers)
{
    int len = credit_len(credit_numbers);

    return (len == 13 || len == 15 || len == 16) && sum_of_card_numbers(credit_numbers);
}

//Function use to check which brand is the credit card is from.
void print_brand(long credit_card_num)
{
    // American Express uses 15-digit numbers, so by having the 2 starting number for AMEX which is 34 and 37, having 13 more "zeroes" after it will check if its a valid AMEX card or not
    if ((credit_card_num >= 34e13 && credit_card_num < 35e13) || (credit_card_num >= 37e13 && credit_card_num < 38e13))
    {
        printf("AMEX\n");
    }


    // MasterCard uses 16-digit numbers, so by having the 2 starting number for MASTERCARD which is 51 to 55, having 14 more "zeroes" after it will check if its a valid MASTERCARD card or not.
    else if (credit_card_num >= 51e14 && credit_card_num < 56e14)
    {
        printf("MASTERCARD\n");
    }

    // Visa uses 13- and 16-digit numbers, so by having the starting number for VISA which is 4. and having 12 or 15 more "zeroes" after it will check if its a valid VISA card or not
    else if ((credit_card_num >= 4e12 && credit_card_num < 5e12) || (credit_card_num >= 4e15 && credit_card_num < 5e15))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

}