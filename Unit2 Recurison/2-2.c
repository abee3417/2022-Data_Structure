#include <stdio.h>
// 피보나치 프로그램
long long int memo[100]; // memorization용 배열

void init(); // momorization 초기화
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

long long int fib(int n) { // n = 50이면 매우 크므로 long을 붙인다.
	if (n == 0 || n == 1) {
		return n;
	}
	if (memo[n] == 0) { // n = 50을 넣는다 하면 50부터 내려가며 피보나치합을 넣는다.
		memo[n] = (fib(n - 1) + fib(n - 2));
	}
	return memo[n];
	// 이런식으로 더한값을 memo에 저장해주면서
	// 다음번 계산할 때 재귀호출횟수를 줄일 수 있게 된다.
}

// n_50이 재귀를 너무많이 호출해서 작동이 안됨.
// 이를 위해 memorization을 이용