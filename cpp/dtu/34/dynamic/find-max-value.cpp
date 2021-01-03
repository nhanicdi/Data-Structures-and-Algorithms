//Created by: James

#include "bits/stdc++.h"
using namespace std;

void input(int * &arr, int &n) {
	cout << "n = ";
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "\narr[" << i << "] = ";
		cin >> arr[i];
	}
}

void print(int * arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}

int max(int * arr, int n) {
	int max_value = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max_value)
			max_value = arr[i];
	return max_value;
}

int main() {
	int * arr, n;
	input(arr, n);
	print(arr, n);
	cout << "\nMax value of array: " << max(arr, n);
	return 0;
}

