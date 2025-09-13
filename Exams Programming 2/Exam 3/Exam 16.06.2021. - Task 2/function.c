#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


void zapisivanjeKnjige(char* file, int n){
    int i;
	FILE* pFile = fopen(file, "wb");
	if (pFile == NULL) {
		perror("No file");
		exit(EXIT_FAILURE);
	}
	KNJIGA* temp = (KNJIGA*)calloc(n,sizeof(KNJIGA));
	if (temp == NULL) {
		perror("Din. alloc.");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<n;i++){
	    scanf("%49[^\n]",temp[i].ime);
	    getchar();
	    scanf("%49[^\n]",temp[i].autor);
	    getchar();
	    scanf("%ld",&temp[i].isbn);
	    getchar();
	}
	fwrite(temp,sizeof(KNJIGA),n,pFile);
	fwrite(&n,sizeof(int),1,pFile);
	free(temp);
	fclose(pFile);
}  

KNJIGA* citajKnjige (char* file, int n){
	int i;
	FILE* pFile = fopen(file, "rb");
	if (pFile == NULL) {
		perror("No file");
		exit(EXIT_FAILURE);
	}
	KNJIGA* temp = (KNJIGA*)calloc(n,sizeof(KNJIGA));
	if (temp == NULL) {
		perror("Din. alloc.");
		exit(EXIT_FAILURE);
	}
	
	printf("Knjige u datoteci su:\n");
	fread(temp, sizeof(KNJIGA), n, pFile);
	fclose(pFile);
	return temp;
}

KNJIGA* oslobodiMe(KNJIGA* K){
	free (K);
	return NULL;
}