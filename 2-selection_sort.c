#include "stdio.h"
#include "sort.h"

/**
 * permut - permute les valeur de a et b
 * @a: premier entier
 * @b: deuxième entier
 * Return: Void
 */
void permut(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - sorts array of int in asc order using the Selection sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min;

	for (i = 0; i < size; i++)
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
			permut(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
