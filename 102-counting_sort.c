#include "sort.h"

/**
 *  * get_max - Get the maximum value in an array of integers.
 *   * @array: array of integers.
 *    * @size: size of the array.
 *     * Return:  maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int max, m;

	for (max = array[0], m = 1; m < size; m++)
	{
		if (array[m] > max)
			max = array[m];
	}

	return (max);
}

/**
 *  * counting_sort - Sort an array of integers in ascending order
 *   *                 using the counting sort algorithm.
 *    * @array: array of integers.
 *     * @size:  size of the array.
 *      *
 *       * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, m;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (m = 0; m < (max + 1); m++)
		count[m] = 0;
	for (m = 0; m < (int)size; m++)
		count[array[m]] += 1;
	for (m = 0; m < (max + 1); m++)
		count[m] += count[m - 1];
	print_array(count, max + 1);

	for (m = 0; m < (int)size; m++)
	{
		sorted[count[array[m]] - 1] = arra[m];
		count[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = sorted[m];

	free(sorted);
	free(count);
}
