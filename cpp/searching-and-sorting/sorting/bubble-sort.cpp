//Created by: James
//Created date: December 9th 2020
#include<iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int arr[], int n) {		//we will go from begining to the end of array for the first time, then swap in pair
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++)		
			if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
	}	//after finishing 1st sort, max number will be at index n - 1 - 0 so we will minus the length need to sort by 1
		//after finishing i times sort, max number will be at index n -1 - i, so we will continue sort array with the length is previous length - i
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
}

int main() {
	int arr[10] = {3, 8, 7, 6, 2, 5, 3, 19, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	print(arr, n);
}
