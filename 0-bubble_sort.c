#include "sort.h"
void exchange(int *, int, int);
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: list of an integer array elements
 * @size: size of an array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, l, flag = 0;

	if (array != NULL || size != 0)
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - 1;  j++)
			{
				if (array[j] > array[j + 1])
				{
					exchange(array, j, j + 1);
					flag = 1;
					for (l = 0; l < size - 1; l++)
					printf("%d, ", array[l]);
					printf("%d\n", array[size - 1]);
				}
			}
			if (flag == 0)
				break;
		}
	}
	else
		return;
}
/**
 * exchange - swap array elements
 * @array: list of integer array elements
 * @start_index: first index value
 * @next_index: next index
 */
void exchange(int *array, int start_index, int next_index)
{
	int temp;

	temp = array[start_index];
	array[start_index] = array[next_index];
	array[next_index] = temp;
}
