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

void increasingSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}

int main() {
	int arr[100], n;
	input(arr, n);
	print(arr, n);
	increasingSort(arr, n);
	cout << "\nAfter sorting: ";
	print(arr, n);
	return 0;
}

