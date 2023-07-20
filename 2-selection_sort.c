#include "sort.h"
/**
 *  *  * swap_ints - Swap two integers in an array.
 *   *   * @a:  first integer to swap.
 *    *    * @b:  second integer to swap.
 *     */
void swap_ints(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 *  *  * selection_sort - Sort an array of integers in ascending order
 *   *   *                  using  selection sort algorithm.
 *    *    * @array: An array of integers.
 *     *     * @size: The size of array.
 *      *      *
 *       *       * Description: Prints array after each swap.
 *        */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, k;
	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (k = i + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;
		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
