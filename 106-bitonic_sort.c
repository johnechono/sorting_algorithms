#include <stdio.h>
#include "sort.h"
/**
 * swap - change two values in ascending or descending order
 * @arr: the array
 * @item1: the item one
 * @item2: the item two
 * @order: 1 is ascending order, 0 is descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int tmp;

	if (order == (arr[item1] > arr[item2]))
	{
		tmp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = tmp;
	}
}
/**
 * merge - sort bitonic sequences recursively in both order
 * @arr: the array
 * @low: the first element
 * @nelemnt: the elements number
 * @order: 1 is ascending order, 0 is descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, j;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (j = low; j < low + mid; j++)
			swap(arr, j, j + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sorting algorithm implementation
 * @arr: the array
 * @low: the first element
 * @nelemnt: the number of elements
 * @order: 1 is ascending order, 0 is descending order
 * @size: the array length
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - will prepare the terrain to bitonic sort algorithm
 * @array: the array
 * @size: the array length
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
	{
		return;
	}
	bitonicsort(array, 0, size, order, size);
}
