#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

/* Funkcija main() je dana te u njoj korisnik s tipkovnice unosi broj knjiga koje zeli zapisati u datoteku.
Nakon toga se kreira binarna datoteka naziva "knjige.bin" te se na pocetku nje upisuje broj knjiga koji je ranije unesen.
Poziva se funkcija zapisivanjeKnjige() koja zapisuje podatke o svakoj knjizi u datoteku "knjige.bin. Potom se, nakon 
kljucne rijeci REZULTATI: ispisuju sve knjige na ekran i oslobadja se zauzeta memorija.

Funkcija zapisivanjeKnjige() je dana te zapisuje jednu po jednu knjigu u datoteku naziva "knjige.bin".

Funkcija citajKnjige() prima 2 parametra: strig koji predstavlja ime datoteke u kojoj su zapisane knjige i cijeli broj 
koji predstavlja broj knjiga koji je zapisan u datoteci. Funkcija treba otvoriti datoteku, pomaknuti se na dio gdje su zapisani
podaci o knjigama i procitati ih u dinamicki alocirano polje tipa podatka KNJIGA*. Vratiti pokazivac tog polja u funkciju main();

Funkcija oslobodiMe() prima jedan parametar tipa KNJIGA* te oslobadja memoriju tog polja. Obvezno je napisati ovu funkciju bez obzira 
na testcaseove koji ce i bez nje uspjesno proci.

*/

int main(void) {
	int n, i;
	KNJIGA *K;
	printf("Koliko knjiga zelite upisati?");
	scanf("%d",&n);
	getchar();
	FILE* pFile = fopen("knjige.bin", "wb+");
	if (pFile == NULL) {
		perror("No file");
		exit(EXIT_FAILURE);
	}
	fwrite (&n, sizeof(int),1,pFile);
	fclose(pFile);
	for (i=0; i<n; i++){
		zapisivanjeKnjige("knjige.bin");
	}
	K=citajKnjige ("knjige.bin", n);
	printf("REZULTATI:\n");
	for  (i = 0; i < n; i++){
		printf("Naslov: %s\nAutor: %s\nISBN: %d\n", K[i].ime , K[i].autor, K[i].isbn);
	}
	K=oslobodiMe(K);
	return 0;
}
