/*Omoguciti korisniku unos dimenzija kvadratne matrice(2-D polja) m x m, gdje
je 10 <= m < 19. Popuniti matricu pseudo-slucajnim brojevima iz [−5, 5] c R.
Promijeniti redom svaki element glavne dijagonale na vrijednost 1 ukoliko je
veci od aritmeticke sredine retka u kojem se nalazi, a u suprotnom ga promijeniti
na vrijednost 0. Ispisati matricu na ekran.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int m;
	do {
		scanf("%d", &m);
	} while (m < 10 || m >= 19);
	//druga varijanta je while (!(10 <= m && m < 19));

	float a[18][18]; //18 je najveci cijeli broj u intervalu [10,19>

	srand((unsigned)time(NULL));
	//obavezno pozvati (SAMO JEDNOM) prije generiranja random brojeva

	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			a[i][j] = -5 + (float)rand() / RAND_MAX * (5 - (-5));
			/*FORMULA ZA DECIMALNE RANDOM BROJEVE:
				DonjaGranica + (float) rand()/RAND_MAX * (GornjaGranica - DonjaGranica)
			*/
		}
	}
	float suma;
	float aritmeticka_sredina;
	for (i = 0; i < m; i++) {
		suma = 0; //za svaki red racunamo sumu svih elemenata unutar donje for petlje
		for (j = 0; j < m; j++) {
			suma += a[i][j];
		}

		aritmeticka_sredina = suma / m;
		//radimo provjeru elementa na glavnoj dijagonali i postavljamo ga na odgovarajucu vrijednost
		if (a[i][i] > aritmeticka_sredina) {
			//element na glavnoj dijagonali ima lokaciju [i][i]
			a[i][i] = 1;
		} else {
			a[i][i] = 0;
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("%.2f\t", a[i][j]);
			//isprintaj broj zaokruzen na 2 decimale i dodaj tabulator za poravnanje
		}
		printf("\n"); //na kraju reda u matrici ispisi znak za prijelaz u novi red
	}
	return 0;
}