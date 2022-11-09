#include <stdio.h>

int N, R, C;
int maze[50][50];
int visited[50][50];
void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			maze[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
int path(int r, int c) {
	if (r == R - 1 && c == C - 1) {
		return 1;
	}
	visited[r][c] = 1;

	int ret = 0;
	// go right
	if (c + 1 < C && maze[r][c + 1] == 1 && visited[r][c + 1] == 0) {
		ret = path(r, c + 1);
	}
	// go down
	if (r + 1 < R && maze[r + 1][c] == 1 && visited[r + 1][c] == 0) {
		ret = path(r + 1, c);
	}
	ret = path(r + 1, c);
	visited[r][c] = 0;

	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		init();
		scanf("%d %d", &R, &C);
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				scanf("%d", &maze[r][c]);
			}
		}
		printf("%d\n", path(0, 0));
	}
	
	return 0;
}