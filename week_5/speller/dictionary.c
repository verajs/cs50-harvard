// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int dictsize = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word to obtain the value in the table
    int hashvalue = hash(word);

    // Assign cursor based on place in hashtable
    node *n = table[hashvalue];

    // While the node hasn't reached the end of the list yet
    while (n != NULL)
    {
        // Compare the word the function was given to each word in the linked list
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        // If it isn't found, go to the next node of the linked list
        else
        {
            n = n->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // Initializing with long because the bucket size is huge
    long sum = 0;

    /*
    Adding the ASCII values of the word so that we get a result that is
    random enough to not get repeated across words but also deterministic.
    (I came up with it with a bit of guidance on the internet what makes a good hash function)
    */
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }

    // We modulo the sum result to get a place in the hash table
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Read strings from file one at a time
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            return false;
        }
        strcpy(newnode->word, word);
        // Hash word to obtain a hash value
        int hashvalue = hash(word);
        // Insert node into hash table at that location
        newnode->next = table[hashvalue];
        table[hashvalue] = newnode;
        dictsize++;
    }

//Close file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictsize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
