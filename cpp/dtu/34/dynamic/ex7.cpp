//Created by: James

#include "bits/stdc++.h"

using namespace std;
struct student {
	unsigned long id;
	char name[40];
	float average_mark;
};

bool check_id(student * s, int n, unsigned long new_id) {
	for (int i = 0; i < n; i++)
		if (s[i].id == new_id)
			return false;
	return true;
}

void input(student * &s, int &n) {
	cout << "\nn = ";
	cin >> n;
	s = new student[n];
	for (int i = 0; i < n; i++) {
		cout << "\nEnter information of Student " << i << ": ";
		unsigned long new_id;
		do {
			cout << "\nStudent ID: ";
			cin >> new_id;
			if (check_id(s, n, new_id) == false)
				cout << "This ID has been existed in the Students list";
		} while (check_id(s, n, new_id) == false);
		s[i].id = new_id;
		cout << "Student name: ";
		fflush(stdin);
		gets(s[i].name);
		cout << "Average mark: ";
		cin >> s[i].average_mark;
	}
}

void print_list(student * s, int n) {
	printf("\n%-10s%-30s%s", "ID", "Name", "Average mark");
	for (int i = 0; i < n; i++) {
		cout << endl << setfill('0') << setw(5) << s[i].id;
		printf("%-5s%-30s%-0.2f", " ", s[i].name, s[i].average_mark);
	}
}

void fail_students(student * s, int n) {
	cout << "\nFail students:";
	printf("\n%-10s%-30s%s", "ID", "Name", "Average mark");
	for (int i = 0; i < n; i++) {
		if (s[i].average_mark < 4) {
			cout << endl << setfill('0') << setw(5) << s[i].id;
			printf("%-5s%-30s%-0.2f", " ", s[i].name, s[i].average_mark);
		}
	}
}

// https://giaypheplaodong.net.vn/xep-loai-hoc-luc-tieng-anh-la-gi-xep-loai-tot-nghiep-trong-tieng-anh/
int very_good_students(student * s, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i].average_mark >= 8)
			cnt++;
	return cnt;
}

void write_file(student * s, int n) {
	FILE * f = fopen("./students.txt", "w");
	fprintf(f, "%d", n);
	for (int i = 0; i < n; i++) {
		fprintf(f, "\n%u\t%s\t%-0.2f", s[i].id, s[i].name, s[i].average_mark);
	}
	fclose(f);
}

int main() {
	student * s;
	int n;
	input(s, n);
	print_list(s, n);
	fail_students(s, n);
	cout << "\nNumber of very good students: " << very_good_students(s, n);
	write_file(s, n);
	return 0;
}

