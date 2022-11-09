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
	x.next = n1.next; //n1.next와 같은 곳(n2)을 가르키게 하고
	n1.next = &x; //n1.next를 고쳐준다.

	Node* ptr = &n1;

	while (ptr != NULL) { //ptr이 NULL나올때까지 연결된 리스트의 data를 계속 출력함
		printf("%d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}