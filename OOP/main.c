#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tester.h"

size_t my_strlen(const char *word)
{
    if(word == NULL)
    {
        return 0;
    }

    int size = 0;

    while(word[size] != '\0')
    {
        size++;
    }

    return size;
}

int my_strcmp(const char *word1, const char *word2)
{
    if(word1 == NULL || word2 == NULL)
    {
        return 2;
    }

    int size1 = my_strlen(word1);
    int size2 = my_strlen(word2);

    if(size1 != size2)
    {
        if(my_strlen(word1) < my_strlen(word2))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    for(int i = 0; i < my_strlen(word1); i++)
    {
        if(word1[i] != word2[i])
        {
            return 2;
        }
    }

    return 0;
}

char *my_strcat(char *word1, char *word2)
{
    if(word1 == NULL || word2 == NULL)
    {
        return NULL;
    }

    int size = my_strlen(word1) + my_strlen(word2) + 1;
    char *result = malloc(sizeof(char) * size);
    if(result == NULL)
    {
        return NULL;
    }

    size_t i, j = 0;
    for (i = 0; i < size; i++)
    {
        if (i < my_strlen(word1))
        {
            result[i] = word1[i];
        }
        else
        {
            result[i] = word2[j];
            j++;
        }
    }
    result[size - 1] = '\0';

    return result;
}


int main()
{
    char *word1 = malloc(sizeof(char) * 1000);
    printf("Enter word1: ");
    if (gets(word1) == NULL)
    {
        printf("Incorrect input!");
        free(word1);
        return 666;
    }

    printf("\n");

    char *word2 = malloc(sizeof(char) * 1000);
    printf("Enter word2: ");
    if (gets(word2) == NULL)
    {
        printf("Incorrect input!");
        free(word1);
        free(word2);
        return 666;
    }

    printf("\nYour text is: %s\n", my_strcat(word1, word2));

    strlen_checker();
    strcmp_checker();
    strcat_checker();

    //I've tried to compare my funk and strcat(), but it was hard and I failed to do it :)

    return 0;
}
