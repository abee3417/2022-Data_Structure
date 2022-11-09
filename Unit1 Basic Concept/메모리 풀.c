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
	pool[2].next = NULL; // 마지막 리스트의 next를 NULL로 반드시 설정.
	ptr = &pool[0];

	

	while (ptr != NULL) { //ptr이 NULL나올때까지 연결된 리스트의 data를 계속 출력함
		printf("%d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}