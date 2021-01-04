#include <iostream> 
#include <stdlib.h>
using namespace std;

struct node {
	int number;
	node *next;
};

int main(void) {
	node *list = NULL;

	node *n = new node;
	if (n == NULL)
		return 1;
	n->number = 1;
	n->next = NULL;
	list = n;

	n = new node;
	if (n == NULL) {
		free(list);
		return 1;
	}
	n->number = 2;
	n->next = NULL;
	list->next = n;

	n = new node;
	if (n == NULL) {
		free(list->next);
		free(list);
		return 1;
	}
	n->number = 3;
	n->next = NULL;
	list->next->next = n;

	for (node *tmp = list; tmp != NULL; tmp = tmp->next) 
		cout << "\n" << tmp->number;	

	while (list != NULL) {
		node *tmp = list->next;
		free(list);	
		list = tmp;
	}

	for (node *tmp = list; tmp != NULL; tmp = tmp->next) 
		cout << "\n" << tmp->number;	
}
