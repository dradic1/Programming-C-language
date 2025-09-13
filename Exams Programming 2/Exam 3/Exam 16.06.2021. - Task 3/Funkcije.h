#ifndef HEADER_H
#define HEADER_H

typedef struct hladnjaci {
	int vrsta;
	int vrata;
	struct proizvodjac *Proizvodjac;
	struct hladnjaci* noviCvor;
}HLADNJAK;

typedef struct proizvodjac {
	char *ime;
	char *drzava;
	int ocjena;
}PROIZVODJACI;

int brojhladnjaka();
int BrojZaPretragu();
void UpisHladnjaka(HLADNJAK* );
void IspisHladnjaka(HLADNJAK* );
HLADNJAK* kreiranjePopisa();
HLADNJAK* ubaciNoviCvor(HLADNJAK*);
HLADNJAK* PretragaPopisa(HLADNJAK*, int );
HLADNJAK* OslobadjanjeHladnjaka(HLADNJAK* );
void IspisZeljenogHladnjaka(HLADNJAK*);
#endif