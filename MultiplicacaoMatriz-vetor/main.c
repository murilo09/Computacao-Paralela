#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *Pth_mat_vect(void* rank);

int thread_count = 5;
int m = 5;
int n = 5;

int y[5];
int x[5] = {6, 9, 8, 2, 4};
int A[5][5] = {{55, 40, 13, 20, 86},
			   {37, 27, 44, 30, 48},
			   {25, 35, 83, 85, 94},
			   {28, 34, 71, 99, 67},
			   {47, 90, 41, 66, 69}};

int main() {
	long thread;
	pthread_t* thread_handles;
	thread_handles = malloc(thread_count * sizeof(pthread_t));

	for (thread = 0; thread < thread_count; thread++)
		pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);

	for (thread = 0; thread < thread_count; thread++)
		pthread_join(thread_handles[thread], NULL);

	free(thread_handles);

	printf("y = (%d, %d, %d, %d, %d)\n", y[0], y[1], y[2], y[3], y[4]);

	return 0;
}


void *Pth_mat_vect(void* rank) {
	long my_rank = (long) rank;
	int i, j;
	int local_m = m/thread_count;
	int my_first_row = my_rank * local_m;
	int my_last_row = (my_rank + 1) * local_m - 1;

	for (i = my_first_row; i <= my_last_row; i++) {
		y[i] = 0.0;
		for (j = 0; j < n; j++)
			y[i] += A[i][j] * x[j];
	}

	return NULL;
} /* Pth_mat_vect */