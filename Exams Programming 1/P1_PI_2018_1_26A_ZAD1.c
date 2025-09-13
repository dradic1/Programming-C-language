/*Omoguciti korisniku unos dimenzija matrice (2-D polja) m x n, gdje su
10 <= m < 19 i 11 <= n <= 20. Popuniti matricu pseudo-slucajnim brojevima iz
[b10, 20] c R. Odrediti najvecu vrijednost u svakom stupcu i izracunati njihov
zbroj te ga potom ispisati na ekran.*/

#define _CRT_SECURE_NO_WARNINGS //potrebno samo radi Visual Studija (ne treba pisat u ispitu)

#include <stdio.h> // za scanf i printf
#include <stdlib.h> // za random brojeve
#include <time.h> // za random brojeve

int main(void) {
	int m, n;
	do {
		scanf("%d%d", &m, &n); //Moglo se preko 2 zasebna scanf-a 
	} while (!(10 <= m && m < 19 && 11 <= n && n <= 20));
	//druga opcija za while je while(m > 10 || m >= 19 || n < 11 || n > 20);

	float a[18][20]; //najvece dimenzije matrice, a da m i n ostanu u zadanim uvjetima


	srand((unsigned)time(NULL)); //poziva se samo jednom, obicno u mainu, prije pravljenja random brojeva

	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = -10 + (float)rand() / RAND_MAX * (20 - (-10));
			//formula za random decimalne brojeve je DG + (float)rand()/RAND_MAX * (GG - DG)
		}
	}

	float max_stupca;
	float suma = 0;
	for (j = 0; j < n; j++) {
		max_stupca = a[0][j];
		for (i = 0; i < m; i++) {
			if (a[i][j] > max_stupca) {
				max_stupca = a[i][j];
			}
		}
		suma = suma + max_stupca;
	}
	/*B nacin rjesavanja ovog dijela:
	for (i = 0; i < n; i++) {
		max_stupca = a[0][i];
		for (j = 0; j < m; j++) {
			if (a[j][i] > max_stupca) {
				max_stupca = a[j][i];
			}
		}
		suma = suma + max_stupca;
	}
	Vanjska for petlja i dalje koristi varijablu i, ali ona ide do n (broja
	stupaca), a ne do m, dok unutarnja i dalje koristi j, ali ide do m, a ne do n
	i redoslijed i i j u uglatim zagradama je zamijenjen.*/

	printf("%f", suma);

	return 0;
}