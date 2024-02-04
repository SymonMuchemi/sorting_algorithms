#include "sort.h"

/**
 * merge - joins subarrays correctly with elements in ascending
 * order
 * @arr: the array
 * @lb: the subarray lower bound
 * @ub: the subarray upper bound
 * @mid: the subarrays middle index
 * Return: nothing
*/
void merge(int *arr, int lb, int mid, int ub)
{
	int i = lb, j = mid, k = lb;
	int *tempArray = malloc(sizeof(arr) * (ub - lb + 1));

	if (tempArray == NULL)
		return;

	while (i < mid && j <= ub)
	{
		if (arr[i] <= arr[j])
		{
			tempArray[k] = arr[i];
			i++;
		}
		else
		{
			tempArray[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		tempArray[k] = arr[i];
		i++;
		k++;
	}

	while (j <= ub)
	{
		tempArray[k] = arr[j];
		j++;
		k++;
	}

	for (k = lb; k <= ub; k++)
		arr[k] = tempArray[k];

	free(tempArray);
}
/**
 * mergesort - uses the divide and conquer approach to sort
 * an array
 * @arr: the array to be sorted
 * @lb: the lower bound
 * @ub: the upper bound
 * Return: nothing
*/
void mergesort(int *arr, int lb, int ub)
{
	int mid;

	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		mergesort(arr, lb, mid);
		mergesort(arr, mid + 1, ub);
		merge(arr, lb, mid, ub);
	}
}

/**
 * merge_sort - the main mergesort function
 * @array: pointer to an array
 * @size: the number of elements to be sorted
 * Return: nothing
*/
void merge_sort(int *array, size_t size)
{
	int ub = (int)size - 1;

	mergesort(array, 0, ub);
}
