/*A GRUPA 2.
Napisati funkciju koja određuje i vraca s koliko je svojih znamenki predani joj cijeli
broj djeljiv. U svrhu testiranja u funkciji main() pozvati napisanu funkciju s brojem 1806 kao
argumentom i na ekran ispisati povratnu vrijednost.
*/
#include <stdio.h>

int funkcija(int broj) {
	int broj_znamenki = 0;
	int orig_broj = broj;

	while (broj > 0) {
		int znamenka = broj % 10;
		broj /= 10;
		if (orig_broj % znamenka == 0) {
			broj_znamenki++;
		}
	}
	return broj_znamenki;
}

int main(void) {
	int br_znam = funkcija(1806);
	printf("%d",br_znam);
	return 0;
}