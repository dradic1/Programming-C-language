#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct matrica{
    int n;
    int m;
    int** mat;
}MATRICA;

MATRICA* alokacija(int n);
void unos_elemenata(MATRICA* M);
void print(MATRICA* M);
MATRICA* Oslobadjanje(MATRICA* M);
int parniIznadSporedne(MATRICA* M);
//deklaracija funkcije parniIznadSporedne()

#endif