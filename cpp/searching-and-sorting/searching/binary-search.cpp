#include<conio.h>
#include<iostream>
using namespace std;

int search(int arr[], int n, int x) {
	int mid;
	int left = 0, right = n - 1;
	while(left != right) {
		mid = (left + right) / 2;
		if(x > arr[mid])	left = mid + 1;
		else right = mid - 1;
	}
	if(arr[left] == x) return left;
	return -1;
}

int binarySearchRecursive(int arr[], int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearchRecursive(arr, l, mid - 1, x);
		return binarySearchRecursive(arr, l + 1, r, x);
	}
	return -1;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 6;
	int result = binarySearchRecursive(arr, 0, n - 1, x);
	(result == -1)
		? cout<<"Element is not present in array"
		: cout<<"Element is present in array at index " << result;
	
	int result2 = search(arr, n , x);
	(result2 == -1)
		? cout<<"Element is not present in array"
		: cout<<"Element is present in array at index " << result2;
	return 0;
}
