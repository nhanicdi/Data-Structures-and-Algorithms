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

void bubble_sort(int arr[], int n) {
	int swap_counter = -1;
	while (swap_counter != 0) {
		swap_counter = 0;
		int i = 0;
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap_counter++;
			}
	}
}

int main() {
	int arr[100], n;
	input(arr, n);
	print_array(arr, n);
	bubble_sort(arr, n);
	cout << "\nBubble sort: ";
	print_array(arr, n);
	return 0;
}

