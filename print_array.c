#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - will print an array of integers
 * @array: array to be printed
 * @size: the number of elements in the array
 */
void print_array(const int *array, size_t size)
{
    size_t j;

    j = 0;
    while (array && j < size)
    {
        if (j > 0)
	{
		printf(", ");
	}
        printf("%d", array[j]);
        ++j;
    }
    printf("\n");
}
