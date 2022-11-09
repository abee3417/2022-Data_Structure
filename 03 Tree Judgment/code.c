#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int val;
	struct _node* left, * right;
}Node;

int sum = 0; // 합 변수
int count = 0; // count
Node* queue[50] = { 0 }; // BFS용 Queue
int front, rear; // BFS Queue의 front, rear

void enq(Node* node) {
	if (rear == -1) front++;
	queue[++rear] = node;
}

Node* deq() {
	return queue[front++];
}

Node* addNode(Node* curNode, int val) { // BST 트리 구조에 맞게 노드를 삽입
	if (curNode == NULL) {
		Node* newNode = malloc(sizeof(Node));
		newNode->val = val;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
	if (val < curNode->val) {
		curNode->left = addNode(curNode->left, val);
	}
	else {
		curNode->right = addNode(curNode->right, val);
	}
	return curNode;
}

void DFS(Node* curNode, int num) {
	if (curNode == NULL) return;
	if (count < num) { // Num만큼 숫자를 더해준다.
		sum += curNode->val;
		count += 1;
	}
	DFS(curNode->left, num);
	DFS(curNode->right, num);
}

void BFS(Node* curNode, int num) {
	front = rear = -1;
	enq(curNode);
	while (front <= rear) { // != NULL
		Node* node = deq(); // root를 가져옴
		if (count < num) { // Num만큼 숫자를 더해준다.
			sum += node->val;
			count += 1;
		}
		if (node->left != NULL) {
			enq(node->left);
		}
		if (node->right != NULL) {
			enq(node->right);
		}
	}
}

Node* destroy(Node* curNode) {
	if (curNode == NULL) {
		return NULL;
	}
	else {
		destroy(curNode->left);
		destroy(curNode->right);
		free(curNode);
	}
}

int main() {
	Node* tree = NULL;
	int r, num, data;
	char mode[10];
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &r); // 처리해야할 트리의 수를 입력받는다.
	for (int i = 0; i < r; i++) {
		scanf("%s", mode); // 탐색방법을 입력받는다.
		scanf("%d", &num); // 더할 수의 개수를 입력받는다.
		while ((scanf("%d", &data)) == 1) { // 숫자를 입력받을 동안 트리에 insert
			tree = addNode(tree, data);
		}
		if (mode[0] == 'D' && mode[1] == 'F' && mode[2] == 'S' && mode[3] == ':') { // DFS
			DFS(tree, num);
		}
		else if (mode[0] == 'B' && mode[1] == 'F' && mode[2] == 'S' && mode[3] == ':') { // BFS
			BFS(tree, num);
		}
		printf("%d\n", sum);
		sum = count = 0;
		tree = destroy(tree); // 트리 메모리를 비워준다.
	}
	return 0;
}