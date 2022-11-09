#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct _node {
	char* data;
	struct _node* link;
}Node;

typedef struct _queue {
	int count;
	Node* front;
	Node* rear;
}Queue;

Queue* create() {
	Queue* queue = malloc(sizeof(Queue));
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}
int isEmpty(Queue* queue) {
	return queue->count == 0;
}
int isFull(Queue* queue) {
	return queue->count == MAX;
}

void print(Queue* queue) {
	Node* node = queue->front;
	while (node != NULL) {
		printf("%s\n", node->data);
		node = node->link;
	}
	printf("%d\n\n", queue->count);
}

void enqueue(Queue* queue, char* data) {
	if (isFull(queue)) {
		return;
	}
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	if (isEmpty(queue)) {
		queue->front = newNode;
		queue->count++;
	}
	else {
		queue->rear->link = newNode;
		queue->count++;
	}
	queue->rear = newNode;
}
Node* dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		return;
	}
	if (queue->count == 1) {
		queue->front = NULL;
		queue->rear = NULL;
		queue->count--;
	}
	else {
		queue->front = queue->front->link;
		queue->count--;
	}
}
int main() {
	Queue* queue = create();
	enqueue(queue, "green");
	print(queue);
	enqueue(queue, "blue");
	print(queue);
	enqueue(queue, "red");
	print(queue);

	dequeue(queue);
	print(queue);
	dequeue(queue);
	print(queue);
	return 0;
}