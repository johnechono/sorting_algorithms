#include <stdlib.h>
#include "sort.h"
/**
 * csort2 - the auxiliary function of radix sort
 * @array: the array of data to be sorted
 * @buff: the malloc buffer
 * @size: the size of data
 * @lsd: Lesser significant digits
 * Return: None
 */
void csort2(int *array, int **buff, int size, int lsd)
{
	int j, k, csize = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (j = 0; j < size; j++)
	{
		num = array[j];
		for (k = 0; k < lsd; k++)
			if (k > 0)
				num = num / 10;
		num = num % 10;
		buff[num][carr[num]] = array[j];
		carr[num] += 1;
	}

	for (j = 0, k = 0; j < csize; j++)
	{
		while (carr[j] > 0)
		{
			array[k] = buff[j][carr2[j]];
			carr2[j] += 1, carr[j] -= 1;
			k++;
		}
	}
	print_array(array, size);
}
/**
 * csort - the auxiliary function of radix sort
 * @array: the array of data to be sorted
 * @size: the size of data
 * @lsd: Lesser significant digits
 * Return: None
 */
void csort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int j, k, num, csize = 10, **buff;

	for (j = 0; j < size; j++)
	{
		num = array[j];
		for (k = 0; k < lsd; k++)
			if (k > 0)
				num = num / 10;
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (j = 0; j < csize; j++)
		if (carr[j] != 0)
			buff[j] = malloc(sizeof(int) * carr[j]);

	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (j = 0; j < csize; j++)
		if (carr[j] > 0)
			free(buff[j]);
	free(buff);
}
/**
 * radix_sort - will sorts an array of integers in
 * ascending order using the Radix sort algorithm
 * @array: the array of data to be sorted
 * @size: the size of data
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
