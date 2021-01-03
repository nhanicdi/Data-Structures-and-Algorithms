//Created by: James

#include "bits/stdc++.h"
using namespace std;

typedef struct sllist {
	int val;
	struct sllist* next;
}
sllnode;

sllnode* create(int val);

int main() {
	sllnode* new_node = create(6);
	new_node->next = NULL;
	return 0;
}

