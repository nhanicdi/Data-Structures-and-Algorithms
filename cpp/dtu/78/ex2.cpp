//Created by: James

#include "bits/stdc++.h"
#include <conio.h>
using namespace std;

typedef struct phan_tu {
	int info;
	struct phan_tu* next;
} node;

node* create(int val) {
	node* new_node = new node;
	new_node->info = val;
	new_node->next = NULL;
	return new_node;
}

node* add_first(node* head, int val) {
	node* new_node = create(val);
	if(head == NULL)
		head = new_node;
	else {
		new_node->next = head;
		head = new_node;
	}
	return head;
}

void input(node* &head) {
	int val;
	char ch;
	head = NULL;
	do {
		cout << "\nval = ";
		cin >> val;
		head = add_first(head, val);
		cout << "\nESC to exit!";
		ch = getch();
	} while (ch != 27);
}

void print(node* head) {
	cout << "\n[";
	while (head != NULL) {
		cout << head->info << "\t";
		head = head->next;
	}
	cout << "]";
}

int max(node* head) {
	int max_value = head->info;
	head = head->next;
	while (head != NULL) {
		if (head->info > max_value)
			max_value = head->info;
		head = head->next;
	}
	return max_value;
}

int count(node* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

float average(node* head) {
	int sum = 0;
	node* trav = head;
	while (trav != NULL) {
		sum += trav->info;
		trav =trav->next;
	}
	return (float) sum / count(head);
}

void ascending_sort(node* &head) {
	for (node* i = head; i->next != NULL; i = i->next)
		for (node* j = i->next; j != NULL; j = j->next)
			if (i->info > j->info) {
				int temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
}

node* last_node(node* head) {
	while (head->next != NULL)
		head = head->next;
	return head;
}

node* merge(node* head, node* list) {
	if (head == NULL)
		head = list;
	else {
		node* last = last_node(head);
		last->next = list;
	}
	return head;
}

void delete_last(node* &head) {
	if(head == NULL)
		return;
	else if (head->next == NULL) {
		node* temp = head;
		head = NULL;
		delete temp;
		return;	
	}
	else {
		node* before_last;
		node* last = head;
		while (last->next != NULL) {
			before_last = last;
			last = last->next;
		}
		before_last->next = last->next;
		delete last;
	}
}

node* copy(node* list, node* head) {
	if (list != NULL) {
		if (list->info % 2 == 0)
		    head = add_first(head, list->info);
		return copy(list->next, head);
	}
	return head;
}

void sort_choose(node* &head, node* &list) {
	while (head != NULL) {
		int max_value = head->info;
		node* max_node = head;
		for (node* i = head; i != NULL; i = i->next)
			if (i->info > max_value) {
				max_value = i->info;
				max_node = i;
			}
		
		if (head != max_node) {
			node* before_max_node;
			for (node* i = head; i != max_node; i = i->next) 
				before_max_node = i;
			before_max_node->next = max_node->next;
			max_node->next = list;
			list = max_node;	
		}
		else {
			head = head->next;	
			max_node->next = list;
			list = max_node;
		}
	}
}

int main() {
	node* head = new node;
	input(head);
	print(head);
//	cout << endl << max(head);
//	print(head);
//	cout << endl << count(head);
//	cout << endl << average(head);
//	ascending_sort(head);
//	print(head);
//	node* last = last_node(head);
//	cout << endl << last->info;
	node* list = new node;
//	input(list);
//	print(list);
//	head = merge(head, list);
//	print(head);
//	delete_last(head);
//	print(head);
//	node* head = new node;
//	head = NULL;
//	print(head);
//	head = copy(list, head);
	list = NULL;
	sort_choose(head, list);
	print(head);
	print(list);
	return 0;
}

