#include <stdio.h>
int factorial(int n) {
	if (n == 0) { // Base Case
		return 1;
	}
	else { // General Case
		return (n * factorial(n - 1));
	}
}
int main() {
	int num;
	printf("Input num >> ");
	scanf("%d", &num);
	int result = factorial(num);
	printf("Result is %d\n", result);
	return 0;
}