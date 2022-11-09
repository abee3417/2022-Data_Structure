#include <stdio.h>
long long int memo[100] = {0}; // memoization
long long int fibo(int num) {
	if (num == 0 || num == 1) { // Base Case
		return num;
	}
	if (memo[num] == 0) { // General Case
		memo[num] = fibo(num - 1) + fibo(num - 2);
	}
	// memo[num]���� ���� ��� ������ ���� memo�� ����

	return memo[num];
	// �̹� memo[num]���� ������ ��� if�� �鰡�� ����� �ʿ� ���� �ٷ� �ش� ���� ����
}
/*
<memoization ������� �ʾ��� ���>

if (num == 0 || num == 1) { // Base Case
	return num;
	}
else { // General Case
	return (fibo(num - 1) + fibo(num - 2));
}
*/
int main() {
	int num;
	printf("Input num >> ");
	scanf("%d", &num);
	printf("Result is %lld\n", fibo(num));
	return 0;
}