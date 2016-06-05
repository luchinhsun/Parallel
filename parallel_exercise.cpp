/*******************************************************************
*
*		Subject : Exercise for Paralle
*		Date : 2016/06/05
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_vector(double *a, int N);
double dot(double *a, double *b, int N);

int main ()
{
	printf("\n");
	int N;
	printf(" Please enter N = ");
	scanf("%d", &N);
	printf("\n");

	int i;
	double *x, *y;
	x = (double *) malloc(N*sizeof(double));
	y = (double *) malloc(N*sizeof(double));
	double q, temp, t1, t2;
	q = 0.0;
	temp = 0.0;



	for (i=0; i<N; i++)
	x[i] = i;
	//printf(" x = ");
	//print_vector(x, N);

	for (i=0; i<N; i++)
	y[i] = i+2;
	//printf(" y = ");
	//print_vector(y, N);



	t1 = clock();

	temp = sqrt(dot(x, x, N));

	for (i=0; i<N; i++)
	x[i] = x[i] / temp;

	q = dot(y, x, N);

	for (i=0; i<N; i++)
	y[i] = y[i] - q * x[i];

	t2 = clock();



	//printf(" Ans = ");
	//print_vector(y, N);

	printf(" Time = %.10f s\n",(t2 - t1)/CLOCKS_PER_SEC);

	printf("\n");
	return 0;
}

void print_vector(double *a, int N)
{
	int i;
	for (i=0; i<N; i++)
	printf(" %f ",a[i]);

	printf("\n");
}

double dot(double *a, double *b, int N)
{
	int i, j;
	double temp;

	for (i=0; i<N; i++)
	temp += a[i] * b[i];

	return temp;
}
