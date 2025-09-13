#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct matrica{
    int n;
    int m;
    int** mat;
}MATRICA;

MATRICA* alokacija(int n, int m);
void unos_elemenata(MATRICA* M);
void print(MATRICA* M);
MATRICA* Oslobadjanje(MATRICA* M);

void najveci(MATRICA* M, MATRICA* B);
//deklaracija funkcije najveci()

#endif