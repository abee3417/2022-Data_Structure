#include <stdio.h>
long long int memo[100] = {0}; // memoization
long long int fibo(int num) {
	if (num == 0 || num == 1) { // Base Case
		return num;
	}
	if (memo[num] == 0) { // General Case
		memo[num] = fibo(num - 1) + fibo(num - 2);
	}
	// memo[num]값이 없을 경우 더해준 값을 memo에 저장

	return memo[num];
	// 이미 memo[num]값이 존재할 경우 if문 들가서 계산할 필요 없이 바로 해당 값을 리턴
}
/*
<memoization 사용하지 않았을 경우>

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