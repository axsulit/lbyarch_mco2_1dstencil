// this contains the c code
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h> 


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
		printf("Memory allocation failed!\n");
		return NULL;
	}

	srand(seed); 

	for (int i = 0; i < size; i++) {
		arr[i] = ((rand() % 2 == 0 ? 1.0 : -1.0) * (double)rand() / RAND_MAX) * 75;
	}

	return arr;
}


int main() {
	int n = 8; //1048576 [2^20], 16777216 [2^24], 268435456 [2^28] 

	printf("Generating random elements for array of size %d...\n", n);

	double* X = gen_arr(n, 96);

	int max = (n < 10) ? n : 10;


	printf("\nX --> ");
	for (int i = 0; i < max; i++) {
		printf("%.4f%s", X[i], (i + 1 != max) ? ", " : "...");
	}

	printf("\n");

	free(X);

	return 0;
}