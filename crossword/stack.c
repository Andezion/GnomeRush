#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct linked_list_t* ll_create()
{
    struct linked_list_t *stack = malloc(sizeof(struct linked_list_t));
    if(stack == NULL)
    {
        return NULL;
    }

    stack->head = NULL;
    stack->tail = NULL;

    return stack;
}

int ll_push_back(struct linked_list_t *ll, int value)
{
    if (ll != NULL)
    {
        struct node_t *part = malloc(sizeof(struct node_t));
        if (part != NULL)
        {
            part->data = value;

            int error = ll_is_empty(ll);
            if (error != 1)
            {
                part->next = NULL;

                ll->tail->next = part;
                ll->tail = part;
            }
            else
            {
                part->next = NULL;

                ll->head = part;
                ll->tail = part;
            }

            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}


int ll_push_front(struct linked_list_t *ll, int value)
{
    if (ll != NULL)
    {
        struct node_t *part = malloc(sizeof(struct node_t));
        if (part != NULL)
        {
            part->data = value;

            int error = ll_is_empty(ll);
            if (error != 1)
            {
                part->next = ll->head;

                ll->head = part;
            }
            else
            {
                part->next = NULL;

                ll->head = part;
                ll->tail = part;
            }

            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

void ll_clear(struct linked_list_t *ll)
{
    if(ll == NULL || ll->head == NULL || ll->tail == NULL)
    {
        return;
    }

    struct node_t *end;
    struct node_t *begin = ll->head;

    for(; begin != NULL;)
    {
        end = begin->next;

        free(begin);
        begin = end;
    }

    ll->tail = NULL;
    ll->head = NULL;
}

void ll_display(const struct linked_list_t *ll)
{
    if(ll == NULL)
    {
        return;
    }

    struct node_t *working_on_that;
    working_on_that = ll->head;

    for(; working_on_that;)
    {
        printf("%i ", working_on_that->data);
        working_on_that = working_on_that->next;
    }
}

int ll_is_empty(const struct linked_list_t *ll)
{
    if (ll != NULL)
    {
        if (ll->head == NULL)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

int ll_size(const struct linked_list_t *ll)
{
    if (ll != NULL)
    {
        int counter = 0;
        struct node_t *working_on_that;
        working_on_that = ll->head;

        for (; working_on_that;)
        {
            working_on_that = working_on_that->next;
            counter++;
        }

        return counter;
    }
    else
    {
        return -1;
    }
}


int ll_pop_front(struct linked_list_t *ll, int *err_code)
{
    if (ll != NULL)
    {
        if (ll_is_empty(ll) != 1)
        {
            int number;

            if (ll_size(ll) > 1)
            {
                struct node_t *part = ll->head;

                number = ll->head->data;
                ll->head = ll->head->next;

                free(part);
            }
            else
            {
                number = ll->head->data;
                free(ll->head);

                ll->head = NULL;
                ll->tail = NULL;
            }

            if (err_code)
            {
                *err_code = 0;
            }
            return number;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_remove(struct linked_list_t *ll, unsigned int index, int *err_code)
{
    if (ll != NULL && ll_is_empty(ll) != 1)
    {
        if ((int) index < ll_size(ll) && (int) index >= 0)
        {
            int number;
            if (index == 0)
            {
                return ll_pop_front(ll, err_code);
            }
            else if ((int) index != ll_size(ll) - 1)
            {
                struct node_t *helper;
                struct node_t *part = ll->head;

                for (int i = 1; i < (int) index; i++)
                {
                    part = part->next;
                }

                helper = part->next;
                number = helper->data;

                part->next = helper->next;

                if (err_code)
                {
                    *err_code = 0;
                }
                free(helper);
            }
            else
            {
                return ll_pop_back(ll, err_code);
            }

            if (err_code)
            {
                *err_code = 0;
            }
            return number;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_at(const struct linked_list_t *ll, unsigned int index, int *err_code)
{
    if (ll != NULL)
    {
        if ((int) index <= ll_size(ll))
        {
            unsigned int counter = 0;
            struct node_t *part = ll->head;

            for (; part;)
            {
                if (counter == index)
                {
                    if (err_code)
                    {
                        *err_code = 0;
                    }
                    return part->data;
                }
                part = part->next;

                counter = counter + 1;
            }

            return 0;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_pop_back(struct linked_list_t *ll, int *err_code)
{
    if (ll != NULL)
    {
        if (ll_is_empty(ll) != 1)
        {
            int number;

            if (ll_size(ll) > 1)
            {
                number = ll->tail->data;

                struct node_t *part = ll->head;
                for (; part->next->next;)
                {
                    part = part->next;
                }

                free(ll->tail);

                ll->tail = part;
                part->next = NULL;
            }
            else
            {
                number = ll->head->data;
                free(ll->head);

                ll->head = NULL;
                ll->tail = NULL;
            }

            if (err_code)
            {
                *err_code = 0;
            }
            return number;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_remove_sequence(struct linked_list_t *ll, const struct linked_list_t *ll_2)
{
    if (ll == NULL || ll_2 == NULL)
    {
        return -1;
    }
    const struct linked_list_t *stack = ll_2;

    int little_iterator = 0;
    int size_of_second = ll_size(stack);
    if(size_of_second == 0)
    {
        return 0;
    }

    int adder;
    int error_type_one;
    int error_type_two;
    int file_type_or_something_like_that;

    int i = 0;
    while (i < ll_size(ll))
    {
        if (ll_at(ll, i, NULL) != ll_at(stack, 0, NULL))
        {
            file_type_or_something_like_that = 1;
        }

        else
        {
            adder = 0;

            for (; ll_at(ll, i + adder, &error_type_one) == ll_at(stack, adder, &error_type_two);)
            {
                if (error_type_one != 0 || error_type_two != 0)
                {
                    break;
                }
                adder++;
            }
            if (adder != size_of_second)
            {
                file_type_or_something_like_that = 1;
            }
            else
            {
                for (int j = 0; j < adder; j++)
                {
                    ll_remove(ll, i, &error_type_one);
                }

                i = 0;

                file_type_or_something_like_that = 0;
                little_iterator++;
            }

        }

        if (file_type_or_something_like_that)
        {
            i++;
        }
    }

    if (pick == 0)
    {
        break;
    }
    else if (pick == 1)
    {

        printf("Enter: ");
        error = scanf("%i", &number);
        if (error != 1)
        {
            return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
        }

        error = dll_push_back(stack, number);
        if (error != 0)
        {
            return printf("Failed to allocate memory"), dll_clear(stack), free(stack), 8;
        }
    }
    else if (pick == 2)
    {

        error = dll_pop_back(stack, &err_code);
        if (err_code != 0)
        {
            printf("List is empty\n");
        }
        else
        {
            printf("%i\n", error);
        }
    }
    else if (pick == 3)
    {
        printf("Enter: ");
        error = scanf("%i", &number);
        if (error != 1)
        {
            return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
        }

        error = dll_push_front(stack, number);
        if (error != 0)
        {
            return printf("Failed to allocate memory"), dll_clear(stack), free(stack), 8;
        }
    }
    else if (pick == 4)
    {
        error = dll_pop_front(stack, &err_code);
        if (err_code != 0)
        {
            printf("List is empty\n");
        }
        else
        {
            printf("%i\n", error);
        }
    }
    else if (pick == 5)
    {
        printf("Enter: ");
        error = scanf("%i", &number);
        if (error != 1)
        {
            return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
        }

        printf("Enter: ");
        error = scanf("%u", &num);
        if (error != 1)
        {
            return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
        }

        error = dll_insert(stack, num, number);
        if (error == 1)
        {
            printf("Index out of range\n");
        }
        if (error == 2)
        {
            return printf("Failed to allocate memory"), dll_clear(stack), free(stack), 8;
        }
    }
    else if (pick == 6)
    {
        if (dll_is_empty(stack) != 1)
        {
            printf("Enter: ");

            error = scanf("%u", &num);
            if (error != 1)
            {
                return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
            }

            error = dll_remove(stack, num, &err_code);
            if (err_code == 0)
            {
                printf("%i\n", error);
            }
            else
            {
                printf("Index out of range\n");
            }
        }
        else
        {
            printf("List is empty\n");
        }
    }
    else if (pick == 7)
    {
        error = dll_back(stack, &err_code);
        if (err_code == 0)
        {
            printf("%i\n", error);
        }
        else
        {
            printf("List is empty\n");
        }
    }
    else if (pick == 8)
    {
        error = dll_front(stack, &err_code);
        if (err_code == 0)
        {
            printf("%i\n", error);
        }
        else
        {
            printf("List is empty\n");
        }
    }
    else if (pick == 9)
    {
        if (dll_is_empty(stack) != 1)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
    else if (pick == 10)
    {
        printf("%i\n", dll_size(stack));
    }
    else if (pick == 11)
    {
        dll_clear(stack);
    }
    else if (pick == 12)
    {
        if (dll_is_empty(stack) == 1)
        {
            printf("List is empty\n");
        }
        else
        {
            printf("Enter: ");
            error = scanf("%u", &num);

            if (error != 1)
            {
                return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
            }

            error = dll_at(stack, num, NULL);
            printf("%i\n", error);
        }
    }
    else if (pick == 13)
    {
        if (dll_is_empty(stack) != 1)
        {
            dll_display(stack);
            printf("\n");
        }
        else
        {
            printf("List is empty\n");
        }
    }
    else if (pick == 14)
    {
        if (dll_is_empty(stack) != 1)
        {
            dll_display_reverse(stack);
            printf("\n");
        }
        else
        {
            printf("List is empty\n");
        }
    }
    else
    {
        printf("Incorrect input data\n");
    }

    return little_iterator;
}