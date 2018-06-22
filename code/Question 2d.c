#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 3) return 1;

	FILE *f1 = fopen(*(argv+1), "r");
	if (f1 == NULL) return 1;

	FILE *f2 = fopen(*(argv+2), "w");
	if (f2 == NULL) return 1;

	while (1) {
		char c = getc(f1);
		if (feof(f1)) break;
		if (c<'9'+1 && c>'0' && (c-'0')%2 == 1) continue;
		putc(c, f2);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}