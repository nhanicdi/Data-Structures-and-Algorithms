//Created by: James

#include "bits/stdc++.h"
using namespace std;

void input(int arr[], int &n) {
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\narr[" << i << "] = ";
		cin >> arr[i];
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}

void insert_x(int arr[], int &n, int x, int k) {
	n++;
	for (int i = n - 1; i > k - 1; i--)
		arr[i] = arr[i - 1];
	arr[k - 1] = x;
}

void descending_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}

void insert_y_into_descending_sorted_array(int arr[], int &n, int y) {
	int i = 0;
	while (y <= arr[i])
		i++;
	n++;
	for (int j = n - 1; j > i; j--)
		arr[j] = arr[j - 1];
	arr[i] = y;
}
 
void delete_at_position(int arr[], int &n, int k) {
	for (int i = k - 1; i < n; i++)
		arr[i] = arr[i + 1];
	n--;
}

void delete_all_x(int arr[], int &n, int x) {
	int i = 0;
	while (i < n) {
		if (arr[i] == x)
			delete_at_position(arr, n, i + 1);
		else 
			i++;
	}		
}

void print_all_indices_of_x(int arr[], int n, int x) {
	cout << "\nAll indices of " << x << " are: ";
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			cout << i << ' ';
}

int menu() {
	int option;
	cout << "\n----------- JAMES DANG -----------";
	cout << "\n1. Print the array";
	cout << "\n2. Insert a value at a position to the array";
	cout << "\n3. Sort the array in descending order";
	cout << "\n4. Insert a value to the descending sorted array (The array will also in descending sorted after inserting)";
	cout << "\n5. Delete an element at a given position";
	cout << "\n6. Delete all elements which equal to a given value";
	cout << "\n7. Print all indices of a given value";
	cout << "\n0. Exit";
	cout << "\nYou choose: ";
	cin >> option;
	return option;
	
}

void run(int arr[], int n, int option) {
	switch(option) {
		case 1: 
			print(arr,n);
			menu();
		case 2:
			int x, k; 
			cout << "\nx = ";
			cin >> x;
			do {
				cout << "\nk = ";
				cin >> k;
				if (k < 0 || k > n + 1)
					cout << "\nk is invalid, please enter again!";	
			} while (k < 0 || k > n + 1);
			insert_x(arr, n, x, k);
			print(arr, n);	
			menu();
		case 3:
			descending_sort(arr, n);
			cout << "\nAfter sorting: ";
			print(arr, n);
			menu();
		case 4:
			int y;
			cout << "\n y = ";
			cin >> y;
			insert_y_into_descending_sorted_array(arr, n, y);
			cout << "\nAfter inserting: ";
			print(arr, n);
			menu();
		case 5:
			do {
			cout << "\nEnter position of an element that you want to delete: ";
			cin >> k;
			if (k < 1 || k > n)
				cout << "\nk is invalid, please enter again!";	
			} while (k < 1 || k > n);
			delete_at_position(arr, n, k);
			print(arr, n);
			menu();
		case 6:
			cout << "\nx = ";
			cin >> x;
			delete_all_x(arr, n, x);
			print(arr, n);
			menu();
		case 7:
			cout << "\nx = ";
			cin >> x;
			print_all_indices_of_x(arr, n, x);
			menu();
		default:
			break;	
	}
}
 
int main() {
	int arr[100], n, x, k;	
	cout << "\nBefore you start, please input array with a determined size\n";
	input(arr, n);
	run(arr, n, menu());
	return 0;	
}

