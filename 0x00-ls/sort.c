#include "mem.h"
#include "sort.h"

/**
 * quicksort_part - sort a partition in ascending order
 * @base: the array to sort
 * @size: the size of each item
 * @comp: the comparison function
 * @lower: lower bound of the partition (inclusive)
 * @upper: upper bound of the partition (inclusive)
 *
 * Return: index of the new partition
 */
static size_t quicksort_part(
	void *base, size_t size, comp_fn comp, ssize_t lower, ssize_t upper)
{
	void *comp_with = (char *) base + upper * size;
	void *swap_with = (char *) base + lower * size;
	void *element = swap_with;
	ssize_t index = lower;

	while (index < upper)
	{
		if (comp(element, comp_with) < 0)
		{
			if (lower != index)
			{
				_memswap(element, swap_with, size);
			}
			lower += 1;
			swap_with = (char *) swap_with + size; 

		}
		index += 1;
		element = (char *) element + size;
	}
	if (comp(swap_with, comp_with))
	{
		_memswap(swap_with, comp_with, size);
	}
	return (lower);
}

/**
 * quicksort - sort an array in ascending order
 * @base: the array to sort
 * @size: the size of each item
 * @comp: the comparison function
 * @lower: lower bound of the partition (inclusive)
 * @upper: upper bound of the partition (inclusive)
 */
static void quicksort(
	void *base, size_t size, comp_fn comp, ssize_t lower, ssize_t upper)
{
	ssize_t partition = 0;

	if (lower < upper)
	{
		partition = quicksort_part(base, size, comp, lower, upper);
		quicksort(base, size, comp, lower, partition - 1);
		quicksort(base, size, comp, partition + 1, upper);
	}
}

/**
 * sort - sort an array in ascending order
 * @base: the array to sort
 * @nmemb: the number of items
 * @size: the size of each item
 * @comp: the comparison function
 *
 * Description:
 * Sort an array with nmemb elements of size size. The base argument points to
 * the start of the array. The contents of the array are sorted in ascending
 * order according to a comparison function pointed to by comp, which is called
 * with two arguments that point to the objects being compared. The comparison
 * function must return an integer less than, equal to, or greater than zero if
 * the first argument is considered to be respectively less than, equal to, or
 * greater than the second. If two members compare as equal, their order in the
 * sorted array is undefined.
 */
void sort(void *base, size_t nmemb, size_t size, comp_fn comp)
{
	if (base && size && comp)
		quicksort(base, size, comp, 0, nmemb - 1);
}
