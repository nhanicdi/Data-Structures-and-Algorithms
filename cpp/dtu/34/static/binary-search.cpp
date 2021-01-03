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

int binary_search(int arr[], int left, int right, int x) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == x)
			return mid;
		else if (arr[mid] < x)
			return binary_search(arr, mid + 1, right, x);
		else
			return binary_search(arr, left, mid - 1, x);
	}
	return -1;
}

int main() {
	int arr[100], n, x;
	input(arr, n);
	cout << "\nx = ";
	cin >> x;
	(binary_search(arr, 0, n - 1, x) != -1)
		?	cout << x << " is present in the array at index " << binary_search(arr, 0, n - 1, x)
		:	cout << x << " is not present in the array!";
	return 0;
}

