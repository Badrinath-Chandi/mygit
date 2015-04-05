#include<stdio.h>
#include<iostream>
using namespace std;
#define R 5
#define C 5

void printSpiral(int mat[R][C], int m, int n) {
	int i, j;
	for (i = 0, j = 0; i <= (m / 2); i++, j++) {
		int x = m - 1, y = n - 1;
		int a = i, b = j;
		while (b<=y && b<=y) {
			cout << mat[a][b] << " ";
			b++;
		}
		a++;
		b--;
		while (a<=x && a <= x) {
			cout << mat[a][b] << " ";
			a++;
		}
		a--;
		b--;
		while (b<=x && b >= j) {
			cout << mat[a][b]<<" ";
			b--;
		}
		b++;
		a--;
		while (a > i) {
			cout << mat[a][b]<<" ";
			a--;
		}
		m--;
		n--;
	}
}
// driver program to test above function
int main()
{
	 int mat[R][C] = { { 10, 20, 30, 40, 50 },
	{ 15, 25, 35, 45, 55 },
	{ 27, 29, 37, 48, 59 },
	{ 32, 33, 39, 50 , 60 },
	{11, 22, 33, 44, 55}
	};
	/*int mat[R][C] = { { 1, 2, 3, 4, 5, 6 },
	{ 7, 8, 9, 10, 11, 12 },
	{ 13, 14, 15, 16, 17, 18 }
	};*/
	printSpiral(mat, R , C);
	getchar();
	return 0;
}