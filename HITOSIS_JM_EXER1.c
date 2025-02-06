#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100
#define BASE 1

void std(int *X, int i, int j);
void printMatrix(int *X, int i, int j);
void printStd(float *d, int N);

int main (int argc, char *argv[]){
  if (argc < 2) {
    printf("Expected N! Please try again!\n");
    printf("USAGE: ./<program_name> <N>\n");
    printf("SAMPLE: ./a.out 100\n");
    return 1;
  }

  int N = atoi(argv[1]);
  int *X = (int *) malloc(sizeof(int)*N*N);
  clock_t time_before, time_after;

  // initialize matrix
  for (int i = 0; i < N*N; i++) 
    do X[i] = (rand() % (MAX - BASE)) + BASE;
    while (X[i] == 0);

  // printMatrix(X, N, N);

  time_before = clock();
  std(X, N, N);
  time_after = clock();

  // printStd(d, N);
	printf("Time elapsed: %0.6f\n", (float)(time_after - time_before)/(float)CLOCKS_PER_SEC);
  free(X);

  return 0;
}

void printMatrix(int *X, int i, int j) {
  for (int k = 0; k < i*j; k++){
    printf("%d\t", X[k]);
    if ((k+1)%j == 0) printf("\n");
  }
}

void printStd(float *d, int N) {
  for (int k = 0; k < N; k++){
    printf("%lf\t", d[k]);
  }
  printf("\n");
}

void std(int *X, int row, int column){
  float *d = (float *) malloc(sizeof(float)*column);
  for (int j = 0; j < column; j++){
    d[j] = 0;
    int a = 0;
    for (int k = 0; k < row; k++){
      a += X[k*row + j];
    }
    a /= column;
    for (int i = 0; i < row; i++){
      d[j] += (X[i*row + j]- a) * (X[i*row + j]- a);
    }
    d[j] = sqrt(d[j]/column);
  }
    // 1. find a_j
    // 2. find d_j
  // printStd(d, column);
  free(d);
}
