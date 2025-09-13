#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct knjiga {
	char ime[50];
	char autor[50];
	long int isbn;
}KNJIGA;

void zapisivanjeKnjige(char* file);
KNJIGA* citajKnjige(char *file, int n);
//deklaracije funkcija citajKnjige() i oslobodiMe()
KNJIGA* oslobodiMe(KNJIGA *K);

#endif