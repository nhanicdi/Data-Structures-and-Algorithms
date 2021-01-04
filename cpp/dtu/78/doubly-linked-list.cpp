//Created by: James

#include "bits/stdc++.h"
#include <conio.h>
using namespace std;

struct node {
	int data;
	node *next, *prev;
};

void create(node* &list) {
	list = NULL;
}

void add_first(node* &list, int val) {
	node *n = new node;
	n->data = val;
	n->next = NULL;
	n->prev = NULL;
	
	if (list == NULL)
		list = n;
	else {
		n->next = list;
		list->prev = n;
		list = n;
	}
}

void add_last(node* &list, int val) {
	node *n = new node;
	n->data = val;
	n->next = NULL;
	n->prev = NULL;
	
	if (list == NULL)
		list = n;
	else {
		node *tmp = list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = n;
		n->prev = tmp;
	}
}

int length(node* list) {
	int cnt = 0;
	while (list != NULL) {
		cnt++;
		list = list->next;
	}
	return cnt;
}

void add_node(node* &list, int x, int pos) {
	if (pos > 0 && pos <= length(list) + 1) {
		if (pos == 1)
			add_first(list, x);
		else if (pos == length(list) + 1) {
			add_last(list, x);
		}
		else {
			node *n = new node;
			n->data = x;
			n->next = NULL;
			n->prev = NULL;
			
			int i = 1;
			node *tmp = list;
			while (i < pos) {
				tmp = tmp->next;
				i++;
			}
				
			tmp->prev->next = n;
			n->prev = tmp->prev;
			n->next = tmp;
			tmp->prev = n;
		}
	}	
}

void input(node* &list) {
	create(list);
	int x;
	char ch;
	do {
		cout << "x = ";
		cin >> x;
//		add_first(list, x);
		add_last(list, x);
		cout << "ESC to exit!";
		ch = getch();
	} while (ch != 27);
}

void print_list(node *list) {
	cout << endl;
	while (list != NULL) {
		cout << list->data << "\t";
		list = list->next;
	}
}

int main() {
	node *list = new node;
	input(list);
	print_list(list);
	add_node(list, 5, 2);
	print_list(list);
	return 0;
}

