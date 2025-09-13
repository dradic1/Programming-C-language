/*Napisati funkciju koja racuna i vraca
	f(x) = n * (x_(n))^(-3) + product_(i=1)^(n-1)(i * x_i^-2 + cos(pi/(x_i + 1)))
U svrhu testiranja u funkciji main() deklarirati polje realnih brojeva od 20 elemenata i naknadno
ga popuniti pseudo - slucajnim brojevima iz[0.5, 5] c R.Pozvati funkciju s navedenim
poljem kao argumentom i ispisati na ekran povratnu vrijednost.Funkcija za izracun kosinusa
je opisana u zaglavnoj datoteci math.h, a prototip joj je double cos(double x).*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//kada radimo sa kvadratima u nazivniku i kosinusima najbolje je 
//koristiti double kako ne bi se gubila preciznost
double f(double *x, int n) {
	//matematicarima indeksi krecu od 1 a nama od 0, pa je zato zadnji element na mjestu n-1
	double rezultat = n / (x[n - 1] * x[n - 1] * x[n - 1]);
	double produkt = 1; //1 je neutralni element za mnozenje
	int i;
	for (i = 1; i < n; i++) {
		//krecemo sa i = 1 radi brojnika u clanu i / x[i] * x[i] u formuli
		//zbog toga cemo morati preinaciti indekse u ostatku formule, kao i uvjet
		produkt *= cos(3.1415926535 / (x[i - 1] + 1)) + i / (x[i - 1] * x[i - 1]);
		//u prvom koraku kada je i=1 mi cemo pristupati elementu i-1 = [0] sto 
		//je prvi element
		//u zadnjem koraku kada je i = n-1 mi cemo pristupati prethodnom
		//elementu [n-2] koji je zapravo predzadnji element 
	}
	rezultat += produkt;
	return rezultat;
}
int main(void) {
	double polje[20];

	srand((unsigned)time(NULL));
	int i;
	for (i = 0; i < 20; i++) {
		polje[i] = 0.5 + (float)rand() / RAND_MAX * (5 - 0.5);
	}
	double r = f(polje, 20);
	printf("%lf", r);
	return 0;
}