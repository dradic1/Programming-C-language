/*Omoguciti korisniku unos dimenzija matrice (2-D polja) m x n, gdje je 17 < m <= 30
i 7 <= n <= 12. Popuniti matricu parnim pseudo-slucajnim brojevima iz [5, 50] c R. Redak
i stupac u kojem se nalazi najveci element matrice izmijeniti na sljedeci nacin: sve elemente
retka postaviti na vrijednost 1, a sve elemente stupaca na −1. Najveci element ne mijenjati.
Na koncu, ispisati matricu na ekran.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int m, n;
	do {
		scanf("%d", &m);
		scanf("%d", &n);
	} while (!(17 < m && m <= 30 && 7 <= n && n <= 12));
	//moze ici i while (m <= 17 || m > 30 || n < 7 || n > 12);

	float a[30][12]; // pravimo najvecu mogucu matricu za ogranicene m i n

	srand((unsigned)time(NULL));

	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = 5 + (float)rand() / RAND_MAX * (50 - 5);
		}
	}

	int redak_najveceg = 0, stupac_najveceg = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] > a[redak_najveceg][stupac_najveceg]) {
				//ako je trenutni broj veci od dosadasnjeg najveceg
				//onda trenutni postaje novi max
				redak_najveceg = i;
				stupac_najveceg = j;
			}
		}
	}
	for (j = 0; j < n; j++) {
		//mijenjamo sve elemente u retku gdje je najveci na vrijednost 1
		if (j != stupac_najveceg) {
			//receno je da ne diramo najveci element
			a[redak_najveceg][j] = 1;
		}
	}

	for (i = 0; i < m; i++) {
		//mijenjamo sve elemente u stupcu gdje je najveci na vrijednost -1
		if (i != redak_najveceg) {
			//receno je da ne diramo najveci element
			a[i][stupac_najveceg] = -1;
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.2f\t", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}