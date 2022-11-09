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
		queue->front = newNode; // �ƹ��͵� ������ front���� �������ش�.
	}
	else {
		queue->rear->link = newNode; // rear�� link�� ���� ������ ��
	}
	queue->rear = newNode; // rear�� �����ش�.
	queue->count++;
}

Node* dequeue(Queue* queue) { // returnŸ���� node��.
	Node* node = queue->front; // front�� ���� ���� �������� ����.
	if (queue->count == 1) {
		queue->rear = NULL; // �ϳ� �����ִ� ���¸� null�� ����
	}
	queue->front = queue->front->link; // front�� ���� ������
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
		if (d < 10) { // 10���� ������ q1��
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
		printf("%d ", n->data); // ���� �� ������� ���
	}
	printf("\nq2 : ");
	while (!isEmpty(q2)) {
		Node* n = dequeue(q2);
		printf("%d ", n->data);
	}
	return 0;
}