#include <stdio.h>
#include <stdlib.h>
FILE* fp;
int** maze; // 다른 함수에서 편리하게 사용하도록 전역변수로 선언
int maze_count = 0; // 미로 탈출 경우의 수를 카운팅하는 전역변수

int counting_nums(); // 텍스트 파일 내 숫자가 몇개 있는지 세어주는 함수
int input_nums(int* arr, int cnt); // 텍스트 파일 내 숫자들을 배열에 할당해주는 함수
void make_maze(int* arr, int num_m); // 미로를 만들고 경우의 수를 텍스트 파일에 작성해주는 함수
void find_paths(int x, int y, int max_x, int max_y); // 미로 탈출 경우의 수를 구해주는 함수

int main() {
	int* basic_arr;
	int num_count, num_of_maze;
	num_count = counting_nums() - 1; // 맨 앞 미로의 갯수는 빼준다.
	basic_arr = (int*)malloc(sizeof(int) * num_count); // counting_nums에서 카운팅한 count만큼 동적할당을 한다.
	num_of_maze = input_nums(basic_arr, num_count); // 텍스트파일의 수들을 입력받고, 미로의 총 수를 리턴받는다.
	make_maze(basic_arr, num_of_maze); // make_maze를 이용하여 미로를 구현한다.
	free(basic_arr);
	return 0;
}

int counting_nums() {
	char ch;
	int cnt = 0; // 동적할당에 필요한 메모리의 개수를 세기 위한 변수
	// 우선 입력받은 숫자를 알맞게 동적할당 하기 위해 파일을 한번 읽으며 숫자를 센다.
	fp = fopen("input.txt", "rt");
	while ((ch = fgetc(fp)) != EOF) {
		cnt++;
		fgetc(fp); // 숫자 다음엔 반드시 빈칸이나 엔터가 오고, 이들은 카운트할 필요가 없으므로 파일을 한번 더 읽어 넘긴다.
		// 만약 다음 순서에 빈칸이 아닌 숫자가 오면 파일을 다시 한번 더 읽어 넘겨 카운트가 제대로 되도록 한다. (두자릿수 판별)
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
	// 텍스트 파일 내 숫자들이 메모리 낭비없이 할당이 된다.
	fscanf(fp, "%d", &num); // 미로의 갯수는 배열에 넣지않고 따로 return 한다.
	for (int i = 0; i < cnt; i++) {
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);
	return num;
}

void make_maze(int* arr, int num_m) {
	int arr_seq1 = 0;
	int arr_seq2 = 2;
	// 반복문 사용을 위한 arr_seq 변수들
	fp = fopen("output.txt", "w"); // output.txt를 미리 열어둔다.

	// 미로의 경우의 수를 구하여 output.txt에 작성해준다.
	for (int i = 0; i < num_m; i++) {

		// maze를 이차원 배열 동적할당 해준다. Head Corruption Detected 방지를 위해 메모리 할당을 조금 여유롭게 한다.
		maze = (int**)malloc(sizeof(int*) * (arr[arr_seq1] + 1));
		maze[0] = (int*)malloc(sizeof(int) * (arr[arr_seq1] * arr[arr_seq1 + 1] + 1));
		for (int j = 1; j < arr[arr_seq1]; j++) {
			maze[j] = maze[j - 1] + arr[arr_seq1 + 1];
		}

		// maze 배열에 수들을 할당해준다.
		for (int m = 0; m < arr[arr_seq1]; m++) {
			for (int n = 0; n < arr[arr_seq1 + 1]; n++) {
				maze[m][n] = arr[arr_seq2];
				arr_seq2++;
			}
		}

		find_paths(0, 0, arr[arr_seq1], arr[arr_seq1 + 1]); // 0,0(왼쪽 맨 끝)부터 경우의 수를 찾기 시작한다.
		fprintf(fp, "%d\n", maze_count); // 결과작성

		free(maze); // 다음 미로 구현을 위한 free
		// 반복문 변수들도 맞게 조정해주고, maze_count는 다시 초기화해준다.
		arr_seq1 = arr_seq2;
		arr_seq2 += 2;
		maze_count = 0;
	}
	fclose(fp);
}

void find_paths(int x, int y, int max_x, int max_y) {

	/*
	함수의 원리
	0,0에서 시작하여, 4가지의 방향으로 길을 찾는다.
	왔던 길은 -1로 바꾸어 다시 못가게 막는다.
	방향에 따라 find_paths 함수를 재호출하며, 끝에 도달할때마다 카운팅한다.
	그리고 다시 돌아오면서 -1로 바꿨던 길을 원래대로 돌려놓으면
	또다른 경우의 수를 탐색할 수 있게 된다.
	이러한 원리로 재귀를 반복하며 함수는 끝이난다.
	*/

	if (maze_count == 1000000) { // 100만이 되면 함수를 탈출한다.
		return;
	}

	if (x == max_x - 1 && y == max_y - 1) {
		maze_count++; // 끝점에 도달할때 마다 경우의수를 1 증가시킨다.
	}

	else {
		maze[x][y] = -1; // 원래 있었던 곳을 -1로 바꾸므로써, 한번 갔던길을 다시 가지 않게 된다.
		// 대각선
		if (x >= 0 && y >= 0 && x < max_x - 1 && y < max_y - 1) {
			if (maze[x + 1][y + 1] == 1) {
				// 윗줄과 따로 나눠놓은 이유 : 만약 윗줄에 조건을 &&로 연결시킨다면, x가 2일때, maze[2+1] = maze[3]인데 이 값은 없기 때문에 예외 발생으로 오류가 나타난다.
				// 그래서 오류 해결 방안으로 조건을 따로 나눠놓았다. 그러면 x=2일때도, x < max_x - 1 을 충족시키지 못하므로 걸러진다.
				find_paths(x + 1, y + 1, max_x, max_y);
			}	
		}
		// 아래쪽
		if (x >= 0 && x < max_x - 1) {
			if (maze[x + 1][y] == 1) {
				find_paths(x + 1, y, max_x, max_y);
			}
		}
		// 오른쪽
		if (y >= 0 && y < max_y - 1) {
			if (maze[x][y + 1] == 1) {
				find_paths(x, y + 1, max_x, max_y);
			}
		}
		// 위쪽
		if (x >= 1 && x < max_x) {
			if (maze[x - 1][y] == 1) {
				find_paths(x - 1, y, max_x, max_y);
			}		
		}
	}
	maze[x][y] = 1; // 다시 불러오면서, 왔던 길들을 다시 1로 만들어줌으로써, 재탐색이 가능하게 한다.
}