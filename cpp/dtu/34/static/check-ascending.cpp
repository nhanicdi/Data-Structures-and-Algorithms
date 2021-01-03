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

bool is_ascending_recursive(int arr[], int n) {
	if (n == 1)
		return true;
	if (arr[n - 1] >= arr[n - 2])
		return is_ascending_recursive(arr, n - 1);
	return false;
}

bool is_ascending_iterative(int arr[], int n) {
	if (n == 1)
			return true;
	else {
		bool result = false;
		while (n >= 1) {
			if (arr[n - 1] >= arr[n - 2]) {
				result = true;
				n--;
			}
			else
				return false;	
		}
		return result;
	}	
}

int main() {
	int arr[100], n;
	input(arr, n);
	cout << is_ascending_recursive(arr, n);
	cout << is_ascending_iterative(arr, n);
	return 0;
}

