/*Napisati funkciju koja određuje i vraca koliko se znamenki predana joj cijela dva broja
podudaraju (po vrijednosti i poziciji). Primjerice, za brojeve 78635 i 675 funkcija treba vratiti
vrijednost 2. U svrhu testiranja u funkciji main() pozvati napisanu funkciju s brojevima 2313
i 310317 kao argumentima i na ekran ispisati povratnu vrijednost*/

#include <stdio.h>

int funkcija(int a, int b) {
	int poklapanja = 0;
	int tezinski_faktor = 1;
	int znamenka_a;
	int znamenka_b;

	while (a != 0 && b != 0) {
		znamenka_a = a % 10;
		znamenka_b = b % 10;

		if (znamenka_a * tezinski_faktor == znamenka_b * tezinski_faktor) {
			poklapanja++;
		}

		a /= 10;
		b /= 10;
		tezinski_faktor *= 10;
	}
	return poklapanja;
}

int main(void) {
	int p = funkcija(2313, 310317);
	printf("%d", p);
	return 0;
}