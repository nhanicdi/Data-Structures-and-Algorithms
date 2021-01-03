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

int sum(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
			sum += pow(arr[i], 2);
	return sum;
}

int main() {
	int arr[100], n;
	input(arr, n);
	print(arr, n);
	cout << "\nSum of negative squared numbers in array: " << sum(arr, n);
	return 0;
}

