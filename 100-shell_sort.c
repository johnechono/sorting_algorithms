#include <stdio.h>
#include "sort.h"
/**
 * _swap - swapped two values.
 * @array: array for swapping values.
 * @i: the First index
 * @j: the Second index
 * Return: Nothing or 0
 */
void _swap(int *array, int i, int j)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * shell_sort - sorts the list and prints the changes
 * @array: array to be sorted
 * @size: the array size
 * Return: Nothing or 0
 */
void shell_sort(int *array, size_t size)
{
	size_t g = 0,  h, i;

	if (size < 2)
	{
		return;
	}

	while (g <= size / 3)
	{
		g = g * 3 + 1;
	}

	while (g >= 1)
	{
		for (h = g; h < size; h++)
			for (i = h; i >= g && array[i] < array[i - g]; i -= g)
				_swap(array, i, i - g);
		g /= 3;
		print_array(array, size);
	}
}
