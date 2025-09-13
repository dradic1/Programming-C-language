/*Napisati funkciju koja racuna i vraca
f(x) = 1 - x_1 + sum_(i=2)^(n-1)( (x_i)^(-2) + 0.1) + x_n,
U svrhu testiranja u funkciji main() deklarirati polje realnih brojeva od 10 elemenata i naknadno
ga popuniti pseudo-slucajnim brojevima iz [-5.12, 5.12] c R. Pozvati funkciju s navedenim
poljem kao argumentom i ispisati na ekran povratnu vrijednost.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ako imamo neke izraze sa kvadratima u nazivniku, bolje je radit sve u doubleu
//ako rijesimo sve preko floata, NIJE GRESKA

double f(double *x, int n) {
	int i;
	//matematicarima prvi element ima indeks 1, programerima je prvi indeks 0
	double prvi_dio = 1 - x[0];
	double drugi_dio = 0;
	for (i = 1; i < n - 1; i++) {
		drugi_dio += 1 / (x[i] * x[i]) + 0.1;
	}
	double treci_dio = x[n - 1];
	return prvi_dio + drugi_dio + treci_dio;
}

int main(void) {
	double polje[10];
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++) {
		polje[i] = -5.12 + (float)rand() / RAND_MAX * (5.12 - (-5.12));
	}
	double r = f(polje, 10);
	printf("%lf", r); //%lf je format za double
	return 0;
}