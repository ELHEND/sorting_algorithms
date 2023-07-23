#include "sort.h"

void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);

/**
 *  * get_max - Get the maximum value in an array of integers.
 *   * @array: An array of integers.
 *    * @size: The size of the array.
 *     *
 *      * Return: maximum integer in the array.
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
 *  * radix_counting_sort - Sort the significant digits of an array of integers
 *   * in ascending order using the counting sort algorithm.
 *
 *    * @buff: A buffer to store the sorted array.
 *    * @array: An array of integers.
 *     * @size: The size of the array.
 *      * @sig:  significant digit to sort on.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t m;

	for (m = 0; m < size; m++)
		count[(array[m] / sig) % 10] += 1;

	for (m = 0; m < 10; m++)
		count[m] += count[m - 1];

	for (m = size - 1; (int)m >= 0; m--)
	{
		buff[count[(array[m] / sig) % 10] - 1] = array[m];
		count[(array[m] / sig) % 10] -= 1;
	}

	for (m = 0; m < size; m++)
		array[m] = buff[m];
}

/**
 *  * radix_sort - Sort an array of integers in ascending
 *   *              order using the radix sort algorithm.
 *    * @array: An array of integers.
 *     * @size: The size of the array.
 *      *
 *       * Description: Implements the LSD radix sort algorithm. Prints
 *        * the array after each significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
