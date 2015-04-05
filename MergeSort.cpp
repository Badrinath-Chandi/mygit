/* C program for merge sort */
#include<stdlib.h>
#include<stdio.h>

void mergeData(int *arr, int s, int mid, int n) {

	//int left[mid - s + 1];
	//int right[n - mid + 1];
	int *left = (int*)malloc(sizeof(int) * (mid - s + 1));
	int *right = (int*)malloc(sizeof(int) * (n - mid));
	for (int i = 0; i < mid - s + 1; i++) {
		left[i] = arr[s+i];
	}
	for (int i =0; i <= n-mid; i++) {
		right[i] = arr[mid+1+i];
	}
	int lCnt = 0;
	int rCnt = 0;
	int mCnt = s;
	while (lCnt < (mid - s + 1) && rCnt<(n - mid)) {
		if (left[lCnt] > right[rCnt]) {
			arr[mCnt] = right[rCnt];
			rCnt++;
		}
		else {
			arr[mCnt] = left[lCnt];
			lCnt++;
		}
		mCnt++;
	}
	while (lCnt < (mid - s + 1)) {
		arr[mCnt] = left[lCnt];
		lCnt++;
		mCnt++;
	}
	while (rCnt < (n - mid)) {
		arr[mCnt] = right[rCnt];
		rCnt++;
		mCnt++;
	}
}

void mergeSort(int *arr, int s, int n) {
	if (s < n) {
		int mid = (s+n) / 2;
		mergeSort(arr, s, mid);
		mergeSort(arr, mid + 1, n);
		mergeData(arr, s, mid, n);
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
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	getchar();
	return 0;
}