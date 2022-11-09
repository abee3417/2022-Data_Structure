#include <stdio.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main() {
	Node n1, n2;
	n1.data = 5;
	n1.next = NULL;
	n2.data = 15;
	n2.next = NULL;

	n1.next = &n2;

	Node* ptr = &n1;

	/*
	printf("%d\n", ptr->data); //n1�� data�� ����Ŵ
	ptr = ptr->next; //n1�� next�� n2�̹Ƿ� n2�� data�� �����Ŵ
	printf("%d\n", ptr->data); //n2�� data�� ����Ŵ
	*/

	while (ptr != NULL) { //ptr�� NULL���ö����� ����� ����Ʈ�� data�� ��� �����
		printf("%d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}