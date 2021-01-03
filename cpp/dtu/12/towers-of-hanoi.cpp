//Created by: James

#include "bits/stdc++.h"
using namespace std;

void towers_of_hanoi(int n, char source, char spare, char dest) {
	// spare (n): an extra thing that is not being used and can be used instead of a part that is broken, lost, etc.
	if (n == 0) {
		cout << "\nMove disc 1 from " << source << " to " << dest;
		return;
	}
	else {
		towers_of_hanoi(n - 1, source, dest, spare);
		cout << "\nMove disc " << n << " from " << source << " to " << dest;
		towers_of_hanoi(n - 1, spare, source, dest);	
	}
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	towers_of_hanoi(n, 'A', 'B', 'C');
	return 0;
}

