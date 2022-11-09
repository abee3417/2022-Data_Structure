#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int val;
	struct _node* left, * right;
}Node;

Node* addNode(Node* curNode, int val) { // addBST, Insertion
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

Node* deleteNode(Node* curNode, int target) {
	if (curNode == NULL) return NULL; // 삭제 과정 (NULL)
	if (target < curNode->val) { // 갱신 과정
		curNode->left = deleteNode(curNode->left, target);
	}
	else if (target > curNode->val) { // 갱신 과정
		curNode->right = deleteNode(curNode->right, target);
	}
	else {
		if (curNode->left == NULL) return curNode->right; // case1 : right도 NULL이므로 NULL리턴, case2 : right 리턴 (가장 큰 자식)
		else if (curNode->right == NULL) return curNode->left; // case3 : left 리턴 (가장 작은 자식)
		else { // case4
			Node* largest = curNode->left; // 계속해서 largest를 업데이트
			while (largest->right != NULL) { // right node가 없다 = 해당 node가 가장 큰 자식이다.
				largest = largest->right;
			}
			curNode->val = largest->val; // root의 val을 수정
			curNode->left = deleteNode(curNode->left, largest->val); // target을 다시 수정하여 그 node를 삭제해준다.
		}
	}
	return curNode;
}

void preOrder(Node* curNode) { // preorder traversals
	if (curNode == NULL) return;
	printf("%d\t", curNode->val);
	preOrder(curNode->left);
	preOrder(curNode->right);
}

void inOrder(Node* curNode) { // inorder traversals
	if (curNode == NULL) return;
	preOrder(curNode->left);
	printf("%d\t", curNode->val);
	preOrder(curNode->right);
}

void postOrder(Node* curNode) { // postorder traversals
	if (curNode == NULL) return;
	preOrder(curNode->left);
	preOrder(curNode->right);
	printf("%d\t", curNode->val);
}

int main() {
	Node* tree = NULL;
	tree = addNode(tree, 23);
	tree = addNode(tree, 18);
	tree = addNode(tree, 44);
	tree = addNode(tree, 12);
	tree = addNode(tree, 20);
	tree = addNode(tree, 35);
	tree = addNode(tree, 52);

	preOrder(tree); // 23 18 12 20 44 35 52
	printf("\n");
	inOrder(tree); // 18 12 20 23 44 35 52
	printf("\n");
	postOrder(tree); // 18 12 20 44 35 52 23
	printf("\n");

	tree = deleteNode(tree, 23);
	tree = deleteNode(tree, 18);
	preOrder(tree); // 20 12 44 35 52
	printf("\n");

	return 0;
}
