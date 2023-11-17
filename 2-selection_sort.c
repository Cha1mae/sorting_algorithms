#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selection sort
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, c;
	int tmp;

	if (!array || !size)
		return;

	for (a = 0; a < size - 1; a++)
	{
		c = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] > array[c])
			{
				c = b;
			}
		}

		if (c != a)
		{
			tmp = array[a];
			array[a] = array[c];
			array[c] = tmp;
			print_array(array, size);
		}
	}
}
