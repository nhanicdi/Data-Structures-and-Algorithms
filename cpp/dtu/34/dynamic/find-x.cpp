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

bool is_present(int * arr, int n, int x) {
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return true;
	return false;
}

int main() {
	int * arr, n, x;
	input(arr, n);
	cout << "\nx = ";
	cin >> x;
	(is_present(arr, n, x) == true)
		?	cout << x << " is present in the array"
		:	cout << x << " is not present in the array";
	return 0;
}

