#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct knjiga {
	char ime[50];
	char autor[50];
	long int isbn;
}KNJIGA;

void zapisivanjeKnjige(char* file);
//deklaracije funkcija citajKnjige() i oslobodiMe()

#endif