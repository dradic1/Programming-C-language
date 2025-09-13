#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

char* porukaZaDatoteku(char* nacinRada) {

	char* poruke[] = { "Citanje", "Pisanje", "Dodavanje", "Citanje i pisanje", "Pisanje i citanje", "Dodavanje i citanje", "Ne definirani nacin rada" };

	if (!strcmp("r", nacinRada)) {
		return poruke[0];
	}
	else if (!strcmp("w", nacinRada)) {
		return poruke[1];
	}
	else if (!strcmp("a", nacinRada)) {
		return poruke[2];
	}
	else if (!strcmp("r+", nacinRada)) {
		return poruke[3];
	}
	else if (!strcmp("w+", nacinRada)) {
		return poruke[4];
	}
	else if (!strcmp("a+", nacinRada)) {
		return poruke[5];
	}else{
		return poruke[6];
	}
}

void provjeraDatoteke(FILE* pF, char* nacinRada) {

	if (pF == NULL) {
		perror(porukaZaDatoteku(nacinRada));
		exit(EXIT_SUCCESS);
    }else{
	    printf("Provjera datoteke odradjena\n");
	}
}

FILE* radSDatotekomManipuliranje(char* imeDatoteke, char* nacinRada) {

	FILE* pF = fopen(imeDatoteke, nacinRada);

	//pozvati funkciju

	return pF;
}

FILE* radSDatotekomOslobadjanje(FILE* pF) {
    
    if(/*pozvati funkciju*/ == 0){
        printf("Oslobadjanje datoteke odradjeno\n");
    }

	return NULL;
}

int ucitavanjeElemenata(FILE* pF) {

	//dovrsiti implementaciju
}

void provjeraZauzimanjaPolja(KOMPLEKS* polje) {
    
    if (polje == NULL) {
		perror("Zauzimanje polja");
		exit(EXIT_FAILURE);
	}else{
	    printf("Provjera zauzimanja odradjena\n");
	}
}

KOMPLEKS* zauzimanjePoljaKompleksnih(int brojKompleksnih) {

	KOMPLEKS* polje = (KOMPLEKS*)calloc(brojKompleksnih, sizeof(KOMPLEKS));
	
	//pozvati funkciju
	
	return polje;
}

void ucitavanjeKompleksnihBrojeva(FILE* pF, KOMPLEKS* polje, int brojKompleksnih) {

	rewind(pF);

	//dovrsiti implementaciju
}

void modulKompleksnogBroja(KOMPLEKS* polje, int brojKompleksnih) {

	//dovrsiti implementaciju
}

void ispisNajvecegModula(KOMPLEKS* najveci, int indeks){
    
    
    if (najveci->im < 0) {

		//napisati ispis
	}
	else {
		printf("index: %d complex number: %d + %d i module: %f\n", indeks, najveci->re, najveci->im, najveci->modul);
	}
}

void najveciModul(KOMPLEKS* polje, int brojKompleksnih) {

	//dovrsiti implementaciju

    ispisNajvecegModula(najveci, j);
}

void zamjena(KOMPLEKS* veci, KOMPLEKS* manji) {
	KOMPLEKS temp;
	temp = *veci;
	*veci = *manji;
	*manji = temp;
}

void sortiranjeKompleksnihBrojeva(KOMPLEKS* polje, int brojKompleksnih) {
    	
    //dovrsiti implementaciju
    zamjena(polje + i, polje + min);
    	
}

void ispisKompleksnihBrojeva(KOMPLEKS* polje, int brojKompleksnih) {

	int i;

	for (i = 0; i < brojKompleksnih; i++)
	{
		if ((polje + i)->im < 0) {
			printf("index: %d complex number: %d - %d i\n", i, (polje + i)->re, (polje + i)->im * -1);
		}
		else {
			//napisati ispis
		}
	}
}

KOMPLEKS* oslobadjanjePoljaKompleksnihBrojeva(KOMPLEKS* polje) {

	free(polje);
	
	polje = NULL;
	
	if(polje == NULL){
	    printf("Oslobadjanje polja odradjeno\n");
	}

	return NULL;
}