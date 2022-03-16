#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//get key from command line argument
int main(int argc, string argv[])
{
    //validate key
    if (argc != 2)
    {
        printf("Correct usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0,  n = strlen(argv[1]); i < n;  i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            return 1;
        }
    }
    
    //turn key into integer
    int keyplus = atoi(argv[1]);
    int keyminusupper = 65;
    int keyminuslower = 97;
    int sum = 0;

    //prompt for plaintext
    string plaintext = get_string("Plaintext: ");

    //preserve case for each character in plaintext string and shift plaintext character by key

    for (int j = 0, n = strlen(plaintext); j < n; j++)
    {
        if (isupper(plaintext[j]))
        {
            plaintext [j] = (plaintext[j] - keyminusupper + keyplus) % 26;
            plaintext [j] = plaintext[j] + keyminusupper;
        }
        else if (islower(plaintext[j]))
        {
            plaintext [j] = (plaintext[j] - keyminuslower + keyplus) % 26;
            plaintext [j] = plaintext[j] + keyminuslower;
        }
        
        //print ciphertext
        
    }
    printf("ciphertext: ");
    for (int i = 0, k = strlen(plaintext); i < k; i++)
    {
        printf("%c", plaintext[i]);

    }
    printf("\n");
}
















