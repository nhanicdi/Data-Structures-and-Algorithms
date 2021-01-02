#include<iostream>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		//Find the minimum element in unsorted array
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		//Swap the found minimum element with the first element 
		swap(arr[i], arr[min_idx]);
	}
}

void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}

int main() {
	int arr[10] = {3, 8, 7, 6, 2, 5, 3, 19, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	print(arr, n);
}
