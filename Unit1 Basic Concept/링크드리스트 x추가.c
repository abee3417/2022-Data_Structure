#include <stdio.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main() {
	Node n1, n2, x;
	n1.data = 5;
	n1.next = NULL;
	n2.data = 15;
	n2.next = NULL;

	n1.next = &n2;

	x.data = 10;
	x.next = n1.next; //n1.next�� ���� ��(n2)�� ����Ű�� �ϰ�
	n1.next = &x; //n1.next�� �����ش�.

	Node* ptr = &n1;

	while (ptr != NULL) { //ptr�� NULL���ö����� ����� ����Ʈ�� data�� ��� �����
		printf("%d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}