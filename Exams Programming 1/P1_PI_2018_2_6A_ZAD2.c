/*Napisati funkciju koja racuna i vraca zbroj znamenki svih dijelitelja prednog joj cijelog
broja. Izdvojiti korak izracuna zbroja znamenki pojedinog dijelitelja u posebnu funkciju. U
svrhu testiranja u funkciji main() pozvati napisanu funkciju s brojem 24578 kao argumentom
i na ekran ispisati povratnu vrijednost.*/

int suma_znamenki(int broj) {
	int suma = 0;
	int znamenka;
	while (broj != 0) {
		znamenka = broj % 10;
		suma += znamenka;
		broj = broj / 10;
	}
	return suma;
}
int funkcija(int n) {
	int i, suma = 0;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			suma += suma_znamenki(i);
		}
	}
	return suma;
}

int main(void) {
	int rez = funkcija(24578);
	printf("%d", rez);
	return 0;
}