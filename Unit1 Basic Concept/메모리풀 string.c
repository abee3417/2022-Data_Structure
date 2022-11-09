#include <stdio.h>

typedef struct _node {
	void* data; //void�� ��� ������Ÿ���� ����ų�� �ֱ� ������ ���
	struct _node* next;
} Node;

int main() {
	Node pool[4];
	Node* ptr = NULL;
	
	for (int i = 0; i < 3; i++) {
		ptr = &pool[i];
		switch (i) { //else if�� �ϸ� ��� switch�� ��� �ұ�?
		case 0:
			ptr->data = "lee";
		case 1:
			ptr->data = "hi";
		case 2:
			ptr->data = "?";
		}
		ptr->next = &pool[i + 1];
	}
	pool[2].next = NULL; // ������ ����Ʈ�� next�� NULL�� �ݵ�� ����.
	ptr = &pool[0];



	while (ptr != NULL) { //ptr�� NULL���ö����� ����� ����Ʈ�� data�� ��� �����
		printf("%s --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}