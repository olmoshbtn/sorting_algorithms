#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 * sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, n, new_n;
	int swap;

	if (array == NULL || size < 2)
		return;

	n = size;
	while (n > 0)
	{
		new_n = 0;
		for (index = 0; index < n - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap = array[index];
				array[index] = array[index + 1];
				array[index + 1] = swap;
				new_n = index + 1;
				print_array(array, size);
			}
		}
		n = new_n;
	}
}
