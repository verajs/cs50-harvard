#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? \n"); //asking user for input
    printf("Hello, %s\n", name); //using said input
    
}