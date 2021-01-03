//Created by: James

#include "bits/stdc++.h"
using namespace std;

// Palindrome, Symmetrical
bool is_symmetrical(int n) {
	int rev = 0, temp = n;
	while (n != 0) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	if (rev == temp)
		return true;
	return false;
}

void print_symmetrical_numbers(int n) {
	int i = 0;
	while (i <= n) {
		if (is_symmetrical(i) == true && is_symmetrical(i * i) == true)
			cout << i << ' ';
		i++;
	}
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	cout << is_symmetrical(n);
	print_symmetrical_numbers(n);
	return 0;
}

