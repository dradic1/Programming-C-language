//ZADATAK 4
/*Napisati funkciju koja racuna i vraca
	f(x) = e^(0.1 * (x_1 - x_n)) + product_(i = 2)^(n - 2)(|x_i b x_(i + 1)|)
U svrhu testiranja u funkciji main() deklarirati polje realnih brojeva od 20
elemenata i naknadno ga popuniti pseudo-slucajnim brojevima iz [b10, 10] c R.
Pozvati funkciju s navedenim poljem kao argumentom i ispisati na ekran povratnu
vrijednost. Funkcija za izracun vrijednosti eksponencijalne funkcije [f(z) = e^z]
opisana je u zaglavnoj datoteci math.h, a prototip joj je double exp(double z).*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double aps(double broj) {
	if (broj < 0)
		return -1 * broj;
	else
		return broj;
}

double f(double *x, int n) {
	double rezultat = 0;
	double prvi_dio = exp(0.1 * (x[0] - x[n - 1]));
	double drugi_dio = 1;
	int i;
	for (i = 1; i < n - 1; i++) {
		drugi_dio *= aps(x[i] - x[i + 1]);
	}
	rezultat = prvi_dio + drugi_dio;
	return rezultat;
}

int main(void) {
	double *polje = (double*)calloc(20, sizeof(double));

	if (NULL == polje) {
		printf("GRESKA");
		return 1;
	}

	srand((unsigned)time(NULL));

	int i;
	for (i = 0; i < 20; i++) {
		polje[i] = -10 + (float)rand() / RAND_MAX * (10 - (-10));
	}

	double rez = f(polje, 20);
	printf("%lf", rez);
	free(polje);
	return 0;
}