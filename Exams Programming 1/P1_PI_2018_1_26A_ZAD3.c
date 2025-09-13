/*Napisati funkciju koja vraca vrijednost 1 ukoliko najveci broj predanog joj cjelobrojnog
polja ima ujedno i najveci produkt znamenki, a u suprotnom funkcija vraca vrijednost 0.
Funkcija mora moci raditi s poljima razlicitih velicina. U svrhu testiranja u funkciji main() dinamcki
zauzeti memoriju za 204 podataka tipa long int (u potpunosti rukovati memorijom).
Dobiveno polje popuniti pseudo-slucajenim brojevima iz [-750, 750] c Z. Pozvati funkciju s
navedenim poljem kao argumentom i ispisati na ekran povratnu vrijednost.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int umnozak_znamenki(int broj) {
	int umnozak = 1, znamenka;
	// umnozak se mora postaviti na 1 jer je 1 neutralan za mnozenje
	while (broj != 0) {
		znamenka = broj % 10;
		umnozak = umnozak * znamenka;
		broj = broj / 10;
	} //slicna petlja je u 2. zadatku

	return umnozak;
}

int funkcija(long int *polje, int n) {
	//polje je tipa long int jer se kasnije treba takvo polje predati funkciji
	//predajemo velicinu polja n, jer nemamo nijedan drugi nacin saznati velicinu polja
	//a ne smijemo pretpostaviti velicinu

	long int max_broj = polje[0];
	//bilo koji max ili min se ne smiju staviti na 0,
	//jer je moguce da su veci/manji od svega u polju, zato ide bilo koji element polja
	long int broj_s_max_umnoskom = polje[0];
	int i;
	for (i = 0; i < n; i++) {
		if (polje[i] > max_broj) {
			max_broj = polje[i];
		}//pamtimo najveci broj na kojeg smo naisli
		//ako je trenutni veci od tog, trenutni broj je novi najveci

		if (umnozak_znamenki(polje[i]) > umnozak_znamenki(broj_s_max_umnoskom)) {
			broj_s_max_umnoskom = polje[i];
		}//ista stvar kao i gore, samo provjeramo umnoske, a pamtimo originalne brojeve
		//jer iz njih opet mozemo dobiti umnoske
	}
	if (max_broj == broj_s_max_umnoskom) {
		return 1;
	} else {
		return 0;
	}
}

int main(void) {
	long int* polje = (long int*)calloc(204, sizeof(long int));
	/*SABLONA ZA DINAMICKO ZAUZIMANJE MEMORIJE (1-D POLJE):
		tip_podatka* ime_polja = (tip_podatka*) calloc(broj_elemenata, sizeof(tip_podatka));
		ILI
		tip_podatka* ime_polja = (tip_podatka*) malloc(broj_elemenata * sizeof(tip_podatka));*/

	if (NULL == polje) {
		//calloc nije uspio zauzeti memoriju pa prekidamo program
		//ako pozovemo return u mainu, cijeli program zavrsava
		return 1; // 1 znaci da je prekid zbog greske, 0 je znak da je sve proslo OK
	}

	srand((unsigned)time(NULL));

	int i;
	for (i = 0; i < 204; i++) {
		polje[i] = -750 + (rand() % (750 + 1 - (-750)));
		/*FORMULA ZA CIJELE SLUCAJNE BROJEVE:
			DG + (rand() % (GG + 1 - DG))
		DAJE SAMO CIJELE BROJEVE, NIKAD DECIMALNE*/
	}

	int rez = funkcija(polje, 204);
	printf("%d", rez); //mogli smo i printf("%d", funkcija(polje, 204)) pa nema potrebe za int rez
	free(polje); //sve sto zauzmemo calloc-om i malloc-om moramo i free-at
	return 0;
}