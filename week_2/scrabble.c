#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    
    for (int k = 0, u = strlen(word1); k < u; k++)
    {
        word1[k] = toupper(word1[k]);
    }

    string word2 = get_string("Player 2: ");
    
    for (int k = 0, u = strlen(word2); k < u; k++)
    {
        word2[k] = toupper(word2[k]);
    }

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }


}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    char key = 65;
    int sum = 0;
    for (int i = 0, h = strlen(word); i < h; i++) 
    {
        word[i] = POINTS[word[i] - key];
        sum = sum + word[i];
    }

    return sum;
    



}
