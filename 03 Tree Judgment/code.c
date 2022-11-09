#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int val;
	struct _node* left, * right;
}Node;

int sum = 0; // �� ����
int count = 0; // count
Node* queue[50] = { 0 }; // BFS�� Queue
int front, rear; // BFS Queue�� front, rear

void enq(Node* node) {
	if (rear == -1) front++;
	queue[++rear] = node;
}

Node* deq() {
	return queue[front++];
}

Node* addNode(Node* curNode, int val) { // BST Ʈ�� ������ �°� ��带 ����
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
	if (count < num) { // Num��ŭ ���ڸ� �����ش�.
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
		Node* node = deq(); // root�� ������
		if (count < num) { // Num��ŭ ���ڸ� �����ش�.
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
	scanf("%d", &r); // ó���ؾ��� Ʈ���� ���� �Է¹޴´�.
	for (int i = 0; i < r; i++) {
		scanf("%s", mode); // Ž������� �Է¹޴´�.
		scanf("%d", &num); // ���� ���� ������ �Է¹޴´�.
		while ((scanf("%d", &data)) == 1) { // ���ڸ� �Է¹��� ���� Ʈ���� insert
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
		tree = destroy(tree); // Ʈ�� �޸𸮸� ����ش�.
	}
	return 0;
}