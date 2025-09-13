/*Napisati funkciju koja u predanom stringu sva mala slova zamijenjuje velikim slovima.
U svrhu testiranja u funkciji main() dinamicki zauzeti memoriju za 200 podataka tipa
char (u potpunosti rukovati memorijom). Omoguciti korisniku unos stringa (osigurati da se
ne premaši velicina prethodno zauzetog polja). Pozvati funkciju s navedenim stringom kao
argumentom i naknadno ga ispisati na ekran. Za rješavanje zadatka nije dozvoljeno koristiti
funkciju toupper() standardne biblioteke. [Znakovi A, B, ... , Z imaju ASCII vrijednosti
65, 66, ... , 90, dok znakovi a, b, ... , z imaju ASCII vrijednosti 97, 98, ... , 122, redom]*/

#include <stdio.h>
#include <stdlib.h>

//funkcija ce raditi sve promjene na postojecem stringu i ne pravi nista novo tako da ide void povratni tip
//ne treba dodatni int parametar za velicinu stringa kada znamo da svaki string sigurno zavrsava sa znakom '\0'
void funkcija(char *neki_string) {
	int i;
	for (i = 0; neki_string[i] != '\0'; i++) {
		//prolazimo kroz string sve dok znak na mjestu i nije jednak nul-terminatoru za kraj stringa, onda prekidamo
		if (neki_string[i] >= 'a' && neki_string[i] <= 'z') {
			//kompajler ce automatski za nas pretvoriti 'a' u ascii broj 97
			//tu provjeravamo nalazi li se trenutno slovo u rasponu malih slova [a, z] odnosno [97, 122]
			neki_string[i] -= 'a' - 'A'; // 'a' - 'A' je zapravo 97 - 65 = 32
			//kako bi prebacili mala slova u velika moramo ih "pomaknuti" za 32 mjesta nazad
			//to znaci smanjiti vrijednost za 32
			//jer se svako veliko slovo nalazi 32 znaka prije istog malog slova
		}
	}
	//void funkcija ne mora imati return
}

int main(void) {
	char* mali_string = (char*)calloc(200, sizeof(char));
	if (NULL == mali_string) {
		return 1;
	}
	fgets(mali_string, 200, stdin);
	//NE KORISTITI scanf JER ON NE RADI DOBRO SA RAZMACIMA I NE PAZI NA PREMASIVANJE VELICINE
	//SINTAKSA fgets-a:
	//	fgets(ime_stringa, velicina_stringa, stdin);

	funkcija(mali_string);
	printf("%s", mali_string); //%s ispisuje string

	free(mali_string);
	return 0;
}