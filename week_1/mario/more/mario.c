#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    //Ask user for a number between 0 and 8 
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h <= 0 || h > 8);

    //Main loop
    for (int j = 1; j <= h; j++)
    {
        //Space printing loop
        for (int k = h - 1; k >= j; k--)
        {
            printf(" ");
        }
        //Asterisk printing loop
        for (int i = 0; i < j; i++)
        {
            printf("#");
        }
        //Make the space for the next row in the following pyramid
        printf("\n");
    }
}