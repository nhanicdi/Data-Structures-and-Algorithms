//Created by: James

#include "bits/stdc++.h"
using namespace std;

typedef struct sllist {
	int val;
	struct sllist* next;
}
sllnode;

sllnode* create(int val) {
	sllnode* new_node = new sllnode;
	new_node->val = val;
	new_node->next = NULL;
	return new_node;
};

bool find(sllnode* head, int val) {
	// Create a traversal pointer
	sllnode* trav = head;
	while (trav != NULL) {
		if (trav->val == val)
			return true;
		trav = trav->next;
	}
	return false;
}

sllnode* insert(sllnode* head, int val) {
	sllnode* new_node = create(val);
	if (head == NULL)
		head = new_node;
	else {
		new_node->next = head;
		head = new_node;
	}
	return head;
}

sllnode* insert_last(sllnode* head, int val) {
	sllnode* new_node = create(val);
	if (head == NULL)
		head = new_node;
	else {
		sllnode* trav = head;
		while (trav->next != NULL)
			trav = trav->next;
		trav->next = new_node;
	}
	return head;
}

void destroy(sllnode* &head) {
	if (head == NULL)
		return;
	destroy(head->next);
	delete head;
	head = NULL;
}

void print(sllnode* head) {
	cout << "\n[";
	while (head != NULL) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << "]";
}

int main() {
	sllnode* head = create(6);
	print(head);
//	bool exists = find(head, 6);
//	cout << exists;
	head = insert(head, 7);
	print(head);
	head = insert_last(head, 8);
	print(head);
	destroy(head);
	print(head);
	return 0;
}

