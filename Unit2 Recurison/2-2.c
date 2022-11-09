#include <stdio.h>
// �Ǻ���ġ ���α׷�
long long int memo[100]; // memorization�� �迭

void init(); // momorization �ʱ�ȭ
long long int fib(int n);
int main() {
	int n_10 = fib(10);
	int n_20 = fib(20);
	long long int n_50 = fib(50);
	printf("10th : %d, 20th : %d, 50th : %lld\n", n_10, n_20, n_50);
	return 0;
}

void init() {
	for (int i = 0; i < 100; i++) {
		memo[i] = 0;
	}
}

long long int fib(int n) { // n = 50�̸� �ſ� ũ�Ƿ� long�� ���δ�.
	if (n == 0 || n == 1) {
		return n;
	}
	if (memo[n] == 0) { // n = 50�� �ִ´� �ϸ� 50���� �������� �Ǻ���ġ���� �ִ´�.
		memo[n] = (fib(n - 1) + fib(n - 2));
	}
	return memo[n];
	// �̷������� ���Ѱ��� memo�� �������ָ鼭
	// ������ ����� �� ���ȣ��Ƚ���� ���� �� �ְ� �ȴ�.
}

// n_50�� ��͸� �ʹ����� ȣ���ؼ� �۵��� �ȵ�.
// �̸� ���� memorization�� �̿�