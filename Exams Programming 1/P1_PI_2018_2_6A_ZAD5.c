/*Napisati funkciju koja odreuje i vraca znak koji se najcešce pojavljuje u predanom
joj stringu. Ukoliko su svi znakovi stringa meusobno razliciti, funkcija vraca prvi znak stringa.
U svrhu testiranja u funkciji main() dinamicki zauzeti memoriju za 151 podatak tipa char (u
potpunosti rukovati memorijom). Omoguciti korisniku unos stringa (osigurati da se ne premaši
velicina prethodno zauzetog polja). Pozvati funkciju s navedenim stringom kao argumentom i
ispisati na ekran povratnu vrijednost.*/

#include <stdio.h>
#include <stdlib.h>

char najcesce_slovo(char *ulazni_string) {
	int ponavljanja[128] = {0};
	//{0} postavlja sve elemente niza na nulu
	//u ovaj niz brojeva cemo spremati koliko pojavljivanja ima pojedini znak
	//broj pojavljivanja za svaki znak ce biti spremljen na indeksu koji je jednak ASCII
	//vrijednosti tog znaka (za 'A' ce to biti [65] , za 'B' [66] itd.)
	//niz ima 128 elemenata jer toliko ASCII tablica ima znakova

	int i, max, index_najcesceg;
	char slovo, slovo1;
	for (i = 0; ulazni_string[i] != '\0'; i++) {
		slovo = ulazni_string[i];
		ponavljanja[slovo] += 1;
	}
	//idemo provjeriti ima li svih znakova jednako, ako ima vracamo prvo slovo ulaznog stringa

	int svi_isti = 1; //svi se jednako javljaju, dok se ne pokaze drukcije
	for (i = 0; ulazni_string[i + 1] != '\0'; i++) {
		//ide i + 1 jer cemo gledati jedan znak unaprijed od trenutnog 
		//pa da u zadnjem koraku ne izadje van stringa
		slovo = ulazni_string[i];
		slovo1 = ulazni_string[i + 1];
		if (ponavljanja[i] != ponavljanja[i + 1]) {
			svi_isti = 0;
			break; //nasli smo prvu razliku pa prekidamo petlju
		}
	}
	if (svi_isti == 1) {
		return ulazni_string[0];
	} else { //idemo naci najponavljaniji znak
		index_najcesceg = 0; //zasad cemo reci da je prvi najponavljaniji
		max = ponavljanja[index_najcesceg]; //max uvijek mora biti neka vrijednost iz polja
		for (i = 0; ulazni_string[i] != 0; i++) {
			slovo = ulazni_string[i];
			if (ponavljanja[slovo] > max) {
				//ako je trenutni znak cesci od dosadasnjeg maksimuma, onda je trenutni novi max
				max = ponavljanja[slovo];
				index_najcesceg = i;
			}
		}
		return ulazni_string[index_najcesceg];
	}
}

int main(void) {
	char *str = (char *)calloc(151, sizeof(char));
	if (NULL == str) {
		printf("Calloc nije uspio");
		return 1; //prekidamo program
	}

	fgets(str, 151, stdin);
	//NE KORISTITI scanf
	//on ne ponasa se dobro s razmacima, i ne postuje velicinu polja

	char naj_slovo = najcesce_slovo(str);

	printf("%c", naj_slovo);

	free(str); //sve sto je zauzeto mallocom i callocom treba osloboditi
	return 0;
}