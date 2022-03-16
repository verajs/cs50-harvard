#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float owed;
    do
    {
        
        owed = get_float("Change owed: "); //asks for total ammount of change owed
    
    }
    while (owed < 0);        
    
    int cents = round(owed * 100); //converting dollars to cents and rounding to nearest penny
    
    int coins = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5; 
    int penny = 1;
    
    
    
    while (cents >= 25) //using quarters until no longer able to
    {
        cents = cents - quarter;
        coins++; //keeping track of coins used 
    }
    

    
    while (cents >= 10) //using dimes until no longer able to
    {
        cents = cents - dime;
        coins++;
    }
    
 

    
    while (cents >= 5) //using nickel until no longer able to
    {
        cents = cents - nickel;
        coins++;
    }
    
  
    
    while (cents >= 1) //using penny until no longer able to
    {
        cents = cents - penny;
        coins++;
    }
    

    
    printf("%i\n", coins); 
}