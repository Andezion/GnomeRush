#include <stdlib.h>
#include "my_string.h"

char *my_strdup(const char * sTekst) //strdup
{
    if(sTekst == NULL)
    {
        return NULL;
    }

    size_t size = my_strlen(sTekst);
    char *result = malloc(sizeof(char) * (size + 1));
    if(result == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < size; i++)
    {
        *(result + i) = *(sTekst + i);
    }
    result[size] = '\0';

    return result;
}


char *my_strrchr(const char * str, int ch) // strrchr
{
    int size = my_strlen(str);
    while (size >= 0)
    {
        if (*(str + size) == ch)
        {
            return (char *)(str + size);
        }
        size--;
    }
    return NULL;
}

char *my_strchr(const char *str, int z) //strchr
{
    while (*str != '\0')
    {
        if (*str == z)
        {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *my_strncpy(char *where, const char *from, size_t number) //strncpy
{
    if(from == NULL || number <= 0)
    {
        return NULL;
    }

    size_t size1 = my_strlen(from);
    if(size1 < number)
    {
        return NULL;
    }

    int i;
    for(i = 0; i < number; i++)
    {
        *(where + i) = *(from + i);
    }
    *(where + i) = '\0';

    return where;
}

char *my_strcpy (char *where, const char *from) //strcpy
{
    if(from == NULL)
    {
        return NULL;
    }

    size_t size1 = my_strlen(from);

    int i;
    for(i = 0; i < size1; i++)
    {
        *(where + i) = *(from + i);
    }
    *(where + i) = '\0';

    return where;
}

int my_strlen(const char *word) //strlen
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

char *my_strncat(char *word1, char *word2, size_t size)// strncat
{
    if(word1 == NULL || word2 == NULL)
    {
        return NULL;
    }
    char *result = word1 + my_strlen(word1);

    while(*word2 != '\0' && size--)
    {
        *word1 = *word2;
        word1++;
        word2++;
    }
    *result = '\0';

    return word1;
}

char *my_strcat(char *word1, char *word2) //strcat
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

int my_strncmp(const char *word1, const char *word2, size_t counter) // strncmp
{
    if(word1 == NULL || word2 == NULL || counter <= 0)
    {
        return 1;
    }

    size_t size1 = my_strlen(word1);
    size_t size2 = my_strlen(word2);

    if(counter > size1 || counter > size2)
    {
        return 1;
    }

    for(size_t i = 0; i < counter; i++)
    {
        if(word1[i] != word2[i])
        {
            return 1;
        }
    }

    return 0;
}

int my_strcmp(const char *word1, const char *word2) // strcmp
{
    if(word1 == NULL || word2 == NULL)
    {
        return 1;
    }

    size_t size1 = my_strlen(word1);
    size_t size2 = my_strlen(word2);

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

    for(size_t i = 0; i < my_strlen(word1); i++)
    {
        if(word1[i] != word2[i])
        {
            return 1;
        }
    }

    return 0;
}