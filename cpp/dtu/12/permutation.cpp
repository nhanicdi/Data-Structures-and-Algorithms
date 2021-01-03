//Created by: James

#include "bits/stdc++.h"
using namespace std;

int n, p[100], mark[100];

void print_permutation() {
	for (int i = 1; i <= n; i++)
		cout << p[i] << ' ';
	cout << endl;
}

void Try(int i) {
	for (int j = 1; j <= n; j++)
		if (mark[j] == 0) {
			p[i] = j;
			mark[j] = 1;
			if (i == n)
				print_permutation();
			else
				Try(i + 1);
			mark[j] = 0;
		}
}

int main() {
	cout << "n = ";
	cin >> n;
	Try(1);
	return 0;
}

