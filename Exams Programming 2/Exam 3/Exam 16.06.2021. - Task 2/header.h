#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct knjiga {
	char ime[50];
	char autor[50];
	long int isbn;
}KNJIGA;

KNJIGA* oslobodiMe(KNJIGA* K);
KNJIGA* citajKnjige (char* file, int n);

void zapisivanjeKnjige(char* file, int n);
//deklaracije funkcija zapisivanjeKnjige() 


#endif