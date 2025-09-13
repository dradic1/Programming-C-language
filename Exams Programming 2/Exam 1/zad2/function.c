#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void zapisivanjeKnjige(char* file) {
 
	FILE* pFile = fopen(file, "ab+");
	if (pFile == NULL) {
		perror("No file");
		exit(EXIT_FAILURE);
	}
	
	KNJIGA* temp = (KNJIGA*)calloc(1,sizeof(KNJIGA));
	if (temp == NULL) {
		perror("Din. alloc.");
		exit(EXIT_FAILURE);
	}
	printf ("Unesi naslov: ");
	scanf("%49[^\n]",temp->ime);
	getchar();
	printf ("Unesi autora: ");
	scanf("%49[^\n]",temp->autor);
	getchar();
	printf ("Unesi ISBN: ");
	scanf("%ld",&temp->isbn);
	getchar();
	
	fwrite (temp, sizeof(KNJIGA),1,pFile);
	fclose(pFile);
	free (temp);
	
}
