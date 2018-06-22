#include <stdio.h>
#include <stdlib.h>

//Added function for printing the bits of an int
void print_int_bits(int value) {
	int intSize = sizeof(int);
	for (int i = 1; i <= intSize; ++i) {
		int byte = (value >> (intSize*8 - (i*8))) & 0xFF;
		for (int i = 0; i < 8; ++i) printf("%d", (byte >> (7-i)) & 0x01);
		printf(" ");
	}
	printf("\n");
}

int main(void) {
	int age[] = {8, 2, 6, 12, 15, 11, 10, 7, 0, 1, 4, 5, 13, 9, 3, 14};
	int numAges = sizeof(age)/sizeof(int);
	int m = numAges/8 + (numAges%8? 1:0);

	int* ageInt = calloc(m, sizeof(int));

	for (int i = 0, count = 0; i < m; ++i) {
		for (int j = 0; j < 8 && count++ < numAges; ++j) {
			ageInt[i] += (age[(i*8)+j] & 0xFF) << (28-(j*4));
		}
	}


	//Added code for printing out the int bits and the values read back out
	for (int i = 0; i < m; ++i) {
		print_int_bits(ageInt[i]);
		for (int j = 0; j < 8; ++j) {
			printf("%4d", ((ageInt[i] >> (28 - (j*4))) & 0x0F));
			if (j%2) printf(" ");
		}
		printf("\n");
	}

	return 0;
}