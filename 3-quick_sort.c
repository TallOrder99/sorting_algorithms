#include "sort.h"

/**
 * quick_sort - This function sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: The array that is ordered.
 * @size: The size of the array.
 *
 * Return: Nothing.
 **/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}
	quicksort_recursion(array, size, 0, size - 1);
}

/**
 * quicksort_recursion - This function receives lomuto index and
 * from there it applies the right and left recursion.
 * @array: The array that is ordered.
 * @size: The size of the array.
 * @first: The low index of the sort.
 * @last: The high index of the sort.
 *
 * Return: Nothing.
 **/
void quicksort_recursion(int *array, size_t size, ssize_t first, ssize_t last)
{
	size_t pivot;

	if (first < last)
	{
		pivot = partition(array, size, first, last);

		quicksort_recursion(array, size, first, pivot - 1);
		quicksort_recursion(array, size, pivot + 1, last);
	}
}

/**
 * partition - This function split the array.
 * @array: The array that is ordered.
 * @size: The size of the array.
 * @first: The low index of the sort.
 * @last: The high index of the sort.
 *
 * Return: The index in common.
 **/
size_t partition(int *array, size_t size, ssize_t first, ssize_t last)
{
	int pivot = array[last], i = (first - 1), j;

	for (j = first; j < last; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, size, &array[j], &array[i]);
		}
	}
	swap(array, size, &array[i + 1], &array[last]);

	return (i + 1);
}

/**
 * swap - This function swap both values.
 * @array: The array that is ordered.
 * @size: The size of the array.
 * @value1: The first value
 * @value2: The second value.
 *
 * Return: Nothing.
 **/
void swap(int *array, size_t size, int *value1, int *value2)
{
	int container;

	if (*value1 != *value2)
	{
		container = *value1;
		*value1 = *value2;
		*value2 = container;
		print_array(array, size);
	}
}
