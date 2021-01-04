//Created by: James

#include "bits/stdc++.h"
using namespace std;

void quick_sort(int arr[], int l, int r) {
	int i = l, j = r, pivot;
	while (i < j) {
		pivot = arr[(l + r) / 2];
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
			if (i <= j) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
				j--;
			}
	}
	if (l < j)
		return quick_sort(arr, l, j);
	if (i < r)
		return quick_sort(arr, i, r);
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
}

int main() {
	int arr[5] = {1, 5, 7, 8, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	print_array(arr, n);
	quick_sort(arr, 0, n - 1);
	print_array(arr, n);
	return 0;
}

