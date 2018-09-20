//mergesort.c
//practice by acrux

#include <stdlib.h>
#include <assert.h>

#include "sort.h"

void merge(int *array, int *buff, int start_a, int start_b, int end)
{
	int left = start_a;
	int right = start_b;
	int index = start_a;

	while ((left <= start_b - 1) && (right <= end))
	{
		if (array[left] < array[right])
			buff[index++] = array[left++];
		else
			buff[index++] = array[right++];
	}

	while (left <= start_b - 1)
		buff[index++] = array[left++];
	while (right <= end)
		buff[index++] = array[right++];

	for (index = start_a; index <= end; index++)
	{
		array[index] = buff[index];
	}
}

void msort(int *array, int *buff, int start, int end)
{
	int middle;

	if (start >= end)
		return;

	middle = (start + end)/2;
	msort(array, buff, start, middle);
	msort(array, buff, middle + 1, end);
	merge(array, buff, start, middle + 1, end);
}

void merge_sort(int *array, int length)
{
	int middle = length/2;
	int *buff;

	buff = malloc(sizeof(int) * length);
	if (NULL == buff)
	{
		assert(0);
		return;
	}

	msort(array, buff, 0, length - 1);
}