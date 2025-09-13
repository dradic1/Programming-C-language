/*Napisati funkciju koja provjerava sadrži li dani string više znakova koji predstavljaju
znamenke ili više znakova koji predstavljaju mala slova abecede. Ukoliko sadrži više znamenki
nego slova, funkcija vraca vrijednost 1, a u suprotnom vraca vrijednost 0. U svrhu testiranja u
funkciji main() dinamicki zauzeti memoriju za 50 podataka tipa char (u potpunosti rukovati
memorijom). Omoguciti korisniku unos stringa (osigurati da se ne premaši velicina prethodno
zauzetog polja). Pozvati funkciju s navedenim stringom te ispisati na ekran povratnu vrijednost.
[Znakovi 0, 1, 2, ... , 9 imaju ASCII vrijednosti 48, 49, 50, . . . , 57, dok znakovi a, b, ... , z
imaju ASCII vrijednosti 97, 98, . . . , 122]*/

#include <stdio.h>
#include <stdlib.h>
int funkcija(char *s) {
	int br_znam = 0, br_malih = 0;
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			//kompajler za nas znakove automatski pretvara u ascii vrijednosti
			//pa tako '0' pretvara u 48, '9' u 57 itd...
			br_znam++;
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			br_malih++;
		}
	}
	if (br_znam > br_malih)
		return 1;
	else
		return 0;
}
int main(void) {
	char *unos = (char*)calloc(50, sizeof(char));
	if (NULL == unos) {
		return 1;
	}
	fgets(unos, 50, stdin);
	int rez = funkcija(unos);
	printf("%d", rez);
	free(unos);
	return 0;
}