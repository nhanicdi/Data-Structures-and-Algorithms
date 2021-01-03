//Created by: James

#include "bits/stdc++.h"
using namespace std;

int calculate_S_1(int n) {
	if (n == 1)
		return 1;
	return n + calculate_S_1(n - 1);
}

int calculate_S_2(int n) {
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return calculate_S_2(n - 1);
	return n + calculate_S_2(n - 1);
}

void reverse(int n) {
	if (n == 0)
		return;
	cout << n % 10;
	return reverse(n / 10);
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
//	cout << "a. S = " << calculate_S_1(n);
//	cout << "\bb. S = " << calculate_S_2(n);
	reverse(n);
	return 0;
}

