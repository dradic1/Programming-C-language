/*Napisati funkciju koja odreuje i vraca broj s najvecim brojem dijelitelja iz intervala
[a, b] c N. Izdvojiti korak odreivanja broja dijelitelja pojedinog broja u posebnu funkciju. U
svrhu testiranja u funkciji main() pozvati napisanu funkciju s brojevima 1 i 5000 kao argumentima
i na ekran ispisati povratnu vrijednost.*/

#include <stdio.h>

int broj_djelitelja(int n) {
	int br = 0;
	int i;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			br++;
		}
	}
	return br;
}

int najveci_br_djelitelja(int a, int b) {
	int najveci = a; //bilo kakav max mora biti iz raspona [a,b]
	int i;
	for (i = a; i <= b; i++) {
		if (broj_djelitelja(i) > broj_djelitelja(najveci)) {
			//ako trenutni broj ima vise djelitelja onda je on novi najveci
			najveci = i;
		}
	}
	return najveci;
}

int main(void) {
	int r = najveci_br_djelitelja(1, 5000);
	printf("%d", r);
	return 0;
}