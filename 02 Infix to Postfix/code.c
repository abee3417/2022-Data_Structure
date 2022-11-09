#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // ���ڿ� ���̴� 100�� �ִ��̹Ƿ� ���� ũ�⵵ 100���� �����ϱ� ���� ��������

typedef struct _node {
	char* data;
	struct _node* link;
}Node;

typedef struct _stack {
	int count;
	Node* top;
}Stack;

Stack* create() { // ���� ����
	Stack* stack = malloc(sizeof(Stack));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

int isEmpty(Stack* stack) { // ���� ����ִ��� Ȯ��
	return stack->count == 0;
}

int isFull(Stack* stack) { // ���� �����ִ��� Ȯ��
	return stack->count == MAX;
}

void push(Stack* stack, char* data) { // Push
	if (isFull(stack)) { // ������ ���������� push���� �ʴ´�.
		return;
	}
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	if (!isEmpty(stack)) {
		newNode->link = stack->top;
	}
	stack->top = newNode;
	stack->count++;
}

Node* pop(Stack* stack) { // Pop
	if (isEmpty(stack)) { // ������ ��������� pop���� �ʴ´�.
		return;
	}
	Node* topNode = stack->top;
	stack->top = stack->top->link;
	stack->count--;
	return topNode;
}

Node* top(Stack* stack) { // Top
	return stack->top->data;
}

int main() {
	int str_cnt, str_len;
	char ch;
	Stack* stack = create();
	freopen("input.txt", "r", stdin);
	FILE* fp = freopen("output.txt", "w", stdout);
	scanf("%d", &str_cnt); // ó���ؾ��� ���� ���� �޴´�.
	for (int i = 0; i < str_cnt; i++) {
		scanf("%d", &str_len); // ���� ���� ���� �޴´�.
		for (int j = 0; j < str_len; j++) {
			scanf(" %c", &ch);
			if (ch == '(') {
				push(stack, ch);
			}
			else if (ch == ')') { // ���� ��ȣ�� ������ ������ȣ ���ö����� top, pop
				while (stack->top->data != '(') {
					fprintf(fp, "%c", top(stack));
					pop(stack);
				}
				pop(stack); // �������� ������ȣ�� pop
			}
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
				while (!isEmpty(stack)) {
					// *, /�� +, -���� �켱������ ���� ������ �̷� ��� ���ÿ� �״�� �ױ� ���� pop���� �ʰ� break�Ѵ�.
					if ((ch == '*' || ch == '/') && (top(stack) == '+' || top(stack) == '-')) {
						break;
					}
					// ������ȣ�� pop�� �ϸ� �ȵǱ� ������ break�Ѵ�.
					else if (top(stack) == '(') {
						break;
					}
					// ������ ���� ������ �����ڵ��� top, pop��Ų��.
					else {
						fprintf(fp, "%c", top(stack));
						pop(stack);
					}
				}
				// �ݺ��� ���� �� ���� �����ڸ� push
				push(stack, ch);
			}
			else {
				fprintf(fp, "%c", ch); // operand�� �״�� ���
			}
		}
		while (!isEmpty(stack)) { // ���� ������ �����ڵ��� ���� top, pop�Ѵ�.
			fprintf(fp, "%c", top(stack));
			pop(stack);
		}
		fprintf(fp, "\n"); // �� ���� �ϳ��� �ĸ� �������� ��
	}
	return 0;
}