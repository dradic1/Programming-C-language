/*Napisati funkciju koja mijenja vrijednosti elemenata predanog joj polja realnih brojeva
na sljedeci nacin: redom postavlja svaki element na aritmeticku sredinu ostalih elemenata
koji slijede poslije njega. U svrhu testiranja u funkciji main() dinamcki zauzeti memoriju za 120
podataka tipa double (u potpunosti rukovati memorijom). Dobiveno polje popuniti pseudoslucajenim
brojevima iz [−10, 10] c R. Pozvati funkciju s navedenim poljem kao argumentom
te ga naknadno ispisati na ekran.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funkcija(double *polje, int n) {
	//sve radimo na postojecim podacima pa ide void
	int i, j;
	double suma = 0;
	double broj_poslije = 1;
	for (i = 0; i < n; i++) {
		//ova petlja sluzi da prodjemo kroz svaki broj i stavimo mu novu vrijednost
		//nakon sto sa iducom for petljom prodjemo sve elemente poslije njega i izracunamo
		//njihovu sumu
		//nakon toga racunamo aritmeticku sredinu i to spremamo u trenutni element
		for (j = i + 1; j < n; j++) {
			suma += polje[j];
		}
		polje[i] = suma / (n - i + 1); //n - i + 1 je broj elemenata poslije i-tog elementa
	}
}

int main(void) {
	double *a = (double*)malloc(120 * sizeof(double));
	if (NULL == a) {
		return 1;//dogodila se greska, prekini main
	}
	srand((unsigned)time(NULL));
	int i;
	for (i = 0; i < 120; i++) {
		a[i] = -10 + (float)rand() / RAND_MAX * (10 - (-10));
	}
	funkcija(a, 120);
	for (i = 0; i < 120; i++) {
		printf("%.2lf ", a[i]);
	}
	free(a);
	return 0;
}