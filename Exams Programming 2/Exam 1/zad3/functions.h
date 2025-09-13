#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

typedef struct kompleks {
	int re;
	int im;
	float modul;
}KOMPLEKS;

char* porukaZaDatoteku(char*);
void provjeraDatoteke(FILE*, char*);
FILE* radSDatotekomManipuliranje(char*, char*); //otvaranje datoteke
FILE* radSDatotekomOslobadjanje(FILE*); //osloboditi datoteku

int ucitavanjeElemenata(FILE*); //ucitati ukupni broj kompleksnih brojeva
void provjeraZauzimanjaPolja(KOMPLEKS*);
KOMPLEKS* zauzimanjePoljaKompleksnih(int);  //zauzeti polje kompleksnih brojeva
void ucitavanjeKompleksnihBrojeva(FILE*, KOMPLEKS*, int); //ucitati kompleksne brojeve u polje
void modulKompleksnogBroja(KOMPLEKS*, int); //izracunati module kompleksnih brojeva
void ispisNajvecegModula(KOMPLEKS*, int);
void najveciModul(KOMPLEKS*, int); //pronaci kompleksni broj s najvecim modulom i ispisati njegove informacije
void zamjena(KOMPLEKS*, KOMPLEKS*);
void sortiranjeKompleksnihBrojeva(KOMPLEKS *, int); //sortirati polje kompleksnih brojeva
void ispisKompleksnihBrojeva(KOMPLEKS*, int); //ispisati sortirano polje kompleksnih brojeva
KOMPLEKS* oslobadjanjePoljaKompleksnihBrojeva(KOMPLEKS*); //osloboditi polje kompleksnih brojeva

#endif //FUNCTIONS_H