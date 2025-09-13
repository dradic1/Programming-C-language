/*Napisati funkciju koja provjerava podudara li se pocetak stringa sa zadanim podstringom.
Ukoliko se podudara, funkcija vraca vrijednost 1, a u suprotnom vraca vrijednost 0.
U svrhu testiranja u funkciji main() dinamicki zauzeti memoriju za 90 podataka tipa char (u
potpunosti rukovati memorijom). Omoguciti korisniku unos stringa (osigurati da se ne premaši
velicina prethodno zauzetog polja). Pozvati funkciju s navedenim stringom te s podstringom
"abc" kao argumentima i ispisati na ekran povratnu vrijednost.*/

#include <stdio.h>
#include <stdlib.h>
int funkcija(char *veliki, char *mali) {
	int poklapanje = 1;
	//u pocetku smo optimisticni pa cemo reci da se poklapaju dok ne ispadne drukcije
	int i;
	for (i = 0; veliki[i] != '\0' && mali[i] != '\0'; i++) {
		//ovaj uvjet prati da se ne dogodi da pokusamo preci kraj bilo kojeg stringa
		if (veliki[i] != mali[i]) {
			poklapanje = 0;
			break; //nasli smo prvu razliku i odmah mozemo prestati
		}
	}
	return poklapanje;
}

int main(void) {
	char* dinamicki = (char*)calloc(90, sizeof(char));
	if (NULL == dinamicki) {
		return 1;
	}

	fgets(dinamicki, 90, stdin);

	int rez = funkcija(dinamicki, "abc");
	printf("%d", rez);
	free(dinamicki);
	return 0;
}