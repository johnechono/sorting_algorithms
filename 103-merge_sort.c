#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * copy - will copy data from one buff to another
 * @src: the source buffer
 * @dst: the destination buffer
 * @size: the size of buffers
 * Return: None
 */
void copy(int *src, int *dst, int size)
{
	int j;

	for (j = 0; j < size; j++)
		dst[j] = src[j];
}
/**
 * merge - merges two sets of data in ascending order
 * but they must already be sorted before time
 * @array: the first set of data
 * @buff: the second set of data
 * @minL: the lower range of first set of data
 * @maxL: the upper range of first set of data
 * @minR: the lower range of second set of data
 * @maxR: the upper range of second set of data
 * Return: None
 */
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)

		if (i <= maxL && j <= maxR)
			if (buff[i] <= buff[j])
				array[k] = buff[i], k++, i++;
			else
				array[k] = buff[j], k++, j++;

		else if (i > maxL && j <= maxR)
			array[k] = buff[j], k++, j++;
		else
			array[k] = buff[i], k++, i++;
}
/**
 * printcheck - will print an array in a given range
 * @array: the array of data to be printed
 * @r1: the start of  the range
 * @r2: the end of the range
 * Return: None
 */
void printcheck(int *array, int r1, int r2)
{
	int j;

	for (j = r1; j <= r2; j++)
	{
		if (j > r1)
			printf(", ");
		printf("%d", array[j]);
	}
	printf("\n");
}
/**
 * split - recursive fnctn to split data into merge tree
 * @array: the array of data to be splitted
 * @buff: the auxiliary array of data for merging
 * @min: the minimum range of data in array
 * @max: the maximum range of data in array
 * @size: the total size of the data
 * Return: None
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}
/**
 * merge_sort - sorts the array of integers in ascending order
 * using the merge sort algorithm
 * @array: the array of data to be sorted
 * @size:  data size
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (size < 2)
	{
		return;
	}
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
	{
		return;
	}

	copy(array, buffer, size);

	split(array, buffer, 0, size - 1, size);

	free(buffer);
}
