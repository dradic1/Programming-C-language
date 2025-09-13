#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

/* Funkcija main() je dana te u njoj korisnik s tipkovnice unosi broj knjiga koje zeli zapisati u datoteku.
Nakon toga se poziva funkcija zapisivanjeKnjige() koja  kreira binarnu datoteka naziva koji je poslan kao parametar funkcije
te zapisuje podatke o svakoj knjizi tu datoteku, a na kraj zapisuje broj knjiga. Potom se, nakon poziva funkcije citajKnjige()
i kljucne rijeci "REZULTATI:" ispisuju sve knjige na ekran i oslobadja se zauzeta memorija.

Funkciju zapisivanjeKnjige() je potrebno napisati. Prima 2 parametra: strig koji predstavlja ime binarne datoteke
koja se treba kreirati i cijeli broj koji predstavlja broj knjiga koje ce se zapisati u datoteku. Funckija od korisnika trazi
podatke o svim knjigama te ih zapisuje u binarnu datoteku, na kraj datoteke zapisuje broj koliko je zapisanih knjiga u datoteci.

Funkcija citajKnjige() je dana. Funkcija otvora datoteku, cita podatke o knjigama i sprema ih u dinamicki alocirano polje 
tipa podatka KNJIGA*. Vraca pokazivac tog polja u funkciju main();

Funkcija oslobodiMe() je dana i prima jedan parametar tipa KNJIGA* te oslobadja memoriju tog polja. 

*/
int main(void) {
	int n, i;
	KNJIGA *K;
	printf("Koliko knjiga zelite upisati?");
	scanf("%d",&n);
	getchar();

	
	zapisivanjeKnjige("knjige.bin", n);
	
	K=citajKnjige ("knjige.bin", n);
	printf("REZULTATI:\n");
	for  (i = 0; i < n; i++){
		printf("Naslov: %s\nAutor: %s\nISBN: %d\n", K[i].ime , K[i].autor, K[i].isbn);
	}
	K=oslobodiMe(K);
	return 0;
}
