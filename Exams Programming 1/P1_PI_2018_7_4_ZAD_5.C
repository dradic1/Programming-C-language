//ZADATAK 5
/*Napisati funkciju koja iz predanog joj stringa određuje skracenicu i ispisuje ju
na ekran. Skracenica ce biti niz znakova koji predstavljaju prvo slovo svake rijeci u stringu
osim onih rijeci koje imaju samo jedno slovo. Primjerice, za string "Fakultet elektrotehnike,
racunarstva i informacijskih tehnologija" funkcija treba ispisati Ferit. U svrhu testiranja u
funkciji main() dinamicki zauzeti memoriju za 48 podataka tipa char (u potpunosti rukovati
memorijom). Omoguciti korisniku unos stringa (osigurati da se ne premaši velicina prethodno
zauzetog polja). Pozvati funkciju s tim stringom kao argumentom.*/
#include <stdio.h>
#include <stdlib.h>

void skrati(char *ulaz) {
	int i;
	if (ulaz[1] != ' '){
		printf("%c", ulaz[0]); // isprintaj prvo slovo u stringu ako poslije njega nije razmak
	}
	for (i = 1; ulaz[i] != '\0'; i++) {
		// kreni od drugog znaka u stringu i trazi rijec za skracenicu na slijedeci nacin:
		// ukoliko je prethodni znak jednak razmaku, a trenutni znak nije razmak i znak
		// poslije njega nije razmak (da izbacimo rijeci od 1 slova), onda ispisi trenutni znak
		if (ulaz[i - 1] == ' ' && ulaz[i] != ' ' && ulaz[i + 1] != ' ')
			printf("%c", ulaz[i]);
	}
}

int main(void) {
	char *neki_string = (char*)calloc(48, sizeof(char));
	if (NULL == neki_string) {
		printf("ERROR");
		return 1;
	}
	fgets(neki_string, 48, stdin);
	skrati(neki_string);
	free(neki_string);
	return 0;
}