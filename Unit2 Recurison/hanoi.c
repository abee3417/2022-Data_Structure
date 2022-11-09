#include <stdio.h>
void hanoi(int n, char source, char dest, char aux) {
	printf("* Towers : %d, %c, %c, %c *\n", n, source, dest, aux);
	if (n == 1) { // Base Case
		printf("Move from %c to %c\n", source, dest); // A���� C�� 1�� �̵�
	}
	else { // General Case
		hanoi(n - 1, source, aux, dest); // A���� B�� n - 1�� �̵�
		printf("Move from %c to %c\n", source, dest); // ���� ��Ϳ��� ������ ����� ǥ��
		hanoi(n - 1, aux, dest, source); // B���� C�� n - 1�� �̵�
	}
}
int main() {
	int num;
	printf("Input the number of disks in A >> ");
	scanf("%d", &num);
	hanoi(num, 'A', 'C', 'B'); // A���� C�� num��ŭ �������� �Ѵ�.
	return 0;
}