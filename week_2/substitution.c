#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    //Prepare for user entering other than 2 argument counts
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Prepare for user entering other than 26 characters
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Prepare for user not entering numbers.
    for (int i = 0,  n = strlen(key); i < n;  i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    //Use bool values to check for duplicates    
    bool bool_abc[26] = {0};

    for (int i = 0; i < strlen(key); i++) 
    {
        char x = toupper(key[i]);
        if (bool_abc[x - 65] == false)
        {
            bool_abc[x - 65] = true;
        }
        else
        {
            return 1;
        }
    }

    //prompt user for key
    string plaintext = get_string("plaintext: ");

    //encrypting algorithm
    for (int i = 0, h = strlen(plaintext); i < h; i++)
    {
        //sepparate uppercase and lowercase characters
        if (isupper(plaintext[i]))
        {
            char c = key[plaintext[i] - 65];
            c = toupper(c);
            plaintext[i] = c;
        }
        else if (islower(plaintext[i]))
        {
            char c = key[plaintext[i] - 97];
            c = tolower(c);
            plaintext[i] = c;
        }
    }

    //printing ciphertext
    string ciphertext = plaintext;
    printf("ciphertext: %s\n", ciphertext);
}