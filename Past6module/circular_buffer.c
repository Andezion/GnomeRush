#include "circular_buffer.h"
#include <stdlib.h>
#include <stdio.h>

int circular_buffer_create(struct circular_buffer_t *cb, int N)
{
    if(cb == NULL || N <= 0)
    {
        return 1;
    }

    cb->ptr = malloc(sizeof(int) * N);
    if(cb->ptr == NULL)
    {
        return 2;
    }

    cb->capacity = N;
    cb->full = 0;
    cb->begin = 0;
    cb->end = 0;

    return 0;
}

int circular_buffer_create_struct(struct circular_buffer_t **cb, int N)
{
    if(cb == NULL || N <= 0)
    {
        return 1;
    }

    struct circular_buffer_t *a = malloc(sizeof(struct circular_buffer_t));
    if(a == NULL)
    {
        return 2;
    }

    int error = circular_buffer_create(a, N);
    if(error == 2)
    {
        free(a);
        return 2;
    }

    *cb = a;
    return 0;
}

void circular_buffer_destroy(struct circular_buffer_t *cb)
{
    if(cb == NULL)
    {
        return;
    }

    free(cb->ptr);
}

void circular_buffer_destroy_struct(struct circular_buffer_t **cb)
{
    if(cb == NULL || *cb == NULL)
    {
        return;
    }

    circular_buffer_destroy(*cb);
    free(*cb);
}

int circular_buffer_push_back(struct circular_buffer_t *cb, int value)
{
    if(cb == NULL || cb->ptr == NULL || cb->end >= cb->capacity || cb->full > 1 || cb->capacity < 1
    || cb->begin >= cb->capacity || cb->begin < 0 || cb->end < 0)
    {
        return 1;
    }

    if (cb->full == 1)
    {
        int temp = (cb->begin + 1) % cb->capacity;
        cb->begin = temp;
    }

    *(cb->ptr + cb->end) = value;
    cb->end = (cb->end + 1) % cb->capacity;
    if (cb->end == cb->begin)
    {
        cb->full = 1;
    }

    return 0;
}

int circular_buffer_pop_front(struct circular_buffer_t *cb, int *err_code)
{
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0 || cb->end < 0 || cb->begin < 0
    || cb->begin >= cb->capacity || cb->full > 1 || cb->end >= cb->capacity)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return -1;
    }

    if(circular_buffer_empty(cb) == 0)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return -1;
    }

    int temp = *(cb->ptr + cb->begin);
    if(cb->begin == cb->capacity)
    {
        cb->begin = 0;
    }

    cb->begin++;
    cb->full = 0;

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return temp;
}

int circular_buffer_pop_back(struct circular_buffer_t *cb, int *err_code)
{
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0 || cb->end <= 0 || cb->end > cb->capacity)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return -1;
    }

    if(circular_buffer_empty(cb) == 0)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return -1;
    }



    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return 0;
}

int circular_buffer_empty(const struct circular_buffer_t *cb)
{
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0 || cb->end <= 0 || cb->end > cb->capacity)
    {
        return -1;
    }

    if(cb->end == 0 && cb->full != 1)
    {
        return 1;
    }

    return 0;
}

int circular_buffer_full(const struct circular_buffer_t *cb)
{
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0 || cb->end <= 0 || cb->end > cb->capacity)
    {
        return -1;
    }

    if(cb->end == cb->capacity && cb->full == 1)
    {
        return 1;
    }

    return 0;
}

void circular_buffer_display(const struct circular_buffer_t *a)
{
    if(a == NULL)
    {
        return;
    }
    for(int i = 0; i < a->end; i++)
    {
        printf("%i ",*(a->ptr + i));
    }
    printf("\n");
}