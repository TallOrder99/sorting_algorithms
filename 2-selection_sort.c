#include "sort.h"

/**
 * selection_sort - This function sorts an array of integers.
 * @array: The array that is ordered.
 * @size: The size of the array.
 *
 * Return: Nothing.
 **/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int container = 0, min = 0, m = 0;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j <= (size - 1); j++)
	{
		for (i = j + 1, min = j, m = 0; i < size; i++)
		{
			if (array[min] > array[i])
			{
				min = i;
				m++;
			}
		}
		if (m != 0)
		{
			container = array[j];
			array[j] =  array[min];
			array[min] = container;
			print_array(array, size);
		}
	}
}
