#include <stdio.h>
#include <stdlib.h>
FILE* fp;
int** maze; // �ٸ� �Լ����� ���ϰ� ����ϵ��� ���������� ����
int maze_count = 0; // �̷� Ż�� ����� ���� ī�����ϴ� ��������

int counting_nums(); // �ؽ�Ʈ ���� �� ���ڰ� � �ִ��� �����ִ� �Լ�
int input_nums(int* arr, int cnt); // �ؽ�Ʈ ���� �� ���ڵ��� �迭�� �Ҵ����ִ� �Լ�
void make_maze(int* arr, int num_m); // �̷θ� ����� ����� ���� �ؽ�Ʈ ���Ͽ� �ۼ����ִ� �Լ�
void find_paths(int x, int y, int max_x, int max_y); // �̷� Ż�� ����� ���� �����ִ� �Լ�

int main() {
	int* basic_arr;
	int num_count, num_of_maze;
	num_count = counting_nums() - 1; // �� �� �̷��� ������ ���ش�.
	basic_arr = (int*)malloc(sizeof(int) * num_count); // counting_nums���� ī������ count��ŭ �����Ҵ��� �Ѵ�.
	num_of_maze = input_nums(basic_arr, num_count); // �ؽ�Ʈ������ ������ �Է¹ް�, �̷��� �� ���� ���Ϲ޴´�.
	make_maze(basic_arr, num_of_maze); // make_maze�� �̿��Ͽ� �̷θ� �����Ѵ�.
	free(basic_arr);
	return 0;
}

int counting_nums() {
	char ch;
	int cnt = 0; // �����Ҵ翡 �ʿ��� �޸��� ������ ���� ���� ����
	// �켱 �Է¹��� ���ڸ� �˸°� �����Ҵ� �ϱ� ���� ������ �ѹ� ������ ���ڸ� ����.
	fp = fopen("input.txt", "rt");
	while ((ch = fgetc(fp)) != EOF) {
		cnt++;
		fgetc(fp); // ���� ������ �ݵ�� ��ĭ�̳� ���Ͱ� ����, �̵��� ī��Ʈ�� �ʿ䰡 �����Ƿ� ������ �ѹ� �� �о� �ѱ��.
		// ���� ���� ������ ��ĭ�� �ƴ� ���ڰ� ���� ������ �ٽ� �ѹ� �� �о� �Ѱ� ī��Ʈ�� ����� �ǵ��� �Ѵ�. (���ڸ��� �Ǻ�)
		if (ch != 32 && ch != 10) {
			fgetc(fp);
		}
	}
	fclose(fp);
	return cnt;
}

int input_nums(int* arr, int cnt) {
	int num;
	fp = fopen("input.txt", "rt");
	// �ؽ�Ʈ ���� �� ���ڵ��� �޸� ������� �Ҵ��� �ȴ�.
	fscanf(fp, "%d", &num); // �̷��� ������ �迭�� �����ʰ� ���� return �Ѵ�.
	for (int i = 0; i < cnt; i++) {
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);
	return num;
}

void make_maze(int* arr, int num_m) {
	int arr_seq1 = 0;
	int arr_seq2 = 2;
	// �ݺ��� ����� ���� arr_seq ������
	fp = fopen("output.txt", "w"); // output.txt�� �̸� ����д�.

	// �̷��� ����� ���� ���Ͽ� output.txt�� �ۼ����ش�.
	for (int i = 0; i < num_m; i++) {

		// maze�� ������ �迭 �����Ҵ� ���ش�. Head Corruption Detected ������ ���� �޸� �Ҵ��� ���� �����Ӱ� �Ѵ�.
		maze = (int**)malloc(sizeof(int*) * (arr[arr_seq1] + 1));
		maze[0] = (int*)malloc(sizeof(int) * (arr[arr_seq1] * arr[arr_seq1 + 1] + 1));
		for (int j = 1; j < arr[arr_seq1]; j++) {
			maze[j] = maze[j - 1] + arr[arr_seq1 + 1];
		}

		// maze �迭�� ������ �Ҵ����ش�.
		for (int m = 0; m < arr[arr_seq1]; m++) {
			for (int n = 0; n < arr[arr_seq1 + 1]; n++) {
				maze[m][n] = arr[arr_seq2];
				arr_seq2++;
			}
		}

		find_paths(0, 0, arr[arr_seq1], arr[arr_seq1 + 1]); // 0,0(���� �� ��)���� ����� ���� ã�� �����Ѵ�.
		fprintf(fp, "%d\n", maze_count); // ����ۼ�

		free(maze); // ���� �̷� ������ ���� free
		// �ݺ��� �����鵵 �°� �������ְ�, maze_count�� �ٽ� �ʱ�ȭ���ش�.
		arr_seq1 = arr_seq2;
		arr_seq2 += 2;
		maze_count = 0;
	}
	fclose(fp);
}

void find_paths(int x, int y, int max_x, int max_y) {

	/*
	�Լ��� ����
	0,0���� �����Ͽ�, 4������ �������� ���� ã�´�.
	�Դ� ���� -1�� �ٲپ� �ٽ� ������ ���´�.
	���⿡ ���� find_paths �Լ��� ��ȣ���ϸ�, ���� �����Ҷ����� ī�����Ѵ�.
	�׸��� �ٽ� ���ƿ��鼭 -1�� �ٲ�� ���� ������� ����������
	�Ǵٸ� ����� ���� Ž���� �� �ְ� �ȴ�.
	�̷��� ������ ��͸� �ݺ��ϸ� �Լ��� ���̳���.
	*/

	if (maze_count == 1000000) { // 100���� �Ǹ� �Լ��� Ż���Ѵ�.
		return;
	}

	if (x == max_x - 1 && y == max_y - 1) {
		maze_count++; // ������ �����Ҷ� ���� ����Ǽ��� 1 ������Ų��.
	}

	else {
		maze[x][y] = -1; // ���� �־��� ���� -1�� �ٲٹǷν�, �ѹ� �������� �ٽ� ���� �ʰ� �ȴ�.
		// �밢��
		if (x >= 0 && y >= 0 && x < max_x - 1 && y < max_y - 1) {
			if (maze[x + 1][y + 1] == 1) {
				// ���ٰ� ���� �������� ���� : ���� ���ٿ� ������ &&�� �����Ų�ٸ�, x�� 2�϶�, maze[2+1] = maze[3]�ε� �� ���� ���� ������ ���� �߻����� ������ ��Ÿ����.
				// �׷��� ���� �ذ� ������� ������ ���� �������Ҵ�. �׷��� x=2�϶���, x < max_x - 1 �� ������Ű�� ���ϹǷ� �ɷ�����.
				find_paths(x + 1, y + 1, max_x, max_y);
			}	
		}
		// �Ʒ���
		if (x >= 0 && x < max_x - 1) {
			if (maze[x + 1][y] == 1) {
				find_paths(x + 1, y, max_x, max_y);
			}
		}
		// ������
		if (y >= 0 && y < max_y - 1) {
			if (maze[x][y + 1] == 1) {
				find_paths(x, y + 1, max_x, max_y);
			}
		}
		// ����
		if (x >= 1 && x < max_x) {
			if (maze[x - 1][y] == 1) {
				find_paths(x - 1, y, max_x, max_y);
			}		
		}
	}
	maze[x][y] = 1; // �ٽ� �ҷ����鼭, �Դ� ����� �ٽ� 1�� ����������ν�, ��Ž���� �����ϰ� �Ѵ�.
}