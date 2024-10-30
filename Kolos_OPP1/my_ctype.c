#include "my_ctype.h"

int my_tolower(int ch)
{
    if(ch >= 'A' && ch <= 'Z')
    {
        return ch + ('a' - 'A');
    }
    return ch;
}

int my_toupper(int ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        return ch - ('a' - 'A');
    }
    return ch;
}

int my_isdigit(int ch)
{
    if(ch >= '0' && '9' >= ch)
    {
        return 1;
    }
    return 0;
}

int my_islower(int ch)
{
    if(ch >= 97 && 122 >= ch)
    {
        return 1;
    }
    return 0;
}

int my_isupper(int ch)
{
    if(ch >= 65 && 90 >= ch)
    {
        return 1;
    }
    return 0;
}

int my_isalpha(int ch)
{
    if((ch >= 65 && 90 >= ch) || (ch >= 97 && 122 >= ch))
    {
        return 1;
    }
    return 0;
}

int my_isalnum(int ch)
{
    if((ch >= 65 && 90 >= ch) || (ch >= 97 && 122 >= ch) || (ch >= '0' && '9' >= ch))
    {
        return 1;
    }
    return 0;
}
