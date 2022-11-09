// �迭�� �̿��� ���� ����
// LL���� �ξ� ������.
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct _node {
	char* data;
	//struct _node* link; �迭�� �̿��ϹǷ� link �ʿ����.
}Node;

typedef struct _stack {
	int count;
	Node* top;
}Stack;

int top = -1; // -1�� �ǹ̴� ���� ������ ����ִٴ� ��.
Node stack[MAX]; // stack

int isFull() {
	return top == MAX - 1;
}

int isEmpty() {
	return top == -1;
}

void push(char* data) {
	if (isFull()) {
		return;
	}
	stack[++top].data = data;
}

void pop() {
	if (isEmpty()) {
		return;
	}
	--top;
}

Node topNode() {
	if (isEmpty()){
	return;
	}
	return stack[top];
}

void print() {
	for (int i = top; i >= 0; i--) {
		printf("%s\n", stack[i].data);
	}
	printf("\n");
}
int main() {
	push("green");
	push("blue");
	push("red");
	print();

	pop();
	pop();
	print();
	return 0;
}