//Created by: James

#include "bits/stdc++.h"
using namespace std;

void input(int arr[], int &n) {
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\narr[" << i << "] = ";
		cin >> arr[i];
	}
}

void print(int arr[], int &n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}

int maxValue(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int main() {
	int arr[100], n;
	input(arr, n);
	print(arr, n);
	cout << "\nMax value of array: " << maxValue(arr, n);
	return 0;
}

