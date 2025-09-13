/*Napisati funkciju koja racuna i vraca zbroj znamenki broja n! za predani joj nenegativni
broj n. Ukoliko je predani joj broj negativan funkcija vraca vrijednost −1. Izdvojiti
korak izracuna faktorijela (n!) u posebnu funkciju. U svrhu testiranja u funkciji main() pozvati
napisanu funkciju s brojem 11 kao argumentom i na ekran ispisati povratnu vrijednost.*/

/*Faktorijel je funkcija koja broj mnozi sa svim njegovim prethodnicima
	NPR: 5! = 1 * 2 * 3 * 4 * 5 = 120*/

int fakt(int n) {
	int i, faktorijel = 1;
	for (i = 1; i <= n; i++) {
		faktorijel = faktorijel * i;
	}
	return faktorijel;
}

/*ZA NAPREDNE:
Oni koji se sjete da je faktorijel definiran kao n! = n * (n - 1)! mogu to rekurzivno napisati
	int fakt(int n) {
		if (n == 1)
			return 1;
		else 
			return n * fakt(n - 1);
	}
*/

int funkcija(int broj) {
	if (broj < 0)
		return -1; // Ako nam netko da negativni broj, funkcija ce odmah vratiti -1 i prekinuti sa daljnjim kodom ispod

	int fakt_broja = fakt(broj);
	int zbroj_znamenki = 0;
	int znamenka;
	while (fakt_broja > 0) {
		znamenka = fakt_broja % 10; 
		// zadnja znamenka broja se dobije tako da broj cijelobrojno podijelimo sa 10 i uzmemo ostatak pri dijeljenju
		zbroj_znamenki = zbroj_znamenki + znamenka;
		fakt_broja = fakt_broja / 10; 
		//dijeljenjem 2 inta dobivamo cijeli broj a ne decimalni, tako da ovo mice zadnju znamenku
	}
	
	return zbroj_znamenki;
}

int main(void) {
	int rezultat = funkcija(11);
	printf("%d", rezultat); // moglo se napisati i printf("%d", funkcija(11)) i onda nema potrebe za varijablom rezultat
	return 0;
}