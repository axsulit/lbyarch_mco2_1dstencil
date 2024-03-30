// this contains the c code
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h> 


/**
 * @brief Computes the 1d stencil operation on the input array X, stores the result in Y, and displays it.
 *
 * @param n The size of the input array X.
 * @param X Pointer to the input array.
 * @param Y Pointer to the output array to store the result.
 */
void dstencil(int n, double* X, double* Y) {
	printf("(C) Output Y -> ");
	int max = (n < 10) ? n : 10;

	for (int i = 0; i < n; i++) {
		Y[i] = 0;
		for (int j = i; j <= i + 6; j++) {
			Y[i] += X[j];
		}
	}
	for (int i = 0; i < max; i++) {
		printf("%.4f%s", Y[i], (i + 1 != max) ? ", " : " . . .");
	}
}

/**
 * @brief Generates an array of random double values within the range [-75, 75].
 *
 * @param size The size of the array to be generated.
 * @param seed The seed value for the random number generator.
 * @return A pointer to the dynamically allocated array of random double values,
 *         or NULL if memory allocation fails.
 */
double* gen_arr(int size, int seed) {
	double* arr = malloc(size * sizeof(double));
	if (arr == NULL) {
		printf("malloc failed!\n");
		return NULL;
	}

	srand(seed); 

	for (int i = 0; i < size; i++) {
		arr[i] = ((rand() % 2 == 0 ? 1.0 : -1.0) * (double)rand() / RAND_MAX) * 75;
	}

	return arr;
}


int main() {
	int n = 20; //1048576 [2^20], 16777216 [2^24], 268435456 [2^28] 

	printf("Generating random elements for array of size %d . . .\n", n);

	double* X = gen_arr(n, 96);
	n = n - 6;
	double* Y = malloc(n * sizeof(double));

	/*
	// print X
	printf("\nX -> ");
	for (int i = 0; i < max; i++) {
		printf("%.4f%s", X[i], (i + 1 != max) ? ", " : "...");
	}*/

	printf("\n");

	dstencil(n, X, Y);

	free(X);
	free(Y);
	return 0;
}