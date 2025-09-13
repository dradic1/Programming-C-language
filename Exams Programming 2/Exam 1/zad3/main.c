/*
Napisati C program koji radi s tekstualnom datotekom i strukturom tipa KOMPLEKS. 
U tekstualnoj datoteci kompleksni_brojevi.txt nalazi se određeni broj kompleksnih brojeva zapisani u obliku "re im i\n", 
te na kraju datoteke nalazi se cijeli broj koji označava koliko je kompleksnih brojeva zapisano u toj datoteci. 

Zadana je struktura tipa KOMPLEKS u kojoj su dva cjelobrojna člana i jedan realni. 
Dva cjelobrojna člana predstavljaju realnu i imaginarnu komponentu, dok realni član predstavlja modul tog kompleksnog broja. 

Prvo je potrebno pročitati ukupni broj kompleksnih brojeva zapisanih u datoteci, te s tim učitanim brojem u glavnom dijelu programa potrebno je dinamički zauzeti memoriju za polje struktura tipa KOMPLEKS. 
Tek nakon što se polje kreiralo potrebno je učitati sve kompleksne brojeve iz datoteke, tj. realnu i imaginarnu komponentu u kreirano polje, tj. u odgovarajući član pojedine strukture.

Nakon što se učitaju kompleksni brojevi u polje struktura tipa KOMPLEKS, potrebno je izračunati modul svakog kompleksnog broja te upisati odgovarajući član strukture.

Potrebno je pronaći modul kompleksnog broja koji ima najveću vrijednost te ispisati rezultat u obliku "index: %d complex number: %d + %d i module: %f\n". 
Pripaziti na predznak imaginarnog dijela, ako je imaginarni dio pozitivan ispisati imaginarni broj u obliku "%d + %d i", no ako je imaginarni dio negativan ispisati imaginarni broj u obliku "%d - %d i". 
Obratiti pozornost na aritmetički operator ispred imaginarnog dijela broja!

Za kraj sortirati polje struktura KOMPLEKS uzlazno od najmanjeg modula ka većem te ispisati pojedini kopleksni broj iz polja struktura KOMPLEKS prema sljedećem obliku: "index: %d complex number: %d + %d i\n". 
Pripaziti na predznak imaginarnog dijela, ako je imaginarni dio pozitivan ispisati imaginarni broj u obliku "%d + %d i", no ako je imaginarni dio negativan ispisati imaginarni broj u obliku "%d - %d i". 
Obratiti pozornost na aritmetički operator ispred imaginarnog dijela broja!
*/

#include "functions.h"

int main(void){
    
    printf("REZULTATI:\n");
    
    FILE* pF = //otvaranje datoteke
    
    int brojKompleksnih = //ucitati ukupni broj kompleksnih brojeva
    KOMPLEKS* poljeKompleksnih = //zauzeti polje kompleksnih brojeva
    //ucitati kompleksne brojeve u polje
    
	pF = //osloboditi datoteku
	
    //izracunati module kompleksnih brojeva
	
	//pronaci kompleksni broj s najvecim modulom i ispisati njegove informacije
	
	//sortirati polje kompleksnih brojeva
	//ispisati sortirano polje kompleksnih brojeva
	
	poljeKompleksnih = //osloboditi polje kompleksnih brojeva
    
    return 0;
}