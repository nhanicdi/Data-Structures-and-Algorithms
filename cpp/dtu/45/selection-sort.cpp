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

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}

void selection_sort(int arr[], int n) {
	int i = 0;
	while (i < n - 1) {
		int min_value = arr[i], min_index = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < min_value) {
				min_value = arr[j];
				min_index = j;
			}
		if (min_index != i) {
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
			}
		i++;
	}
}

int main() {
	int arr[100], n;
	input(arr, n);
	print_array(arr, n);
	selection_sort(arr, n);
	cout << "\nSelection sort: ";
	print_array(arr, n);
	return 0;
}

