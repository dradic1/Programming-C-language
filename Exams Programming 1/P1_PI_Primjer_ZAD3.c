/*Napisati funkciju koja predano joj polje cijelih brojeva popunjava meusobno razlicitim
pseudo-slucajnim brojeva iz [−n, n] c Z, gdje je n velicina polja. U svrhu testiranja u
funkciji main() dinamcki zauzeti memoriju za 50 podataka tipa long int (u potpunosti rukovati
memorijom). Popuniti navedeno polje uprabom napisane funkcije te ga naknadno ispisati
na ekran.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funkcija(long int *polje, int n) {
	int dg = -n;
	int gg = n;
	int i, j, sluc_broj, sluc_br_razlicit;
	for (i = 0; i < n; i++) {
		do {
			sluc_broj = dg + rand() % (gg + 1 - dg);
			sluc_br_razlicit = 1;
			for (j = 0; j < i; j++) {
				if (sluc_broj == polje[j]) {
					sluc_br_razlicit = 0;
					break;
				}
			}
		} while (sluc_br_razlicit == 0);

		//ova do-while petlja generira nasumicni broj u intervalu [dg, gg] i sprema 
		//ga u sluc_broj zatim for petljom provjerava je li se taj broj vec negdje 
		//prije pojavio u polju, i ako je stavlja varijablu sluc_br_razlicit na 0, 
		//sto ce uzrokovati da se do-while petlja ponovi i napravi novi broj
		//u pocetku smatramo da ce taj nas broj bit razlicit od svih ostalih, 
		//dok se ne pokaze sa for petljom drukcije
		//kada do-while petlja zavrsi, sigurno imamo neki razlicit broj i njega 
		//spremamo u trenutni element polja
		polje[i] = sluc_broj;
	}
}

int main(void) {
	long int *a = (long int*)malloc(50 * sizeof(long int));
	if (NULL == a) {
		return 1;
	}

	srand((unsigned)time(NULL));
	funkcija(a, 50);

	int i;
	for (i = 0; i < 50; i++) {
		printf("%2d", a[i]);
	}

	free(a);
	return 0;
}