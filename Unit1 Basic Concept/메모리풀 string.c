#include <stdio.h>

typedef struct _node {
	void* data; //void는 모든 데이터타입을 가르킬수 있기 때문에 사용
	struct _node* next;
} Node;

int main() {
	Node pool[4];
	Node* ptr = NULL;
	
	for (int i = 0; i < 3; i++) {
		ptr = &pool[i];
		switch (i) { //else if로 하면 쉬운데 switch로 어떻게 할까?
		case 0:
			ptr->data = "lee";
		case 1:
			ptr->data = "hi";
		case 2:
			ptr->data = "?";
		}
		ptr->next = &pool[i + 1];
	}
	pool[2].next = NULL; // 마지막 리스트의 next를 NULL로 반드시 설정.
	ptr = &pool[0];



	while (ptr != NULL) { //ptr이 NULL나올때까지 연결된 리스트의 data를 계속 출력함
		printf("%s --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("END\n");

	return 0;
}