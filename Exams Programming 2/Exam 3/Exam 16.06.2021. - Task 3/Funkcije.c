#include <stdlib.h>
#include<stdio.h>
#include "Funkcije.h"

int brojhladnjaka(){
    int n;
    printf("Koliko hladnjaka u popis zelis upisati?\n");
	scanf("%d", &n);

    return n;
    
}

int BrojZaPretragu(){
    int x;
    printf("Hladnjak s kojom ocjenom proizvodjaca zelis?\n");  
	scanf("%d", &x);
    return x;
}
/*
typedef struct hladnjaci {
	int vrsta;
	int vrata;
	struct proizvodjac *Proizvodjac;
	struct hladnjaci* noviCvor;
}HLADNJAK;

typedef struct proizvodjac {
	char *ime;
	char *drzava;
	int ocjena;
}PROIZVODJACI;

*/
void UpisHladnjaka(HLADNJAK* headNode)
{
    HLADNJAK* temp;
    temp=headNode;
    if(temp==NULL){
        perror("Pogreska");
        exit(EXIT_FAILURE);
    }
    temp->Proizvodjac=(PROIZVODJACI*)malloc(sizeof(PROIZVODJACI));
    if(temp->Proizvodjac==NULL){
        perror("Kreiranje");
        exit(EXIT_FAILURE);
    }
    
    temp->Proizvodjac->ime=(char*)malloc(sizeof(char));
    if(temp->Proizvodjac->ime==NULL){
        perror("Kreiranje");
        exit(EXIT_FAILURE);
    }
    
    temp->Proizvodjac->drzava=(char*)malloc(sizeof(char));
    if(temp->Proizvodjac->drzava==NULL){
        perror("Kreiranje");
        exit(EXIT_FAILURE);
    }
    
    scanf("%d",&temp->vrsta);
    scanf("%d",&temp->vrata);
    scanf("%s",temp->Proizvodjac->ime);
    scanf("%s",temp->Proizvodjac->drzava);
    scanf("%d",&temp->Proizvodjac->ocjena);
}

    //dovrsi implementaciju
    /*
    int traverseSLList(SLLNODE* traverseNode) {
    int counter = 0;
    if (traverseNode == NULL) {
        return -1;
    }
    else {
        while (traverseNode) {
            counter++;
            printf("Node number: %d\tnumber: %d\tcurrent node addr:\ %p\tnext node addr: %p\n", counter, traverseNode->number, traverseNode, traverseNode->nextNode);
            traverseNode = traverseNode->nextNode;
        }
    }
    return counter;
}
Tip hladnjaka:
Ime proizvodjaca:
Ocjena brzine dostave:

    */
    
void IspisHladnjaka(HLADNJAK* traverseNode){
    HLADNJAK* temp;
    temp=traverseNode;
    if(temp==NULL){
        perror("Error!");
        exit(EXIT_FAILURE);
    }
    else{
        while(temp){
            printf("Tip hladnjaka: %d\n",temp->vrsta);
            printf("Ime proizvodjaca: %s\n",temp->Proizvodjac->ime);
            printf("Ocjena brzine dostave: %d\n",temp->Proizvodjac->ocjena);
            temp=temp->noviCvor;
        }
    }
}
    
        //dovrsi implementaciju
	
/*
Tip hladnjaka:
Broj vrata:
Ime proizvodjaca:
Drzava proizvodnje:
*/

void IspisZeljenogHladnjaka(HLADNJAK* traverseNode){
    HLADNJAK* temp;
    temp=traverseNode;
    if(temp==NULL){
        perror("Error!");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Tip hladnjaka: %d\n",temp->vrsta);
        printf("Broj vrata: %d\n", temp->vrata);
        printf("Ime proizvodjaca: %s\n",temp->Proizvodjac->ime);
        printf("Drzava proizvodnje: %s\n",temp->Proizvodjac->drzava);
    }
}
        //dovrsi implementaciju
        /*
        SLLNODE* createSLList(void) {
    SLLNODE *headNode = (SLLNODE*)calloc(1, sizeof(SLLNODE));
    if (headNode == NULL) {
        perror("Kreiranje");
        return NULL;
    }
    else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &headNode->number);
        headNode->nextNode = NULL;
    }
    return headNode;
}
        */
HLADNJAK* kreiranjePopisa() {
    HLADNJAK* headNode=(HLADNJAK*)malloc(sizeof(HLADNJAK));
    if(headNode==NULL){
        perror("Kreiranje");
        return NULL;
    }
    else{
        UpisHladnjaka(headNode);
        headNode->noviCvor=NULL;
    }
    return headNode;
        //dovrsi implementaciju
}

/*

SLLNODE* insertNewNodeSLList(SLLNODE* headNode) {
    SLLNODE *newHeadNode = (SLLNODE*)calloc(1, sizeof(SLLNODE));
    if (newHeadNode == NULL) {
        perror("Kreiranje");
        return headNode;
    }
    else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &newHeadNode->number);
        newHeadNode->nextNode = headNode;
    }
    return newHeadNode;
}
*/
HLADNJAK* ubaciNoviCvor(HLADNJAK* headNode) {
    HLADNJAK* newHeadNode=(HLADNJAK*)malloc(sizeof(HLADNJAK));
    if(newHeadNode==NULL){
        perror("Kreiranje");
        return headNode;
    }
    else{
        UpisHladnjaka(newHeadNode);
        newHeadNode->noviCvor=headNode;
    }
    return newHeadNode;
	//dovrsi implementaciju
}

/*
SLLNODE* deleteWholeSLList(SLLNODE* traverseNode) {
    SLLNODE* deleteNode = NULL;
    while (traverseNode) {
        deleteNode = traverseNode;
        traverseNode = traverseNode->nextNode;
        free(deleteNode);
        printf("Oslobodjen chvor: %p\n", deleteNode);
    }
    return NULL;
}
typedef struct hladnjaci {
	int vrsta;
	int vrata;
	struct proizvodjac *Proizvodjac;
	struct hladnjaci* noviCvor;
}HLADNJAK;

typedef struct proizvodjac {
	char *ime;
	char *drzava;
	int ocjena;
}PROIZVODJACI;

*/

HLADNJAK* OslobadjanjeHladnjaka(HLADNJAK* glavniCvor)
{
   HLADNJAK* tmp = NULL;
   while(glavniCvor){
       tmp=glavniCvor;
       glavniCvor=glavniCvor->noviCvor;
       free(tmp->Proizvodjac->ime);
       free(tmp->Proizvodjac->drzava);
       free(tmp->Proizvodjac);
       free(tmp);
   }
   return NULL;
  //dovrsi implementaciju
}

/*
int traverseSLList(SLLNODE* traverseNode) {
    int counter = 0;
    if (traverseNode == NULL) {
        return -1;
    }
    else {
        while (traverseNode) {
            counter++;
            printf("Node number: %d\tnumber: %d\tcurrent node addr:\ %p\tnext node addr: %p\n", counter, traverseNode->number, traverseNode, traverseNode->nextNode);
            traverseNode = traverseNode->nextNode;
        }
    }
    return counter;
}
*/
HLADNJAK* PretragaPopisa(HLADNJAK* headNode, int x){
    HLADNJAK* temp;
    temp=headNode;
    if(temp==NULL){
        perror("Error!");
        exit(EXIT_FAILURE);
    }
    else{
        while(temp){
            if(temp->Proizvodjac->ocjena==x){
                return temp;
            }
            temp=temp->noviCvor;
        }
        return temp;
    }
}

	//dovrsi implementaciju





