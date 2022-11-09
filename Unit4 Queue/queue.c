#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char* data;
	struct _node* link;
}Node;

typedef struct _head {
	int count;
	Node* front;
	Node* rear;
}Queue;

Queue* create() {
	Queue* queue = malloc(sizeof(Queue));
	queue->count = 0;
	queue->front = queue->rear = NULL;
	return queue;
}

void enqueue(Queue* queue, int data) {
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	if (queue->count == 0) {
		queue->front = newNode; // 아무것도 없으면 front에도 연결해준다.
	}
	else {
		queue->rear->link = newNode; // rear의 link를 먼저 수정한 후
	}
	queue->rear = newNode; // rear을 고쳐준다.
	queue->count++;
}

Node* dequeue(Queue* queue) { // return타입이 node임.
	Node* node = queue->front; // front가 가장 먼저 없어지기 때문.
	if (queue->count == 1) {
		queue->rear = NULL; // 하나 남아있는 상태면 null로 변경
	}
	queue->front = queue->front->link; // front도 새로 고쳐줌
	queue->count--;
	return node;
}

int isEmpty(Queue* queue) {
	return queue->count == 0;
}

int main() {
	Queue* q1 = create();
	Queue* q2 = create();
	int d;
	scanf("%d", &d);
	while (d != -1) {
		if (d < 10) { // 10보다 작은건 q1로
			enqueue(q1, d);
		}
		else {
			enqueue(q2, d);
		}
		scanf("%d", &d);
	}
	printf("q1 : ");
	while (!isEmpty(q1)) {
		Node* n = dequeue(q1);
		printf("%d ", n->data); // 먼저 들어간 순서대로 출력
	}
	printf("\nq2 : ");
	while (!isEmpty(q2)) {
		Node* n = dequeue(q2);
		printf("%d ", n->data);
	}
	return 0;
}