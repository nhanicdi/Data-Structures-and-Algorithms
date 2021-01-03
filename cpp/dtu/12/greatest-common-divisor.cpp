//Created by: James
// Program: Calculate greatest common divisor of 2 given numbers

#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b) {
	if (a == 0)
		if (b == 0)
			return -1;
		else
			return 0;
	if (b == 0)
		return 0;
	a = abs(a);
	b = abs(b);
	if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else
		return gcd(a, b - a);
}

int main() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "Greatest common divisor of " << a << " and " << b << ": " << gcd(a, b);
	return 0;
}

