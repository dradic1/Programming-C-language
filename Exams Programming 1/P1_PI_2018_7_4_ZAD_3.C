//ZADATAK 3
/*Napisati funkciju koja nasumicno premješta brojeve unutar prednog joj cjelobrojnog
polja. Premještanje se obavlja na sljedeci nacin: redom svaki element zamjenjuje s nasumično
odabranim elementom polja. Izdvojiti korak zamjene dva elementa polja u posebnu funkciju.
U svrhu testiranja u funkciji main() dinamicki zauzeti memoriju za 45 podataka tipa short
int (u potpunosti rukovati memorijom). Popuniti navedeno polje pseudo-slučajnim brojevima
iz [−100, 100] c Z. Pozvati navedenu funkciju s tim poljem kao argumentom i naknadno ga
ispisati na ekran.*/

#include <stdlib.h>

void zamijeni(short int *x, short int *y) {
	short int privremeni = *x;
	*x = *y;
	*y = privremeni;
}

void funkcija(short int *polje, int n) {
	int i;
	for (i = 0; i < n; i++) {
		int novi_index = rand() % n;
		zamijeni(&polje[i], &polje[novi_index]);
	}
}

int main(void) {
	short int *niz = (short int*) calloc(45,sizeof(short int));
	if (NULL == niz){
		printf("GRESKA");
		return 1;
	}

	int i;
	for (i = 0; i < 45; i++) {
		niz[i] = -100 + rand() % (100 + 1 - (-100));
	}

	funkcija(niz, 45);

	for (i = 0; i < 45; i++) {
		printf("%3d\t", niz[i]);
	}
	free(niz);
	return 0;
}