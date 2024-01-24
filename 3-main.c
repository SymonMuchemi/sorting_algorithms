#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {0, 8, 58, 63, 84, 88, 115, 117, 127, 128, 136, 139, 141, 157, 163, 174, 188, 191, 193, 195};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
