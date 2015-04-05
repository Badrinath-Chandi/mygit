/* A typical recursive implementation of quick sort */
#include<stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int getPartition(int *arr, int l, int n) {
	int pivot = arr[n];
	int i = l - 1;
	for (int j = l; j <= n - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[n]);
	return i + 1;
}
void quickSort(int* arr, int l, int n) {
	if (l < n) {
		int p = getPartition(arr, l, n);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, n);
	}
}
/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
// Driver program to test above functions
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	getchar();
	return 0;
}