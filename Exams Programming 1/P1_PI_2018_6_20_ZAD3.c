/*Napisati funkciju koja odreduje i vraca broj predanog joj cjelobrojnog polja s najvecom
aritmetickom sredinom znamenki. Izdvojiti korak izracuna aritmeticke sredine znamenki
pojedinog broja u posebnu funkciju. U svrhu testiranja u funkciji main() dinamcki zauzeti
memoriju za 100 podataka tipa long int (u potpunosti rukovati memorijom). Popuniti navedeno
polje pseudo-slucajnim brojevima iz [−1500, 12500] c Z. Pozvati funkciju s njim kao
argumentom te ispisati na ekran povratnu vrijednost.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float arit_sred(long int n) {
	int br_znam = 0;
	int suma = 0;
	int znam;
	while (n != 0) {
		br_znam++;
		znam = n % 10;
		suma += znam;
		n /= 10;
	}
	float as = (float)suma / br_znam;
	//kada dijelimo 2 inta, jedan uvijek tretiramo kao float (castamo)
	//jer rezultat dijeljenja 2 inta je uvijek cijeli broj, cak i ako se sprema
	//u float

	return as;
}

long int funkcija(long int *polje, int n) {
	long int najveci = polje[0];
	int i;
	for (i = 0; i < n; i++) {
		if (arit_sred(polje[i]) > arit_sred(najveci)) {
			najveci = polje[i];
		}
	}
	return najveci;
}

int main(void) {
	long int *a = (long int*)malloc(100 * sizeof(long int));
	if (NULL == a) {
		return 1; //malloc nije uspio pa prekidamo main i ostatak programa
	}
	int i;
	for (i = 0; i < 100; i++) {
		a[i] = -1500 + rand() % (12500 + 1 - (-1500));
	}

	long int n = funkcija(a, 100);
	printf("%ld", n);

	free(a);
	return 0;
}