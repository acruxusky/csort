//quicksort.c
//practice by acrux

#include "sort.h"

//swap: exchange data for index left and right of the array
void swap(int *array, int left, int right)
{
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

//get_pivot_index: get index of pivot, using the center position now
int get_pivot_index(int *array, int left, int right)
{
	return (left + right)/2;
}

//qsort: sort the array from start to end
void qsort(int *array, int start, int end)
{
	int ileft = start;
	int iright = end;
	int ipivot;
	int pivot;

	if (start >= end)
		return;

	ipivot = get_pivot_index(array, start, end);
	pivot = array[ipivot];
	swap(array, start, ipivot);
	while (ileft < iright)
	{
		while ((ileft < iright) && (array[iright] > pivot))
			iright--;
		while ((ileft < iright) && (array[ileft] <= pivot))
			ileft++;

		if (ileft < iright)
			swap(array, ileft, iright);
	}

	swap(array, start, ileft);
	qsort(array, start, ileft - 1);
	qsort(array, ileft + 1, end);
}

//quicksort: api for quicksort
void quicksort(int *array, int length)
{
	qsort(array, 0, length - 1);
}