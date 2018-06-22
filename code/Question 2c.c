#include <stdio.h>

void printStr(char **ptr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", *ptr);
		ptr++;
	}
}

int main(void) {
	char *a[] = {"AAA", "BBB", "CCC"};
	
	int n = sizeof(a)/sizeof(a[0]);
	
	char **ptr;
	ptr = a;

	printStr(ptr, n);
	return 0;
}