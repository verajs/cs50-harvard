#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int words = 1;
    int letters = 0;
    int sentences = 0;

    //get input from user
    string text = get_string("Text: ");

    //count ammount of words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    
    //count ammount of letters
    for (int j = 0, h = strlen(text); j < h; j++)
    {
        if ((text[j] >= 65 && text[j] <= 90) || (text[j] >= 97 && text[j] <= 122))
        {
            letters++;
        }
    }

    //count ammount of sentences
    for (int k = 0, u = strlen(text); k < u; k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            sentences++;
        }
    }

    //make int L the average number of letters per 100 words in the text

    float laverage = (letters / (float)words) * 100;
    float saverage = (sentences / (float)words) * 100;

    float index = 0.0588 * laverage - 0.296 * saverage - 15.8;

    //print grade number of text
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}



