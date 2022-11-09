#include <stdio.h>
void find(int i, int j, int max_y, int max_x, int ar[][3]);
int main() {
	int ar[4][3] = {
		1,0,1,
		1,1,1,
		0,1,1,
		1,0,1
	};
	printf("Hello\n");
	find(0, 0, 4, 3, ar);
	return 0;
}

void find(int i, int j, int max_y, int max_x, int ar[][3]) {
	ar[i][j] = -1;
	printf("%d, %d\n", i, j);
	if (i == max_y-1 && j == max_x-1) {
		printf("Find End\n");
	}

	if (j + 1 < max_x && i + 1 < max_y && ar[i + 1][j + 1] != 0) {
		find(i + 1, j + 1, max_x, max_y, ar);
	}
	if (j + 1 < max_x && ar[i][j+1] != 0) {
		find(i, j + 1, max_x, max_y, ar);
	}
	if (i + 1 < max_y && ar[i+1][j] != 01) {
		find(i + 1, j, max_x, max_y, ar);
	}
	if (i - 1 >= 0 && ar[i-1][j] != 0) {
		find(i - 1, j, max_x, max_y, ar);
	}
}