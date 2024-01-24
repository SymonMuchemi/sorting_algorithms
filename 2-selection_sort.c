#include "sort.h"

/**
 * swap - switches the position of two array elements
 * @x: the first element
 * @y: the second element
 * Return: nothing
*/
void swap(int x, int y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
/**
 * selection_sort - use the selection sort algorithm to sort array
 * @array: pointer to the unsorted array
 * @size: the number of elements to be sorted
 * Return: nothing
*/

void selection_sort(int *array, size_t size)
{
	unsigned long int min, i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
