/*Napisati funkciju koja racuna i vraca
f(x) = 10(x_1 − 1)^2 − sum_(i = 1)^(n - 1)(2 * x_(i+1)^2).
U svrhu testiranja u funkciji main() deklarirati polje realnih brojeva od 30 elemenata i naknadno
ga popuniti pseudo-slucajnim brojevima iz [−1.25, 1.25]  R. Pozvati funkciju s navedenim
poljem kao argumentom i ispisati na ekran povratnu vrijednost.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f(float *x, int n) {
	float prvi_dio = 10 * (x[0] - 1) * (x[0] - 1);// prvi dio je sve do sume
	//PAZI: matematicarima indeksi krecu od 1, nama od 0
	float suma = 0;
	int i;
	for (i = 0; i < n - 1; i++) {
	//ovo ce stati prije zadnjeg elementa jer gledamo 1 element unaprijed
		suma += 2 * x[i + 1] * x[i + 1];
	}
	return prvi_dio - suma;
}
int main() {
	float polje[30];

	srand((unsigned)time(NULL));

	int i;
	for (i = 0; i < 30; i++) {
		polje[i] = -1.25 + (float)rand() / RAND_MAX * (1.25 - (-1.25));
	}

	float rezultat = f(polje, 30);

	printf("%f", rezultat);
	return 0;
}
