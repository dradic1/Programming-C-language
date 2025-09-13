/*Napisati C program koji koristi jednostruko povezani popis za strukturu HLADNJAK. 
Struktura ima varijable tip hladnjaka [0 - sa zamrzivacem, 1- bez zamrzivača, 2 - vinski], broj vrata [1,2,4]
i pokazivac na strukturu PROIZVODJAC, koja ima clanove: pokazivace na ime i drzavu prozivodnje,
i cjelobrojnu varijablu ocjena koja odgovara ocjeni brzine isporuke [od 1 do 10].

Napisati odgovarajuce funkcije za kreiranje povezanog popisa i ubacivanje novog clana: 
KreiranjePopisa(), UnesiNoviCvor().

Napisati funkciju UnosHladnjaka() s kojom se unose svi podaci u clanove strukture i pozvati 
funkciju na odgovarajućem mjestu u programu.


Napisati funkciju IspisHladnjaka() koja ispisuje povezani popis u obliku:

Tip hladnjaka:
Ime proizvodjaca:
Ocjena brzine dostave:


Napisati funkciju PretragaPopisa() za pretrazivanje povezanog popisa po zeljenoj ocjeni brzine
isporuke.

Napisati funkciju IspisZeljenogHladnjaka() koja ispisuje pronađeni hladnjak prethodnom funkcijom.
Ako ih ima više takvih, ispisati prvi u popisu. Ispis neka bude u obliku:

Tip hladnjaka:
Broj vrata:
Ime proizvodjaca:
Drzava proizvodnje:

Napisati funkciju OslobadjanjeHladnjaka() koja oslobadja dinamicki zauzetu memoriju
za povezani popis.

U potpunosti rukovati memorijom za sve varijable za koje je to nužno.
*/
#include <stdio.h>
#include "Funkcije.h"

int main() {

	int n,i, x;

	HLADNJAK* headNode = NULL;
	HLADNJAK* ZeljeniHladnjak = NULL;
	
	
	n = brojhladnjaka();
	headNode = kreiranjePopisa();
    
	 for (i = 0; i < n - 1; i++)
 	 {
 	 	headNode = ubaciNoviCvor(headNode);
 	 }

	 
 	 	IspisHladnjaka(headNode);
 	 	x = BrojZaPretragu();
 	 	ZeljeniHladnjak = PretragaPopisa(headNode, x); 
 	 	//IspisZeljenogHladnjaka(ZeljeniHladnjak);
 	 	printf("REZULTATI:\n");
 	 	if (ZeljeniHladnjak == NULL) {
		printf("Hladnjak s tom ocjenom nije pronadjen!");   
	        }
 	 	else IspisZeljenogHladnjaka(ZeljeniHladnjak);
 	 
 	 
        headNode = OslobadjanjeHladnjaka(headNode);
		if (headNode == NULL)
			printf("Oslobodjen cvor!");
    
	
	
	




	return 0;
}
