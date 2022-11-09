#include <stdio.h>
#define SIZE 100

int T; // test cases
int N; // nodes
int graph[SIZE][SIZE];
int visited[SIZE];

int q[SIZE];
int front, rear;

void init() {
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			graph[r][c] = -1;
		}
		visited[r] = 0;
		q[r] = -1;
	}
	front = rear = -1;
}

void enq(int v) {
	q[++rear] = v;
	if (front == -1) {
		front = 0;
	}
}

int deq() {
	int ret = q[front++];
	if (front > rear) { // q가 empty상태이므로 -1로 초기화
		front = rear = -1;
	}
	return ret;
}

int isEmptyQ() {
	return rear == -1;
}

void readGraph() {
	scanf("%d", &N);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			scanf("%d", &graph[r][c]);
		}
	}
}

void bfs(int v) { // v is a starting point
	enq(v);
	visited[v] = 1;
	while (!isEmptyQ()) {
		int i = deq();
		printf("%d--> ", i);
		for (int j = 0; j < N; j++) { // j is i's neighbor
			if (visited[j] == 1 || graph[i][j] == 0) { // 이미 방문했을 경우
				continue;
			}
			enq(j);
			visited[j] = 1;
		}
	}
}

void bfsAll() {
	for (int n = 0; n < N; n++) {
		if (visited[n] == 0) { // 아직 방문하지 않았을 때
			bfs(n);
		}
	}
}

void process() {
	init();
	readGraph();
	bfsAll();
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		process();
	}
}