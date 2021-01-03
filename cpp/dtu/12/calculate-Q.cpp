//Created by: James

#include "bits/stdc++.h"

using namespace std;

int calculate_Q(int a, int b) {
	if (a < b)
		return 0;
	return calculate_Q(a - b, b) + 1;
}

int main() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << calculate_Q(a, b);
	return 0;
}

