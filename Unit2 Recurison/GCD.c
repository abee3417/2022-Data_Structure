#include <stdio.h>
int gcd(int n1, int n2) {
	if (n1 == 0) { // Base Case
		return n2;
	}
	else if (n2 == 0) { // Base Case
		return n1;
	}
	else { // General Case
		return gcd(n2, n1 % n2);
	}
}
int main() {
	int n1, n2;
	printf("Input two nums >> ");
	scanf("%d%d", &n1, &n2);
	int result = gcd(n1, n2);
	printf("Result is %d\n", result);
	return 0;
}