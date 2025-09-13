////ZADATAK 1
/*Omoguciti korisniku unos dimenzija kvadratne matrice (2-D polja) m x m, gdje
je 5 < m < 25 i m mora biti neparan broj. Popuniti matricu parnim pseudo-slucajnim
brojevima iz [0, 255] C Z. Zamijeniti vrijednost elementa koji se nalazi na sjecištu dijagonala
novom vrijednošcu koja se racuna kao aritmeticka sredina svih susjednih elemenata tog broja
(susjedne elemente cini osam elemenata oko jednog centralnog).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int m;
	do {
		scanf("%d", &m);
	} while (!(5 < m && m < 25 && m % 2 == 1));
	//druga varijanta bi bila while ( m <= 5 || m >= 25 || m % 2 == 0);

	int polje[23][23]; //najveci neparni broj u intervalu <5, 25> je 23
	srand((unsigned)time(NULL)); 
	//potrebno iskljucivo jednom pozvati prije generiranja random brojeva

	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			polje[i][j] = 0 + (float)rand() / RAND_MAX * (127.5 - 0) * 2;
		}
	}

	int sjeciste_index = m / 2; //sjeciste kvadratne matrice je na broj_redaka / 2

	float suma = 0; //suma je float zbog problema cjelobrojnog dijeljenja

	for (i = sjeciste_index - 1; i < sjeciste_index + 1; i++) { //idemo od 1 reda prije sjecista do 1 reda poslije
		for (j = sjeciste_index - 1; j < sjeciste_index + 1; j++) {//idemo od 1 stupca prije sjecista do 1 stupca poslije
			if (i != sjeciste_index || j != sjeciste_index) { //ako nije srednji element
				suma += polje[i][j];
			}
		}
	}

	polje[sjeciste_index][sjeciste_index] = suma / 8; //direktno sredinu upisujemo u sjeciste

	return 0;
}