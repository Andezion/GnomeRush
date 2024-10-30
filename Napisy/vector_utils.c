#include "vector_utils.h"
#include <stdio.h>

int find(const int* tab, int size, int to_find)
{
    static int pointer = 0;
    static const int* temp_array = NULL;
    static int temp_size = 0;

    if (tab == NULL)
    {
        if (temp_array == NULL)
        {
            return -2;
        }
        tab = temp_array;
        size = temp_size;
    }
    else
    {
        if (size <= 0)
        {
            return -2;
        }
        temp_array = tab;
        temp_size = size;
        pointer = 0;
    }

    for (int i = pointer; i < size; ++i)
    {
        if (*(tab + i) == to_find)
        {
            pointer = i + 1;
            return i;
        }
    }

    pointer = 0;
    return -1;
}

