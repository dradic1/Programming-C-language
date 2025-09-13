//ZADATAK 2
/*Napisati funkciju koja od predanog joj cijelog broja određuje i vraća novi broj kojemu
su izbačene parne znamenke. Primjerice, za broj 78635 funkcija treba vratiti broj 735. U
svrhu testiranja u funkciji main() pozvati napisanu funkciju s brojem 569213 kao argumentom
i na ekran ispisati povratnu vrijednost. Funkcija za potenciranje (x^p) opisana je u zaglavnoj
datoteci math.h, a prototip joj je double pow(double x, double p).*/

#include <stdio.h>

int funkcija(int ulaz) {
	int izlaz = 0, faktormnozenja = 1, znamenka;
	while (ulaz != 0) {
		znamenka = ulaz % 10;
		ulaz = ulaz / 10;

		if (znamenka % 2 == 1) {
			izlaz += znamenka * faktormnozenja;
			faktormnozenja *= 10;
		}
	}
	return izlaz;
}

int main(void) {
	int novi_broj = funkcija(569213);

	printf("%d", novi_broj);
	return 0;
}