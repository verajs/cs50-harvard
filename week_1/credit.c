#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    //Declaring variables used later in the program, including different versions of the same ccn
    long ccn = get_long("Number: ");
    int product = 0;
    int sum = 0;
    int ccnlen = 0;
    long ccn2 = ccn;
    long ccn3 = ccn;
    int ltwo = 0;

    //Create Luhn's algorithm loop
    while (ccn > 0)
    {
        sum += ccn % 10;
        ccn = ccn / 10;
        product = ccn % 10 * 2;
        //If the number is bigger than 2, then separate into two different numbers
        if (product > 9)
        {
            sum = product % 10 + sum;
            product = product / 10;
            sum =  product + sum;
        }
        //If the number is less than 2, directly add it to the variable sum
        else
        {
            sum = product + sum;
        }
        ccn = ccn / 10;
    }

    //Find out length of digits in the ccn
    do
    {
        ccn2 = ccn2 / 10;
        ccnlen++;
    }
    while (ccn2 != 0);

    //Get last two digits in the ccn
    while (ccn3 > 65)
    {
        ccn3 = ccn3 / 10;
    }

    //Figure out type of card using its length and also its starting numbers. Check if it's real by seeing if it satisfies the checksum
    if ((ccnlen == 15 && sum % 10 == 0) && (ccn3 == 34 || ccn3 == 37))
    {
        printf("AMEX\n");
    }
    else if ((ccnlen == 16 && sum % 10 == 0) && (ccn3 == 51 || ccn3 == 52 || ccn3 == 53 || ccn3 == 54 || ccn3 == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (((ccnlen == 13 || ccnlen == 16) && sum % 10 == 0) && (ccn3 / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}