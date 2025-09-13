/* Napišite funkciju parniIznadSporedne() kojoj cete predati pokazivac na matricu M. 
Funkcija treba vratiti koliko elemenata iznad sporedne dijagonale ima parnu vrijednost
 te se nalazi na indeksima cija je suma parna (nula se ne spatra parnom vrijednoscu):

Primjer:
M= 1 6 0 5
   2 8 5 4
   8 4 6 3
   1 2 4 5 
REZULTATI:
2

Funkciju alokacija() je napisana, te joj je zadatak dinamicki alocirati memoriju za matricu. Vratiti adresu kreirane matrice.

Funkciju unos_elemenata() je napisana, te joj je zadatak unijeti vrijednosti elemenata matrice s tipkovnice. 

Funkciju print() je napisana te joj je cilj ispisati  matricu na ekran u matricnom obliku. Funkcija ne vraca nikakvu vrijednost.

Funkciju Oslobadjanje() je napisana, te joj je zadatak osloboditi alociranu memoriju matrice.

Funkciju main() je napisana. Ucitava se dimenzija matrice M s tipkovnice. Pomocu definiranih funkcija, alocira se memorija za 
matricu M i unose se elementi matrice M s tipkovnice, te se ispisuje unesena matrica.
Nakon "REZULTATI:\n" ispisuje se rezultat funkcije parniIznadSporedne().*/

#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main()
{
    int n,m;
    MATRICA *M, *B;
    scanf("%d",&n);
    
    M=alokacija(n);
    unos_elemenata(M);
    printf("Unesena matrica je:\n");
    print(M);
    printf("REZULTATI:\n");
    printf("%d", parniIznadSporedne(M));
    M=Oslobadjanje(M);
    
    return 0;
}