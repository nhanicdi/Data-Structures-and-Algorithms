//Created by: James

#include "bits/stdc++.h"

using namespace std;

int ucln(int a, int b) {
	if (a == 0) {
		if (b == 0)
			return -1;
		return 0;
	}
	else {
		if (b == 0)
			return 0;
		a = abs(a);
		b = abs(b);
		if (a == b)
			return a;
		else if (a > b)
			return ucln(a - b, b);
		else
			return ucln(a, b - a);
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << ucln(a, b);
	return 0;
}

