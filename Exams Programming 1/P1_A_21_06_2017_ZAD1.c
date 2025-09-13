/*A GRUPA 1.
Omoguciti korisniku unos dimenzija matrice (2-D polja) 5*n, gdje je 18 <= n < 31.
Popuniti matricu na pseudo-slucajnim brojevima iz [−17, 17] E R. Odrediti i na ekran ispisati
koliko stupaca ima aritmeticku sredinu vecu u odnosu na aritmeticku sredinu svih vrijednosti
elemenata matrice.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DG (-17)
#define GG 17

int main(void) {
	srand((unsigned)time(NULL));
	int n;
	do {
		scanf("%d",&n);
	} while (n < 18 || n >= 31);
	/*ako nije jasno to sa desifriranjem uvjeta 18 <= n < 31, moze se pisati
	while !(uvjet), znaci ponavljaj dok broj NIJE(veci ili jednak od 18 i manji od 30) -> while !(n >= 18 && n < 30) */
	int A[5][30]; //ne pise da se mora dinamicki pa idemo zauzeti najvece moguce
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = DG + (float)rand() / RAND_MAX * (GG - DG); //DG + (float)rand()/RAND_MAX * (GG-DG);
		}
	}
	float total_sredina = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < n; j++) {
			total_sredina += A[i][j];
		}
	}
	total_sredina /= (5 * n); //prvo pozbrajamo sve elemente u matrici, a onda ih podijelimo sa brojem clanova (5 * n)
	int broj_vecih_od_sredine = 0;
	for (j = 0; j < n; j++) {
		float stupac_sredina = 0;
		for (i = 0; i < 5; i++) {
			stupac_sredina += A[i][j];
		}
		if (stupac_sredina / 5 > total_sredina) {
			broj_vecih_od_sredine++;
		}
	}
	return 0;
}