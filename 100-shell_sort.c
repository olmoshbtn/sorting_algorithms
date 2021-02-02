#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = 1;
	int val_insert;

	if (array == NULL || size < 2)
		return;
	
	while (interval < size/3)
	{
		interval = interval * 3 + 1; 
	}
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			val_insert = array[i];
			for (j = i; j >= interval && array[j - interval] > 
				val_insert; j = j - interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = val_insert;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
	
	
}
