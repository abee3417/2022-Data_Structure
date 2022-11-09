#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // 문자열 길이는 100이 최대이므로 스택 크기도 100으로 제한하기 위한 전역변수

typedef struct _node {
	char* data;
	struct _node* link;
}Node;

typedef struct _stack {
	int count;
	Node* top;
}Stack;

Stack* create() { // 스택 구현
	Stack* stack = malloc(sizeof(Stack));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

int isEmpty(Stack* stack) { // 스택 비어있는지 확인
	return stack->count == 0;
}

int isFull(Stack* stack) { // 스택 다차있는지 확인
	return stack->count == MAX;
}

void push(Stack* stack, char* data) { // Push
	if (isFull(stack)) { // 스택이 다차있으면 push하지 않는다.
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
	if (isEmpty(stack)) { // 스택이 비어있으면 pop하지 않는다.
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
	scanf("%d", &str_cnt); // 처리해야할 식의 수를 받는다.
	for (int i = 0; i < str_cnt; i++) {
		scanf("%d", &str_len); // 식의 문자 수를 받는다.
		for (int j = 0; j < str_len; j++) {
			scanf(" %c", &ch);
			if (ch == '(') {
				push(stack, ch);
			}
			else if (ch == ')') { // 닫힌 괄호가 나오면 열린괄호 나올때까지 top, pop
				while (stack->top->data != '(') {
					fprintf(fp, "%c", top(stack));
					pop(stack);
				}
				pop(stack); // 마지막에 열린괄호도 pop
			}
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
				while (!isEmpty(stack)) {
					// *, /는 +, -보다 우선순위가 높기 때문에 이런 경우 스택에 그대로 쌓기 위해 pop하지 않고 break한다.
					if ((ch == '*' || ch == '/') && (top(stack) == '+' || top(stack) == '-')) {
						break;
					}
					// 열린괄호도 pop을 하면 안되기 때문에 break한다.
					else if (top(stack) == '(') {
						break;
					}
					// 나머지 경우는 스택의 연산자들을 top, pop시킨다.
					else {
						fprintf(fp, "%c", top(stack));
						pop(stack);
					}
				}
				// 반복문 종료 시 현재 연산자를 push
				push(stack, ch);
			}
			else {
				fprintf(fp, "%c", ch); // operand는 그대로 출력
			}
		}
		while (!isEmpty(stack)) { // 남은 스택의 연산자들을 전부 top, pop한다.
			fprintf(fp, "%c", top(stack));
			pop(stack);
		}
		fprintf(fp, "\n"); // 한 줄의 하나의 식만 나오도록 함
	}
	return 0;
}