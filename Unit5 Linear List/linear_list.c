#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int val;
	struct _node* link;
}Node;

typedef struct _list {
	int count;
	Node* head;
}List;

List* create() {
	List* list = malloc(sizeof(List));
	list->count = 0;
	list->head = NULL;
	return list;
}

int searchNode(List* list, Node** pPre, Node** pLoc, int target) {
	*pPre = NULL;
	*pLoc = list->head;

	while ((*pLoc) != NULL && target > (*pLoc)->val) {
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	}
	int found = 0;
	if ((*pLoc) == NULL) {
		found = 0;
	}
	else {
		if (target == (*pLoc)->val) {
			found = 1;
		}
		else {
			found = 0;
		}
	}
	return found;

}

void insertNode(List* list, int data) {
	Node* pNew = malloc(sizeof(Node));
	pNew->val = data;
	pNew->link = NULL;

	Node* pPre, * pLoc;
	int found = searchNode(list, &pPre, &pLoc, data);

	if (pPre == NULL) {
		pNew->link = list->head;
		list->head = pNew;
	}
	else {
		pNew->link = pPre->link;
		pPre->link = pNew;
	}
	list->count++;
}

void deleteNode(List* list, int data) {
	Node* pPre, * pLoc;
	int found = searchNode(list, &pPre, &pLoc, data);
	if (found == 0){
		return;
	}
	if (pPre == NULL) {
		list->head = pLoc->link;
	}
	else {
		pPre->link = pLoc->link;
	}
	list->count--;
}

void traverse(List* list) {
	Node* node = list->head;
	while (node != NULL) {
		printf("%d ", node->val);
		node = node->link;
	}
	printf("\n");
}

int main() {
	List* list = create();
	insertNode(list, 100);
	insertNode(list, 5);
	insertNode(list, 25);
	traverse(list); // 5 25 100

	deleteNode(list, 80);
	deleteNode(list, 25);
	traverse(list); // 5 100
	return 0;
}