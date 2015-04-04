
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(vector <int>  ar) {
	int i = 0, j = 0;
	int key;
	for (int i = 1; i < ar.size(); i++) {
		key = ar.at(i);
		j = i - 1;
		while (j >= 0 && ar.at(j) > key) {
			ar.at(j + 1) = ar.at(j);
			j = j - 1;
		}
		ar.at(j + 1) = key;
		for (int k = 0; k<ar.size(); k++)
			cout << ar.at(k) << " ";
		cout << endl;
	}

}
int main(void) {
	vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for (int _ar_i = 0; _ar_i<_ar_size; _ar_i++) {
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp);
	}

	insertionSort(_ar);

	return 0;
}