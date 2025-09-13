/*B GRUPA 4.
Napisati funkciju koja određuje i vraca koliko se puta u predanom joj stringu pojavljuje
prvo po redu malo slovo. Funkcija vraca vrijednost 0 ukoliko predani joj string ne sadrži
niti jedno malo slovo. Primjerice, za string "01kb-bA-Ka123k" funkcija bi vratila vrijednost 2.
U svrhu testiranja u funkciji main() dinamicki zauzeti memoriju za 151 podataka tipa char (u
potpunosti rukovati memorijom). Omoguciti korisniku unos stringa (osigurati da se ne premaši
velicina prethodno zauzetog polja). Pozvati funkciju s navedenim stringom i na ekran ispisati
povratnu vrijednost. [Znakovi a, b, ... , z imaju ASCII vrijednosti 97, 98, . . . , 122, redom]*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int funkcija(char s[]) {
	int i;
	char prvo_malo_slovo;
	int broj_malih = 0;
	for (i = 0; s[i] != 0; i++) {
		if (s[0] >= 'a' && s[0] <= 'z' ){
			prvo_malo_slovo = s[i]; //ako je prvo slovo stringa malo odma broj_malih ide za 1 gore
		}
	}
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == prvo_malo_slovo ) {
			broj_malih++;
		}
	}
	return broj_malih;
}

int main(void) {
	char *s = (char *)calloc(151,sizeof(char)); //moglo se i sa malloc al meni je calloc drazi
	fgets(s, 151, stdin);
	printf("%d", funkcija(s));
	free(s);
	return 0;
}