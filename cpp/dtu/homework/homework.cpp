#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;

struct sv {
	unsigned long masv;
	char hotensv[40];
	char ngaysinh[11];
	float DTB;
	char ghichu[100];
};

bool checkMaSV(sv * arr, int n, unsigned long masv1) {
	for (int i = 0; i < n; i++)
		if (arr[i].masv == masv1) return false;
	return true;
}

void nhap(sv * &arr, int &n) {
	cout << "\nNhap n: ";	cin >> n;
	arr = new sv[n];
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << " :";
		unsigned long masv1;
		cout << "\nNhap masv: ";
		do {
			cin >> masv1;
			if (checkMaSV(arr, n, masv1) == false) cout << "\nMasv da ton tai, vui long nhap lai: ";
		} while(checkMaSV(arr, n, masv1) == false);
		arr[i].masv = masv1;
		cout << "\nNhap ho ten sinh vien: ";
		fflush(stdin);
		gets(arr[i].hotensv);
		cout << "\nNhap ngay sinh: ";
		fflush(stdin);
		gets(arr[i].ngaysinh);
		cout << "\nNhap DTB: ";	
		do  {
			cin >> arr[i].DTB;
			if (arr[i].DTB < 0 || arr[i].DTB > 10) cout << "\nDiem nhap ko hop le, vui long nhap lai: ";
		} while(arr[i].DTB < 0 || arr[i].DTB > 10);
		if (arr[i].DTB >= 4) strncpy(arr[i].ghichu, "DAT", 100);
		else strncpy(arr[i].ghichu, "KO DAT", 100);
	}
}

void in(sv * arr, int n) {
	printf("\n%-10s%-40s%-15s%-10s%s", "Masv", "Ho ten", "Ngay sinh", "DTB", "Ghi chu");
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << setfill('0') <<setw(4) << arr[i].masv;
		printf("%-6s%-40s%-15s%-10.2f%s", " ", arr[i].hotensv, arr[i].ngaysinh, arr[i].DTB, arr[i].ghichu);
	}
}

int svKoDat(sv * arr, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (arr[i].DTB < 4) cnt++;
	return cnt;
}

void timTheoMaSV(sv * arr, int n) {
	cout << "\nNhap ma sv can tim: ";
	unsigned long masv1;
	cin >> masv1;
	for (int i = 0; i < n; i++)
		if(arr[i].masv == masv1) {
			printf("\n%-10s%-40s%-15s%-10s%s", "Masv", "Ho ten", "Ngay sinh", "DTB", "Ghi chu");
			cout << endl;
			cout << setfill('0') <<setw(4) << arr[i].masv;
			printf("%-6s%-40s%-15s%-10.2f%s", " ", arr[i].hotensv, arr[i].ngaysinh, arr[i].DTB, arr[i].ghichu);
			return;
		}
	cout << "\nKo co sinh vien nao co ma la " << setfill('0') << setw(4) << masv1;
}

void timTheoTen(sv * arr, int n) {
	char ten[40];
	int result = 0;
	cout << "\nNhap ten sv can tim: ";
	fflush(stdin);
	gets(ten);
	printf("\n%-10s%-40s%-15s%-10s%s", "Masv", "Ho ten", "Ngay sinh", "DTB", "Ghi chu");
	for (int i = 0; i < n; i++) {
		if (strstr(arr[i].hotensv, ten)!=NULL) {
			result = 1;
			cout << endl;
			cout << setfill('0') <<setw(4) << arr[i].masv;
			printf("%-6s%-40s%-15s%-10.2f%s", " ", arr[i].hotensv, arr[i].ngaysinh, arr[i].DTB, arr[i].ghichu);
		}
	}
	if (result == 0) cout << "\nKo co sinh vien nao co ten " << ten << " trong danh sach";
}

void xoaTheoMaSV(sv * &arr, int &n) {
	cout << "\nNhap masv can xoa: ";
	unsigned long masv1;
	cin >> masv1;
	for (int i = 0; i < n; i++)
		if (arr[i].masv == masv1) {
			for (int j = i; j < n - 1; j++)
				arr[j] = arr[j+1];
			n--;
			arr = (sv *) realloc (arr, n * sizeof(sv));
			return;
		}
	cout << "\nKo co sv nao co ma " << masv1 << " trong ds";
}

int sv1993(sv * arr, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (strstr(arr[i].ngaysinh, "1993")!=NULL) cnt++;
	return cnt;
}

void swap(sv * &a, sv * &b) {
	sv * temp = a;
	a = b;
	b = temp;
}

void quickSort(sv * &arr, int l, int r) {
	int i = l, j = r, pivot;
	while(i < j) {
		pivot = arr[(l+r)/2].DTB;
		while(arr[i].DTB > pivot) i++;
		while(arr[j].DTB < pivot) j--;
		if(i<=j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if(l<j) quickSort(arr, l, j);
	if(i<r) quickSort(arr, i, r);
}

void themSV(sv * &arr, int &n) {
	cout << "\nNhap thong tin sinh vien muon them: ";
	unsigned long masv1;
	sv sv1;
	cout << "\nNhap masv: ";
	do {
		cin >> masv1;
		if (checkMaSV(arr, n, masv1) == false) cout << "\nMasv da ton tai, vui long nhap lai: ";
	} while(checkMaSV(arr, n, masv1) == false);
	sv1.masv = masv1;
	cout << "\nNhap ho ten sinh vien: ";
	fflush(stdin);
	gets(sv1.hotensv);
	cout << "\nNhap ngay sinh: ";
	fflush(stdin);
	gets(sv1.ngaysinh);
	cout << "\nNhap DTB: ";	
	do  {
		cin >> sv1.DTB;
		if (sv1.DTB < 0 || sv1.DTB > 10) cout << "\nDiem nhap ko hop le, vui long nhap lai: ";
	} while(sv1.DTB < 0 || sv1.DTB > 10);
	if (sv1.DTB >= 4) strncpy(sv1.ghichu, "DAT", 100);
	else strncpy(sv1.ghichu, "KO DAT", 100);
	int i = 0;
	while(sv1.DTB <= arr[i].DTB) i++;
	n++;
	arr = (sv *) realloc (arr, n * sizeof(sv));
	for (int j = n; j > i; j--) arr[j] = arr[j-1];
	arr[i] = sv1;
}

int main() {
	sv * arr;
	int n;
	nhap(arr, n);
	in(arr, n);
	int l, r;
//	cout << "\nCo tat ca " << svKoDat(arr, n) << " co DTB < 4";
//	timTheoMaSV(arr, n);
//	timTheoTen(arr, n);
//	xoaTheoMaSV(arr, n);
//	in(arr, n);
//	cout << "\nCo tat ca " << sv1993(arr, n) << " sinh vien sinh nam 1993 trong ds";
	quickSort(arr, l, r);
	cout << "\nSau khi sap xep: ";
	in(arr, n);
//	themSV(arr, n);
//	in(arr, n);
	return 0;
}
