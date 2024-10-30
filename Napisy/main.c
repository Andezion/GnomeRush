#include <stdio.h>

int custom_strlen(const char tab[])
{
    int counter = 0;

    for(; tab[counter] != '\0';)
    {
        counter++;
    }

    return counter;
}

int count_string(const char tab[], const char tab2[]);
int count_all_of(const char tab[], const char tab2[]);
int count(const char tab[], char c);

int main()
{
    printf("%i", count_string("To jest test", "jest"));
    return 0;
}

int count_all_of(const char tab[], const char tab2[])
{
    if(tab == NULL || tab2 == NULL)
    {
        return -1;
    }

    int counter = 0;



    return counter;
}

int count_string(const char tab[], const char tab2[])
{
    if(tab == NULL || tab2 == NULL)
    {
        return -1;
    }

    int counter = 0;

    int i = 0;
    int tab2_len = custom_strlen(tab2);

    while (tab[i] != '\0')
    {
        int j = 0;
        while (tab[i + j] != '\0' && tab2[j] != '\0' && tab[i + j] == tab2[j])
        {
            j++;
        }
        if (j == tab2_len)
        {
            counter++;
            i += tab2_len - 1;
        }
        i++;
    }

    return counter;
}

int count(const char tab[], char c)
{
    if(tab == NULL)
    {
        return -1;
    }

    int counter = 0;

    int i = 0;
    while(tab[i] != '\0')
    {
        if(tab[i] == c)
        {
            counter++;
        }
        i++;
    }

    return counter;
}