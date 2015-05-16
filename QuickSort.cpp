/* A typical recursive implementation of quick sort */
#include<stdio.h>
#if 0
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
#endif
//Simple Version

#include<iostream>
#include<stdio.h>
#include <time.h>

#define MAX 10000
//int arr[] = { 4, 1, 3, 10, 12, 5, 8 ,15 ,6 };
int arr[MAX];



using namespace std;

class sort
{
public:
	void swap(int s, int n)
	{
		if (arr[s] == arr[n])
			return;
		arr[s] ^= arr[n];
		arr[n] ^= arr[s];
		arr[s] ^= arr[n];
	}
	int getPartition(int s, int n) {
		int i= s;
		int pivot = arr[s];
		s++;
		int j = n;		
		while (1) {
			while (arr[s] < pivot)
				s++;
			while (arr[j] > pivot)
				j--;
			if (s < j)
				swap(s, j);
			else {
				swap(i, j);
				return j;
			}
		}
	}
	void qsort(int s,int n)
	{
		if (s < n) {
			int p = getPartition(s, n);
			qsort(s, p - 1);
			qsort(p + 1, n);
		}
	}
};

int main()
{
	for (int i = 0; i < MAX; i++)
		arr[i] = i;
	int n = sizeof(arr) / sizeof(arr[0]);
	sort s;
	clock_t st, et;
	st = clock();
	s.qsort(0, n-1);
	et = clock();
	double duration = (double)(et - st) / CLOCKS_PER_SEC;
	cout << "qsort duration " << duration << endl;
	/*for (int i = 0; i < n; i++)
		cout << arr[i] << " ";*/

	cout << endl;
	getchar();
}
