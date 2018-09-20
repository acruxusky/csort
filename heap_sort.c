//heapsort.c
//practice by acrux

#include "sort.h"

void down(int *heap, int key, int length)
{
	int leaf;
	int current = key;
	int key_value = heap[key];

	leaf = 2 * current + 1;
	while (leaf < length)
	{
		if ((leaf + 1 < length) && (heap[leaf] < heap[leaf + 1]))
			leaf++;

		if (heap[leaf] < key_value)
		{
			break;
		}

		heap[current] = heap[leaf];
		current = leaf;
		leaf = 2 * current + 1;
	}

	heap[current] = key_value;
}

void heap_sort(int *array, int length)
{
	int index;

	//构建最大堆
	for (index = (length/2 - 1); index >= 0; index--)
	{
		down(array, index, length);
	}

	//基于堆排序：每次将堆顶放到堆尾
	index = length - 1;
	while (index > 0)
	{
		int temp = array[0];
		array[0] = array[index];
		array[index] = temp;

		down(array, 0, index);
		index--;
	}
}