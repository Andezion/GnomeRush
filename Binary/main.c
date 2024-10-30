#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void* sum(const void * const ptr, int size);

int main()
{

    return 0;
}

void* sum(const void * const ptr, int size)
{
    if (ptr == NULL || size < 1)
    {
        return NULL;
    }

    int counter = 0;
    double storage_for_sum = 0.0;
    const uint8_t *pointer_on_pointer = (const uint8_t *) ptr;

    for (; counter < size;)
    {
        uint8_t take_number = *(pointer_on_pointer + counter++);
        uint8_t type_of_number = take_number >> 4;
        uint8_t how_much_numbers = take_number & 0x0F;

        for (int i = 0; i < how_much_numbers; i++)
        {
            if (type_of_number == 0)
            {
                storage_for_sum = storage_for_sum + (double)((int8_t)pointer_on_pointer[counter]);
                counter = counter + sizeof(int8_t);
            }
            else if (type_of_number == 1)
            {
                storage_for_sum = storage_for_sum + (double)pointer_on_pointer[counter];
                counter = counter + sizeof(uint8_t);
            }
            else if (type_of_number == 2)
            {
                int32_t value = (pointer_on_pointer[counter] << 24) |
                                (pointer_on_pointer[counter + 1] << 16) |
                                (pointer_on_pointer[counter + 2] << 8) |
                                pointer_on_pointer[counter + 3];

                storage_for_sum = storage_for_sum + (double)value;
                counter = counter + sizeof(int32_t);
            }
            else if (type_of_number == 3)
            {

                uint32_t value = ((uint32_t)pointer_on_pointer[counter] << 24) |
                                 ((uint32_t)pointer_on_pointer[counter + 1] << 16) |
                                 ((uint32_t)pointer_on_pointer[counter + 2] << 8) |
                                 pointer_on_pointer[counter + 3];

                storage_for_sum = storage_for_sum + (double)value;
                counter = counter + sizeof(uint32_t);
            }
            else if (type_of_number == 4)
            {
                float value;
                memcpy(&value, &pointer_on_pointer[counter], sizeof(float));

                storage_for_sum = storage_for_sum + (double)value;
                counter = counter + sizeof(float);
            }
            else if (type_of_number == 5)
            {
                double value;
                memcpy(&value, &pointer_on_pointer[counter], sizeof(double));

                storage_for_sum = storage_for_sum + value;
                counter = counter + sizeof(double);
            }
            else
            {
                return NULL;  // хуйня
            }
        }
    }

    double *returning_void = (double *)malloc(sizeof(double));
    if (returning_void == NULL)
    {
        return NULL;
    }

    *returning_void = storage_for_sum;
    return returning_void;
}

