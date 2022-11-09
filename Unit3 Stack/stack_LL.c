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

Stack* create() { // 스택 구현 (Create Stack)
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
		// 스택이 다차있으면 push하지 않는다.
		return;
	}
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	// 먼저 data가 들어간 새로운 구조체를 만든다.
	if (!isEmpty(stack)) {
		// 만약 count가 0이면, 탑을 새로 정해줘야 하므로
		newNode->link = stack->top; // 링크를 탑으로 걸어준다
	}
	stack->top = newNode; // 탑을 업데이트, 갱신해준다.
	stack->count++;
	// 원래 링크를 수정하고 새로운 구초제 링크도 설정해준다.
}
Node* pop(Stack* stack) { // top을 지워주는 pop
	Node* topNode = stack->top;
	stack->top = stack->top->link;
	// 탑을 다음걸로 연결해주면 기존 탑은 연결해제 됨. (붕 뜬 느낌)
	stack->count--; // count 감소시킴
	return topNode;
}
Node* top(Stack* stack) { // top값을 리턴해주는 함수
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