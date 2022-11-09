#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
    int value;
    int height;
    struct node* lLink;
    struct node* rLink;
}Node;

typedef struct Queue {
    int front;
    int rear;
    Node* arr[100];
}Queue;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}
int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}
void enQueue(Queue* queue, Node* data) {
    queue->arr[queue->front++] = data;
    queue->front = queue->front % 100;
}
Node* deQueue(Queue* queue) {
    Node* now;
    if (isEmpty(queue)) {
        return NULL;
    }
    now = queue->arr[queue->rear++];
    queue->rear = queue->rear % 100;
    return now;
}
Node* createNode(int value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->rLink = NULL;
    tmp->lLink = NULL;

    return tmp;
}
Node* insertBST(Node* root, int value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->rLink = NULL;
        root->lLink = NULL;
        root->value = value;
        return root;
    }
    else {
        if (value < root->value) {
            root->lLink = insertBST(root->lLink, value);
        }
        else if (value > root->value) {
            root->rLink = insertBST(root->rLink, value);
        }
    }
    return root;
}
void printNode(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    printNode(root->lLink);
    printNode(root->rLink);
}

//전위 순회 
void preOrder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->value);
    preOrder(root->lLink);
    preOrder(root->rLink);
}
//중위 순회 
void inOrder(Node* root) {
    if (root == NULL)
        return;
    inOrder(root->lLink);
    printf("%d ", root->value);
    inOrder(root->rLink);
}
//후위 순회 
void postOrder(Node* root) {
    if (root == NULL)
        return;
    postOrder(root->lLink);
    postOrder(root->rLink);
    printf("%d ", root->value);
}
//층간 순회
void levelOrder(Node* root) {
    if (root != NULL) {
        Queue* q = (Queue*)malloc(sizeof(Queue));
        Node* now = NULL;
        initQueue(q);
        enQueue(q, root);
        while (!isEmpty(q)) {
            now = deQueue(q);
            if (now->lLink != NULL) {
                enQueue(q, now->lLink);
            }
            if (now->rLink != NULL) {
                enQueue(q, now->rLink);
            }
            printf("%d ", now->value);
        }
    }
}

int getMax(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}
void setHeight(Node* node) {
    node->height = getMax(getHeight(node->lLink), getHeight(node->rLink)) + 1;
}
int getDiffernece(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->lLink) - getHeight(node->rLink);
}

Node* AVLrotateLOL(Node* node) {
    Node* tmp = node->lLink;
    node->lLink = tmp->rLink;
    tmp->rLink = node;
    setHeight(node);
    return tmp;
}
Node* AVLrotateROR(Node* node) {
    Node* tmp = node->rLink;
    node->rLink = tmp->lLink;
    tmp->lLink = node;
    setHeight(node);
    return tmp;
}
Node* AVLrotateLOR(Node* node) {
    Node* tmp = node->rLink;
    node->rLink = AVLrotateLOL(tmp);
    setHeight(node->rLink);
    return AVLrotateROR(node);
}
Node* AVLrotateROL(Node* node) {
    Node* tmp = node->lLink;
    node->lLink = AVLrotateROR(tmp);
    setHeight(node->lLink);
    return AVLrotateLOL(node);
}

Node* AVLbalance(Node* node) {
    int difference = getDiffernece(node);
    if (difference >= 2) { //left balance
        if (getDiffernece(node->lLink) >= 1) {
            node = AVLrotateLOL(node);
        }
        else {
            node = AVLrotateROL(node);
        }
    }
    else if (difference <= -2) { // right balance
        if (getDiffernece(node->rLink) <= -1) {
            node = AVLrotateROR(node);
        }
        else {
            node = AVLrotateLOR(node);
        }
    }
    setHeight(node);
    return node;
}
Node* insertAVL(Node* root, int value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->rLink = NULL;
        root->lLink = NULL;
        root->value = value;
        root->height = 1;
        return root;
    }

    if (value < root->value) {
        root->lLink = insertAVL(root->lLink, value);
    }
    else if (value > root->value) {
        root->rLink = insertAVL(root->rLink, value);
    }
    root = AVLbalance(root);

    return root;
}




int main(void) {
    Node* root = createNode(12);
    root = insertBST(root, 8);
    root = insertBST(root, 1);
    root = insertBST(root, 4);
    root = insertBST(root, 6);
    root = insertBST(root, 14);
    root = insertBST(root, 4);
    root = insertBST(root, 7);
    root = insertBST(root, 13);


    printf("inorder = ");
    inOrder(root);
    printf("\npreorder = ");
    preOrder(root);
    printf("\npostorder = ");
    postOrder(root);
    printf("\nlevelorder = ");
    levelOrder(root);
    printf("\n");
    printf("\n");

    Node* root1 = createNode(12);
    root1 = insertAVL(root1, 8);
    root1 = insertAVL(root1, 1);
    root1 = insertAVL(root1, 4);
    root1 = insertAVL(root1, 6);
    root1 = insertAVL(root1, 14);
    root1 = insertAVL(root1, 4);
    root1 = insertAVL(root1, 7);
    root1 = insertAVL(root1, 13);
    printf("inorder = ");
    inOrder(root1);
    printf("\npreorder = ");
    preOrder(root1);
    printf("\npostorder = ");
    postOrder(root1);
    printf("\nlevelorder = ");
    levelOrder(root1);
    printf("\n");

    return 0;
}

