//test.c
//testcase for sort functions

#include <stdio.h>
//#define NDEBUG
#include <assert.h>

#include "sort.h"

#define DEBUG_ECHO_DATA

//echo_data: print array to console
void echo_data(int *array, int length)
{
	#ifdef DEBUG_ECHO_DATA
	int index;

	printf("\nEcho data:\n");
	for(index = 0; index < length; index++)
		printf("%d, ", array[index]);
	printf("\n");
	#endif
}

//compare_data: compare array_a and array_b, return 0 if same, or return 1
int compare_data(int *array_a, int *array_b, int length)
{
	for (int index = 0; index < length; index++)
	{
		if (array_a[index] != array_b[index])
			return 1;
	}

	return 0;
}

//test_sort: testcases for sort functions
void test_sort(void func(int*, int))
{
	int a[] = {10};
	int a_result[] = {10};
	func(a, 1);
	echo_data(a, 1);
	assert(0 == compare_data(a, a_result, 1));

	int b[] = {10, 8};
	int b_result[] = {8, 10};
	func(b, 2);
	echo_data(b, 2);
	assert(0 == compare_data(b, b_result, 2));

	int c[] = {10, 8, 9};
	int c_result[] = {8, 9, 10};
	func(c, 3);
	echo_data(c, 3);
	assert(0 == compare_data(c, c_result, 3));

	int d[] = {10, 7, 11, 8};
	int d_result[] = {7, 8, 10, 11};
	func(d, 4);
	echo_data(d, 4);
	assert(0 == compare_data(d, d_result, 4));

	int e[] = {10, 7, 11, 8, 10};
	int e_result[] = {7,  8, 10, 10, 11};
	func(e, 5);
	echo_data(e, 5);
	assert(0 == compare_data(e, e_result, 5));

}

//main: test for quicksort
int main(int argc, char **argv)
{
	//test_sort(quicksort);
	test_sort(merge_sort);

	return 0;
}