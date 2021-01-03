//Created by: James
// Program: Fibonacii
#include "bits/stdc++.h"

using namespace std;

int fibonacii(int n) {
	if (n == 0 || n == 1)
		return 1;
	return fibonacii(n - 2) + fibonacii(n - 1);
}

// Print first n Fibonacii numbers
void printFirstNFibonacii(int n) {
	for (int i = 0; i < n; i++)
		cout << fibonacii(i) << ' ';
}

// Print fibonacii numbers which are less than or equal to n
void printFibonaciiLEN(int n) {
	int i = 0;
	while (fibonacii(i) <= n) {
		cout << fibonacii(i) << ' ';
		i++;
	}
}

bool is_fibonacii(int m) {
	int i = 0;
	while (i < m) {
		if (fibonacii(i) == m)
			return true;
		i++;
	}
	return false;
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	printFirstNFibonacii(n);
	cout << endl;
	printFibonaciiLEN(n);
	int m;
	cout << "\nm = ";
	cin >> m;
	cout << is_fibonacii(m);
	return 0;
}

