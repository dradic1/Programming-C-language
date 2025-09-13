/* A GRUPA 3.
Napisati funkciju koja u predanom joj polju cijelih brojeva određuje i vraca element
koji ima najmanje djelitelja. Funkcija mora moci raditi s poljima razlicitih velicina i ne treba
uzimati u obzir nule (0), jer svaki cijeli broj je njen djelitelj. U svrhu testiranja u funkciji
main() deklarirati cjelobrojno polje od 250 elemenata i naknadno ga popuniti pseudo-slucajnim
brojevima iz [−111, 110] E Z. Pozvati funkciju s navedenim poljem kao argumentom i ispisati
na ekran povratnu vrijednost.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DG (-111)
#define GG 110


int funkcija (int A[], int n) {
	int i,j;
	int najmanji_djeljitelj = A[0];
	int najmanji_br_djeljitelja = 0;
	for (j = 1; j < A[0]; j++) {
		if (A[0] != 0 && A[0] % j == 0) {
			najmanji_br_djeljitelja++;
		}
	} 
	//ova petlja sluzi jer moramo odrediti neki minimum djeljitelja
	//ne mozemo samo reci da je jedan djeljitelj ili 100 njih nego tocno odredimo za prvi i to tretiramo kao pocetni minimum
	for (i = 0; i < n; i++) {
		int broj_djeljitelja;
		for (j = 1; j < A[i]; j++) {
			if (A[i] != 0 && A[i] % j == 0) {
				broj_djeljitelja++;
			}
		}
		if (broj_djeljitelja < najmanji_br_djeljitelja) {
			najmanji_br_djeljitelja = broj_djeljitelja;
			najmanji_djeljitelj = A[i];
		}
	}
	return najmanji_djeljitelj;
}

int main(void) {
	int A[250];
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 250; i++) {
		A[i] = DG + (float)rand() / RAND_MAX * (GG - DG); //DG + (float)rand()/RAND_MAX * (GG-DG);
	}
	printf("%d\n",funkcija(A,250));
	return 0;
}