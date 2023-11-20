#include "sort.h"

/**
 * swap - swap two elements in an array
 * @array: the array to sort
 * @j: address of the first value
 * @v: address of the second value
 * @size: arry siz
 */
void swap(int *array, size_t size, int *j, int *v)
{
	if (*j != *v)
	{
		*j = *j ^ *v;
		*v = *j ^ *v;
		*j = *j ^ *v;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - scheme for Quick sort
 * @array: array to sort
 * @size: array size
 * @lo: lowest index
 * @hi: highest index
 * Return: partition index
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int x, y, pivot = array[hi];

	for (x = y = lo; y < hi; y++)
	{
		if (array[y] < pivot)
		{
			swap(array, size, &array[y], &array[x]);
			x++;
		}
	}
	swap(array, size, &array[x], &array[hi]);

	return (x);
}

/**
 * quicksort_recursive - recursive function to perform Quick sort
 * @array: array of integers to be sorted
 * @lo: starting index of the partition
 * @hi: ending index of the partition
 * @size: amount of elments in array
 */
void quicksort_recursive(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	if (lo < hi)
	{
		ssize_t pi = lomuto_partition(array, size, lo, hi);

		quicksort_recursive(array, lo, pi - 1, size);
		quicksort_recursive(array, pi + 1, hi, size);
	}
}
/**
 * quick_sort - quickly sort arrays
 * @array: the array
 * @size: the size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}
