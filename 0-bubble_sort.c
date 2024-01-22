#include "sort.h"

/**
 * bubble_sort - arranges array elements using bubble sort
 * algorithm
 * @array: pointer to an integer array
 * @size: the number of elements to be sorted
 * Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	int i, j, n, temp;
	bool swapped;

	n = size;

	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < (n - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, n);
			}
		}
		if (swapped == false)
			break;
	}
}
