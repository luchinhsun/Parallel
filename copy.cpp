#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void initial(double *a, int M, int N);
void print_matrix(double *a, int M, int N);

int main()
{
	int M, N;
	printf("\n");
	printf(" Input M = ");
	scanf("%d", &M);
	printf(" Input N = ");
	scanf("%d", &N);

	int i, j, k;
	double *a, *b, *c;
	a = (double *) malloc(M*N*sizeof(double));
	b = (double *) malloc(M*N*sizeof(double));
	c = (double *) malloc(M*N*sizeof(double));

	double t1, t2;

	initial(a, M, N);
	//print_matrix(a, M, N);

	t1 = clock();

	for (i=0; i<M*N; i++)
	b[i] = a[i];

	t2 = clock();

	//print_matrix(b, M, N);
	printf("\n Time in normal = %f s \n\n"
		,(t2 - t1)/CLOCKS_PER_SEC);

        t1 = clock();

	#pragma acc data copyin(a[0:M*N]) copyout(c[0:M*N])
	#pragma acc parallel loop independent
        for (i=0; i<M*N; i++)
        c[i] = a[i];

        t2 = clock();

        //print_matrix(c, M, N);
        printf("\n Time in normal = %f s \n\n"
                ,(t2 - t1)/CLOCKS_PER_SEC);
	return 0;

}

void initial(double *a, int M, int N)
{
	int i;
	for (i=0; i<M*N; i++)
	a[i] = i;
}

void print_matrix(double *a, int M, int N)
{
	int i, j;
	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
		printf(" %f ", a[i*N+j]);

		printf("\n");
	}
	printf("\n");
}
