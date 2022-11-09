#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct _node {
	char* data;
	struct _node* link;
}Node;

typedef struct _stack {
	int count;
	Node* top;
}Stack;

Stack* create() { // ���� ���� (Create Stack)
	Stack* stack = malloc(sizeof(Stack));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}
int isEmpty(Stack* stack) { // Empty Stack
	return stack->count == 0;
}
int isFull(Stack* stack) { // Full Stack
	return stack->count == MAX;
}
void print(Stack* stack) {
	Node* node = stack->top;
	while (node != NULL) {
		printf("%s\n", node->data);
		node = node->link;
	}
	printf("\n");
}
void push(Stack* stack, char* data) { // Push
	if (isFull(stack)) {
		// ������ ���������� push���� �ʴ´�.
		return;
	}
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	// ���� data�� �� ���ο� ����ü�� �����.
	if (!isEmpty(stack)) {
		// ���� count�� 0�̸�, ž�� ���� ������� �ϹǷ�
		newNode->link = stack->top; // ��ũ�� ž���� �ɾ��ش�
	}
	stack->top = newNode; // ž�� ������Ʈ, �������ش�.
	stack->count++;
	// ���� ��ũ�� �����ϰ� ���ο� ������ ��ũ�� �������ش�.
}
Node* pop(Stack* stack) { // top�� �����ִ� pop
	Node* topNode = stack->top;
	stack->top = stack->top->link;
	// ž�� �����ɷ� �������ָ� ���� ž�� �������� ��. (�� �� ����)
	stack->count--; // count ���ҽ�Ŵ
	return topNode;
}
Node* top(Stack* stack) { // top���� �������ִ� �Լ�
	return stack->top;
}
int main() {
	Stack* stack = create(); 
	push(stack, "green");
	push(stack, "blue");
	push(stack, "red");
	print(stack);

	pop(stack);
	pop(stack);
	print(stack);
	return 0;
}