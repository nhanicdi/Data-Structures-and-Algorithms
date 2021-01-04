//Created by: James

#include "bits/stdc++.h"
using namespace std;

int arr[100], n;

void print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i];
	cout << endl;
} 

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		arr[i] = j;
		if (i == n - 1)
			print(arr, n);
		else
			Try(i + 1);
	}
}

int main() {
	n = 5;
	Try(0);
	return 0;
}

