#include <stdio.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main() {
	Node pool[4];
	Node* ptr = NULL;

	for (int i = 0; i < 3; i++) {
		ptr = &pool[i];
		ptr->data = i * 5;
		ptr->next = &pool[i + 1];
	}
	pool[2].next = NULL; // ������ ����Ʈ�� next�� NULL�� �ݵ�� ����.
	ptr = &pool[0];

	

	while (ptr != NULL) { //ptr�� NULL���ö����� ����� ����Ʈ�� data�� ��� �����
		printf("%d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}