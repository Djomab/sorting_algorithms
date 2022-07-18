#include "stdio.h"
#include "sort.h"

/**
 * permuter - permute les valeur de a et b
 * @a: premier entier
 * @b: deuxième entier
 * Return: Void
 */
void permuter(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * _split - splits the array and takes the last element as pivot
 * @arr: input array
 * @min: first element
 * @last: The last element
 * @size: size
 * Return: integer
 */
int _split(int *arr, int min, int last, size_t size)
{
	int piv;
	int i = (min);
	int j;

	piv = arr[last];
	for (j = min; j < last; j++)
	{
		if (arr[j] <= piv)
		{
			permuter(&arr[i], &arr[j]);

			if (i != j)
				print_array(arr, size);

			i++;
		}
	}

	permuter(&arr[i], &arr[last]);
	if (i != j)
	{
		print_array(arr, size);
	}
	return (i);
}

/**
 * quick_sort_array - quick_sort_array
 * @arr: arr
 * @min: min
 * @last: last
 * @size: size
 */
void quick_sort_array(int *arr, int min, int last, size_t size)
{
	int piv;

	if (min < last)
	{
		piv = _split(arr, min, last, size);
		quick_sort_array(arr, min, (piv - 1), size);
		quick_sort_array(arr, (piv + 1), last, size);
	}
}

/**
 * quick_sort - sorts array of int in asc order using the Quick sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quick_sort_array(array, 0, size - 1, size);
}
