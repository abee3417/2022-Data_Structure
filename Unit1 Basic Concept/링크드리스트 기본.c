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
	printf("%d\n", ptr->data); //n1의 data를 가르킴
	ptr = ptr->next; //n1의 next는 n2이므로 n2의 data를 연결시킴
	printf("%d\n", ptr->data); //n2의 data를 가르킴
	*/

	while (ptr != NULL) { //ptr이 NULL나올때까지 연결된 리스트의 data를 계속 출력함
		printf("%d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}