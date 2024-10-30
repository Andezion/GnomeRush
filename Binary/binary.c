#include "binary.h"
#include <stdio.h>
#include <math.h>

void in_3(int num)
{
    char data[12];
    int index = 0;
    int n = 10;

    for (int i = 0; i < 11; i++)
    {
        data[i] = '0';
    }

    while(num > 0)
    {
        if(pow(3, n) > num)
        {
            n--;
            index++;
        }
        else
        {
            if(2 * pow(3, n) < num)
            {
                n--;
                data[index] = '2';
                num = num - (int)(2 * pow(3, n));
                index++;
            }
            else
            {
                n--;
                data[index] = '1';
                num = num - (int)pow(3, n);
                index++;
            }
        }
    }

    index = 12;

    data[index - 1] = '\0';

    printf("\n%s", data);
}

void in_2(int num)
{
    char data[12];
    int index = 0;
    int n = 10;

    for (int i = 0; i < 11; i++)
    {
        data[i] = '0';
    }

    while (num > 0)
    {
        if (pow(2, n) <= num)
        {
            num = num - (int)pow(2, n);
            data[index] = '1';
        }

        n--;
        index++;
    }
    if(index != 12)
    {
        index = 12;
    }

    data[index - 1] = '\0';

    printf("%s", data);
}