#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
	int data;
	struct _node* left;
	struct _node* right;
	struct _node* link;
}Node;

Node* queue[100] = {0};
int front, rear;

void enq(Node* node) {
	if (rear == -1) {
		front++;
	}
	queue[++rear] = node;
}

Node* deq() {
	return queue[front++];
}

void BFT(Node* node) {
	printf("\n");
	front = rear = -1;
	enq(node);
	while (front <= rear) { // != NULL
		Node* cur = deq(); // root를 가져옴
		printf("%d ", cur->data);
		if (cur->left != NULL) {
			enq(cur->left);
		}
		if (cur->right != NULL) {
			enq(cur->right);
		}
	}
}

Node* makeNode(int data) {
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void DFT(Node* cur) {
	if (cur != NULL) {
		printf("%d ", cur->data);
		DFT(cur->left);
		DFT(cur->right);
		/*
		<inorder>
		DFT(cur->left);
		printf("%d ", cur->data);
		DFT(cur->right);
		*/
		/*
		<postorder>
		DFT(cur->left);
		DFT(cur->right);
		printf("%d ", cur->data);
		*/
	}
}



int main() {
	Node* root = makeNode(5); // root의 데이터는 5
	Node* n1 = makeNode(3);
	Node* n2 = makeNode(1);
	Node* n3 = makeNode(-3);
	Node* n4 = makeNode(100); // 우선 노드를 전부 생성

	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4; // 노드를 연결

	DFT(root); // DFT : 자식별로 traverse
	BFT(root); // BFT : Level별로 traverse

	return 0;
}

/*
typedef struct _queue {
	int count;
	Node* front;
	Node* rear;
}Queue;

Queue* create() {
	Queue* newQ = malloc(sizeof(Queue));
	newQ->count = 0;
	newQ->front = NULL;
	newQ->rear = NULL;
	return newQ;
}

void enqueue(Queue* q, Node* cur) {
	Node* new = malloc(sizeof(Node));
	new->left = NULL;
	new->right = NULL;
	if (q->count == 0) {
		q->front = new;
	}
	else {
		q->rear->link = new;
	}
	q->rear = new;
	q->count++;
}

Node* dequeue(Queue* q) {
	Node* temp = q->front;
	if (q->count == 1) {
		q->rear = NULL;
	}
	q->front = q->front->link; // count=1이어도 이때 front가 null이 된다.
	q->count--;
	return temp;
}
*/