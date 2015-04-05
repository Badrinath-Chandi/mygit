/* C program for merge sort */
#include<stdlib.h>
#include<stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void buildMaxHeapify(int *arr, int s, int n,int f) {
	int l = 2 * s + 1;
	int r = 2 * s + 2;
	int mIndex = s;
	if (l<f && l<n && arr[l]>arr[mIndex])
		mIndex = l;
	if (r<f && r<n && arr[r]>arr[mIndex])
		mIndex = r;
	if (mIndex != s) {		
		swap(&arr[mIndex], &arr[s]);
		buildMaxHeapify(arr, mIndex, n,f);
	}
}
void buildMaxHeap(int *arr, int s, int n) {
	for (int i = n / 2; i >= 0; i--) {
		buildMaxHeapify(arr, i, n,n);
	}
}
void max_heapSort(int *arr, int s, int n) {
	buildMaxHeap(arr, s, n);
	for (int i = n ; i >=1; i--) {
		swap(&arr[i], &arr[0]);
		buildMaxHeapify(arr, 0, i-1,n);
	}
}
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
/* Driver program to test above functions */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7,4 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	//mergeSort(arr, 0, arr_size - 1);
	max_heapSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	getchar();
	return 0;
}