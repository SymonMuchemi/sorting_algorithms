#include "sort.h"

/**
 * partition - partitions the array to small subarrays
 * @array: the array
 * @upper: the upper bound of the array
 * @lower: the lower bound of the array
 * @size: the length of the array
 * Return: the last index of the first subarray
*/

int partition(int *array, int lower, int upper, size_t size)
{
	int pivot, start, end, temp;

	pivot = array[lower];
	start = lower;
	end = upper;
	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}
	}

	temp = array[lower];
	array[lower] = array[end];
	array[end] = temp;

	print_array(array, size);
	return (end);
}
/**
 * quick_sort_recursive - implements the quick sort algorithm on an @array
 * @array: the list of elements
 * @upper: the upper bound of the array
 * @lower: the lower bound of the array
 * @size: the number of elements in the array
 * Return: nothing
*/

void quick_sort_recursive(int *array, int lower, int upper, size_t size)
{
	int location;

	if (lower < upper)
	{
		location = partition(array, lower, upper, size);
		quick_sort_recursive(array, lower, (location - 1), size);
		quick_sort_recursive(array, (location + 1), upper, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm
 * @array: pointer to the unsorted array
 * @size: the number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (size - 1), size);
}
