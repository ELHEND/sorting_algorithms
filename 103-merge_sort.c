#include "sort.h"
void merge_sort(int *array, size_t size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);

/**
 *  * merge_subarr - Sort a subarray of integers.
 *   * @subarr: A subarray of an array of integers to sort.
 *    * @buff: A buffer to store the sorted subarray.
 *     * @front: The front index of the array.
 *      * @mid: The middle index of the array.
 *       * @back: The back index of the array.
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t m, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (m = front, j = mid; m < mid && j < back; k++)
		buff[k] = (subarr[m] < subarr[j]) ? subarr[m++] : subarr[j++];
	for (; m < mid; m++)
		buff[k++] = subarr[m];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (m = front, k = 0; m < back; m++)
		subarr[m] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 *  * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 *   * @subarr: A subarray of an array of integers to sort.
 *    * @buff: A buffer to store the sorted result.
 *   * @back: The back index of the subarray.
 *     * @front: The front index of the subarray.
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 *  * merge_sort - Sort an array of integers in ascending
 *   *              order using the merge sort algorithm.
 *    * @array:array of integers.
 *     * @size:  size of the array.
 *      *
 *       * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
