#include <stdio.h>
void hanoi(int n, char source, char dest, char aux) {
	printf("* Towers : %d, %c, %c, %c *\n", n, source, dest, aux);
	if (n == 1) { // Base Case
		printf("Move from %c to %c\n", source, dest); // A에서 C로 1개 이동
	}
	else { // General Case
		hanoi(n - 1, source, aux, dest); // A에서 B로 n - 1개 이동
		printf("Move from %c to %c\n", source, dest); // 이전 재귀에서 움직인 결과를 표시
		hanoi(n - 1, aux, dest, source); // B에서 C로 n - 1개 이동
	}
}
int main() {
	int num;
	printf("Input the number of disks in A >> ");
	scanf("%d", &num);
	hanoi(num, 'A', 'C', 'B'); // A에서 C로 num만큼 움직여야 한다.
	return 0;
}