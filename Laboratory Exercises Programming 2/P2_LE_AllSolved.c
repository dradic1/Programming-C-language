Laboratory Exercises – Programming 2
You can search using the format NZAD M, where N is the number of the laboratory exercise and M is the number of the task for that exercise.

LV1

//1ZAD 3
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    int a[32],i,br=0,s;
    srand((unsigned)time(NULL));
    for(i=0;i<32;i++)
        a[i]=(float)rand()/RAND_MAX*2; 
    for(i=0;i<32;i++)
        printf("%d",a[i]);
    if (a[0]==0){
        for(i=0;i<32;i++)
            br+=a[i]*(int)pow(2,fabs(i-31));
    }
    else if (a[0]==1){
        for(i=31;i>=0;i--){
        if(a[i]==1){
            for(s=i-1;s>=0;s--){
            if(a[s]==0)a[s]=1;
            else if(a[s]==1)a[s]=0;
            }
            break;
        }
    }
     for(i=0;i<32;i++)
            br+=a[i]*(int)pow(2,fabs(i-31));
        br=-br;
    }
    printf("\nConverted to decimal:%d",br);
    return 0;
}


LV2

//2ZAD 1
#include <stdio.h>

struct complex {
    float x;
    float y;
} a, b;

int main() {
    printf("\nComplex 1:");
    scanf("%f %f", &a.x, &a.y);
    printf("\nComplex 2:");
    scanf("%f %f", &b.x, &b.y);
    printf("REZULTATI:\n%.3f, %.3f*i\n%.3f, %.3f*i", (a.x+b.x), (a.y+b.y), (a.x-b.x), (a.y-b.y));
    return 0;
}

//2ZAD 2
#include <stdio.h>

struct datum{
    int dan;
    int mj;
    int god;
};
typedef struct ucenik{
    char ime[20];
    char pre[20];
    unsigned long long int mat;
    float pros;
    struct datum rod;
	}UCENIK;
int main(void){
    int n;
    do{
        printf("\nUnesite broj ucenika razreda, max 40: ");
        scanf("%d",&n);
    }while(n<=0 || n>40);
    UCENIK r[n];
    int maxi;
    float max=0;
    for (int i=0;i<n;i++){
        printf("\nUnesite ime %d. ucenika: ", i+1);
        scanf("%19s",r[i].ime);
        printf("\nUnesite prezime %d. ucenika: ", i+1);
        scanf("%19s",r[i].pre);
        printf("\nUnesite maticni broj %d. ucenika: ", i+1);
        scanf("%llu",&r[i].mat);
        printf("\nUnesite prosjek %d. ucenika: ", i+1);
        scanf("%f",&r[i].pros);
        printf("\nUnesite datum rodjenja %d. ucenika u formatu dan.mj.god.: ", i+1);
        scanf("%d.%d.%d.",&r[i].rod.dan,&r[i].rod.mj,&r[i].rod.god);
        if(r[i].pros>max){
            max=r[i].pros;
            maxi=i;
        }
	}
    printf("REZULTATI:\n%s %s",r[maxi].ime,r[maxi].pre);
    return 0;
}

//2ZAD 3
#include <stdio.h>
#include <string.h>

struct stan{
    int pov;
    int cj;
    char adr[50];
    char er[3];
    int ku;
};
int main(void){
    int n;
    do{
        printf("\nUnesite broj stanova koje zelite unesti, min 2, max 20: ");
        scanf("%d",&n);
    }while(n<2 || n>20);
    struct stan st[20];
    int i,stop=0;
    char ku_odg[3];
    for (i=0;i<n;i++){
    printf("\nUnesite povrsinu %d. stana u metrima na kvadrat: ", i+1);
    scanf("%d",&st[i].pov);    
    printf("\nUnesite cjenu %d. stana u eurima: ", i+1);
    scanf("%d",&st[i].cj);
    printf("\nUnesite adresu %d. stana: ", i+1);
    scanf("%49s",st[i].adr);
    printf("\nUnesite energetski razred %d. stana: ", i+1);
    scanf("%s",st[i].er);
    do{
        printf("\nDa li %d. stan ima klima uredaj, odgovorite sa \"da\" ili \"ne\": ", i+1);
        scanf("%2s",&ku_odg);
    }while(strcmp("da",ku_odg)!=0 && strcmp("ne",ku_odg)!=0);
    if(strcmp("da",ku_odg)==0)st[i].ku=1;
    else if(strcmp("ne",ku_odg)==0)st[i].ku=0;
}
printf("REZULTATI:\n");
for (i=0;i<n;i++){
    if((st[i].cj/st[i].pov)<900){
        printf("%s, %d\n", st[i].adr, st[i].cj);
        stop=1;
    }
    if(((st[i].cj/st[i].pov)>1100) && st[i].ku==0){
        printf("%s, %d\n", st[i].adr, st[i].cj);
        stop=1;
    }
}
if(stop == 0)printf("Niti jedan stan ne odgovara kriterijima.");
return 0;
}


LV3

//3ZAD 1
#include<stdio.h>

int main(void) {
    char *m[]={ "sijecanj", "veljaca", "ozujak", "travanj","svibanj", "lipanj", "srpanj", "kolovoz", "rujan","listopad", "studeni", "prosinac"};
    int zm;
    printf("Unesite broj mjeseca koji zelite:");
    scanf("%d",&zm);
    if (zm>=1 && zm<=12)
    printf("REZULTATI:\n%s",*(m+zm-1));
    else
    printf("REZULTATI:\n\"Nekorektan broj mjeseca\"");
    return 0;
}

//3ZAD 2
#include <stdio.h>
#include <stdlib.h>

int funk(int **mat, int n, int m){
    int nv=**mat;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) 
        if(mat[i][j]>nv) nv=mat[i][j];
      return nv;
}
int main(){
    int **mat,n,m,i,j;
    do{
        printf("Unesite broj redaka matrice:");
        scanf("%d",&n);
    }while(n<2||n>5);
    do{
        printf("Unesite broj stupaca matrice:");
        scanf("%d",&m);
    }while(m<2||m>8);
    mat=(int**)malloc(n*sizeof(int*));
    if(mat==NULL)
      return 1;
    for(i=0;i<n;i++)
      *(mat+i)=(int*)malloc(m*sizeof(int));
       for(i=0;i<n;i++)
           if(*(mat+i)==NULL) 
                return 1;
    printf("Unesite cijelobrojne vrijednosti matrice:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) 
            scanf("%d",&mat[i][j]);
    printf("REZULTATI:\n%d",funk(mat,n,m));
    for(i=0;i<n;i++)
        free(*(mat+i));
    free(mat);
    return 0;
}

//3ZAD 3
#include <stdio.h>
#include <stdlib.h>

void funk(int **mat, int n, int m, int k){
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        mat[i][j]*=k;
}
int main(){
    int **mat,n,m,i,j,k;
    do{
        printf("Unesite broj redaka matrice:");
        scanf("%d",&n);
    }while(n<2||n>10);
    do{
        printf("Unesite broj stupaca matrice:");
        scanf("%d",&m);
    }while(m<2||m>10);
    printf("Unesite jedan cijeli broj:");
    scanf("%d",&k);
	mat=(int**)malloc(n*sizeof(int*));
    if(mat==NULL)
      return 1;
    for(i=0;i<n;i++)
        *(mat+i)=(int*)malloc(m*sizeof(int));
        for(i=0;i<n;i++)
            if(*(mat+i)==NULL) 
                return 1;
    printf("Unesite cijelobrojne vrijednosti matrice:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) 
            scanf("%d",&mat[i][j]);
    funk(mat,n,m,k);
    printf("REZULTATI:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) 
            printf("%d\t",mat[i][j]);
    for(i=0;i<n;i++)
      free(*(mat+i));
    free(mat);
    return 0;
}

LV4

//4ZAD 1
#include <stdio.h>
#include <math.h>

struct dot{
    float x;
    float y;
    float z;
} d[10];

struct tria{
    struct dot *d1;
    struct dot *d2;
    struct dot *d3;
}r[10];

float mod(struct dot *a, struct dot *b){
    return sqrt(pow(b->x - a->x,2)+pow(b->y - a->y,2)+pow(b->z - a->z,2));
}

float cf(struct tria *r){
    return mod(r->d1,r->d2)+mod(r->d2,r->d3)+mod(r->d1,r->d3);
}
}

int main(){
    int n,m,i;
    printf("Upisi broj tocaka: ");
    scanf ("%d",&n);
    printf("Upisi broj trokuta: ");
    scanf ("%d",&m);
    for (i = 0; i < n; i++) {
        printf("Upisi vrijednosti %d.tocke : ", i+1);
        scanf ("%f %f %f", &d[i].x, &d[i].y, &d[i].z);
        }
    for (i = 0; i < m; i++) {
        int rd1,rd2,rd3;
        printf("Odaberite zeljene tocke za %d. trokut: ", i+1);
        scanf ("%d %d %d", &rd1, &rd2, &rd3 );
        r[i].d1=&d[rd1-1];
        r[i].d2=&d[rd2-1];
        r[i].d3=&d[rd3-1];
    }
    
    float max_cf=cf(&r[0]);
    for (i = 0; i < m; i++) {
        if(max_cf<cf(&r[i]))
        max_cf=cf(&r[i]);
    }
    printf("REZULTATI:\n%.2f\n",max_cf);
    return 0;
}

//4ZAD 2
#include <stdio.h>
#include <math.h>

struct artkl{
    char ime[50];
    float cijena;
    int kolicina;
};

int main(){
    int n,i;
    struct artkl br[10];
    struct artkl *max;
    do{
        printf("Unesite koliko artikala zelite unesiti: ");
        scanf ("%d",&n);
    }while(n<0||n>10);
    for (i=0;i<n;i++){
    printf("Unesite ime %d. artikla: ", i+1);
    scanf ("%49s",br[i].ime);  
    printf("Unesite cijenu %d. artikla: ", i+1);
    scanf ("%f",&br[i].cijena);
    printf("Unesite kolicinu %d. artikla: ", i+1);
    scanf ("%d",&br[i].kolicina);
    }
    max=&br[0];
    for (i=0;i<n;i++){
        if(max->cijena<br[i].cijena)
        max=&br[i];
    }
    printf("REZULTATI:\ncijena: %.2f, kolicina: %d", max->cijena, max->kolicina);
    return 0;
}


LV 5

//5ZAD 1
//lv5.c
#include "myheader.h"
#include <stdio.h>

#include<stdlib.h>

int main(void)
{
	int **M=NULL;
	int m, n, K;
	printf("Unesi n i m: ");
	scanf("%d%d", &n, &m);

    printf("Unesi k: ");
    scanf("%d", &K);


	M = allocateMatrix(n, m);

	inputMatrix(M, n, m);

    matrixTimesK(M, n, m, K);

    printf("REZULTATI:\n");
    printMatrix(M, n, m);

	return 0;
}

//myheader
#include <stdio.h>

#ifndef HEAD_H
#define HEAD_H

int** allocateMatrix(int n,int m);
void inputMatrix(int** mat,int n,int m);
void matrixTimesK(int** mat, int n,int  m,int k);
void printMatrix(int** mat,int n,int m);

#endif

//functions.c
#include <stdio.h>
#include<stdlib.h>

int** allocateMatrix(int n,int m){
    int**mat;
    int i;
    mat=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
       mat[i]=(int*)malloc(m*sizeof(int));
    return mat;
}

void inputMatrix(int** mat,int n,int m){
    int i,j;
    for(i=0;i<n;i++)
       for(j=0;j<m;j++)
          scanf("%d", &mat[i][j]);
}

void matrixTimesK(int** mat, int n,int  m,int k){
    int i,j;
    for(i=0;i<n;i++)
       for(j=0;j<m;j++)
          mat[i][j]*=k;
}

void printMatrix(int** mat,int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

//5ZAD 2
//lv5-2.c
#include "lv5-2-header.h"
#include <stdio.h>

//ovaj kod ne trebate mijenjati, vec nadopuniti lv5-2-func.c te lv5-2-header.h

/*Napišite C program koji će omogućiti unos n (n<10)sto predstavlja broj artikala. 
Pomocu funkcije ucitavanje unijet elemente u polje struktura artikala
(struktura ima članove ime (char), kolicina (int) i cijena (float), te je pomocu typedef dan novi naziv strukturi: ARTIKL).
U pokazivač max vratiti memorijsku adresu srukture najskupljeg artikla. */

int main(void)
{
  ARTIKL *max, artikli[100];
  int n;
  printf("Unesi n: ");
  scanf("%d", &n);
  
  ucitavanje(&artikli[0], n);
  max=najveci(&artikli[0], n);



  // ispis ne dirati, mora koristiti pokazivac max
  printf("REZULTATI:\n");
  printf("cijena: %.2f, kolicina: %d", max->cijena, max->kolicina);
  return 0;
}

//lv5-2-func.c
#include <stdio.h>
#include "lv5-2-header.h"


void ucitavanje(ARTIKL *artikli,int n){
        for(int i=0;i<n;i++){
            scanf("%29s", artikli[i].ime);
            scanf("%d",&artikli[i].kolicina);
            scanf("%f",&artikli[i].cijena);
        }
}

ARTIKL* najveci(ARTIKL *artikli, int n){
    ARTIKL *max;
    max=&artikli[0];
    for(int i=0;i<n;i++){
      if(max->cijena < artikli[i].cijena)
      max=&artikli[i];
  }
  return max;
}

//lv5-2-header.h
#include <stdio.h>


#ifndef HEAD_H
#define HEAD_H

typedef struct artikl {
  char ime[30];
  int kolicina;
  float cijena;
}ARTIKL;
void ucitavanje(ARTIKL *artikli,int n);
ARTIKL* najveci(ARTIKL *artikli, int n);

#endif


LV 6

//6ZAD 1
//program.c
/* Ovu datoteku ne mijenjate */

#include <stdio.h>
#include "myheader.h"



int main(void)
{
  int n, m;
  Tocka tocke[100];
  Trokut trokuti[100];
  float opseg;

  printf("Upisi broj tocaka koje zelis unijeti: ");
  scanf("%d", &n);

  printf("Upisi broj trokuta koje zelis unijeti: ");
  scanf("%d", &m);

  unesiTocke(tocke, n);
  unesiTrokute(trokuti, tocke, m);

  opseg = pronadjiNajveciOpseg(trokuti, m);

  printf("REZULTATI:\n");
  printf("%.2f", opseg);

	return 0;
}

//myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

typedef struct tocka {
    float x;
    float y;
    float z;
} Tocka;
typedef struct trokut {
    struct tocka *t1;
    struct tocka *t2;
    struct tocka *t3;
} Trokut;

void unesiTocke(Tocka*, int );
void unesiTrokute(Trokut*, Tocka*, int );
float pronadjiNajveciOpseg(Trokut*, int );
float mod(Tocka *, Tocka *);
float opseg(Trokut *);

#endif

//functions.c
#include <stdio.h>
#include <math.h>
#include "myheader.h"

void unesiTocke(Tocka* d, int n){
    for(int i=0;i<n;i++){
        scanf("%f %f %f", &d[i].x, &d[i].z, &d[i].y);
}
}

void unesiTrokute(Trokut*r, Tocka*d, int m){
    int i,a,b,c;
    for(i=0;i<m;i++){
        scanf("%d %d %d", &a, &b, &c);
        r[i].t1=&d[a];
        r[i].t2=&d[b];
        r[i].t3=&d[c];
	}
}

float mod(Tocka *a, Tocka *b){
    return sqrt(pow(b->x - a->x,2)+pow(b->y - a->y,2)+pow(b->z - a->z,2));
}

float opseg(Trokut *r){
    return mod(r->t1,r->t2)+mod(r->t2,r->t3)+mod(r->t1,r->t3);
}

float pronadjiNajveciOpseg(Trokut*r, int m){
    float max=opseg(&r[0]);
    for (int i=0;i<m;i++){
        if(max<opseg(&r[i]))
        max=opseg(&r[i]);
}
    return max;
}

//6ZAD 2
//program.c
#include <stdio.h>
#include "myheader.h"

void ispisRacuna(Racun *r) {
  int i;
  float cijena;
  int kolicina;
  printf("REZULTATI:\n");
  printf("Kupac: %s\n", r->kupac);
  printf("Prodavac: %s\n", r->prodavac);
  printf("-----------------------------\n");
  printf("Artikli: \n");
  printf("rb   naziv                    kolicina    cijena    ukupno\n");
  for (i = 0; i < r->broj_artikala; i++) {
    cijena = r->artikli[i].cijena;
    kolicina = r->artikli[i].kolicina;
    printf("%-4d %-25s %-10d %-10.2f %.2f\n", i+1, r->artikli[i].naziv, kolicina, cijena, kolicina*cijena);
  }
  printf("\nUkupan iznos racuna: %.2f", r->ukupan_iznos);
}

int main(void)
{
  int n, m;
  Racun racun;

  unesiPodatkeRacuna(&racun);

  ispisRacuna(&racun);

	return 0;
}

//myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

typedef struct artikl {
  char naziv[50];
  float cijena;
  int kolicina;
} Artikl;
typedef struct racun {
  char prodavac[50];
  char kupac [50];
  Artikl artikli[10];
  int  broj_artikala;
  float ukupan_iznos;
} Racun;

void unesiPodatkeRacuna(Racun*);

/* Ukoliko koristite dodatne funkcije mozete ih navesti nakon ovog komentara */


#endif

//functions.c
//ovdje pisete implementaciju potrebnih funkcija. 
//ukoliko zelite koristiti dodatne funkcije, njihove deklaracije
//mozete navesti u datoteci zaglavlja. 
//Funkcija unesiPodatkeRacuna je obvezna.

#include <stdio.h>
#include "myheader.h"


void unesiPodatkeRacuna(Racun *r) {

}

/*
Primjer kako bi izgledalo izvodjenje programa, 
prema ovom redosljedu trebate upisivati podatke u strukture.
Ispis racuna se izvodi sam. 

Unesi ime kupca: Petar Kupcevic 
Unesi ime prodavaca: Ivan Prodavacevic
Unesi broj artikala: 4
Unesi ime artikla: Pivo Osjecko 0.5l
Unesi cijenu artikla: 5.99
Unesi kolicinu pojedinog artikla: 120
Unesi ime artikla: Brandy Badel 1l
Unesi cijenu artikla: 69.99
Unesi kolicinu pojedinog artikla: 5
Unesi ime artikla: Vino Crno Ribar 1l
Unesi cijenu artikla: 12.99
Unesi kolicinu pojedinog artikla: 55
Unesi ime artikla: Coca Cola 2l
Unesi cijenu artikla: 12.99
Unesi kolicinu pojedinog artikla: 20

REZULTATI:
Kupac: Petar Kupcevic
Prodavac: Ivan Prodavacevic
-----------------------------
Artikli: 
rb   naziv                    kolicina    cijena    ukupno
1    Pivo Osjecko 0.5l         120        5.99       718.80
2    Brandy Badel 1l           5          69.99      349.95
3    Vino Crno Ribar 1l        55         12.99      714.45
4    Coca Cola 2l              20         12.99      259.80

Ukupan iznos racuna: 2043.00
*/


LV 7

//7ZAD 2
//program.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m,i,j;
    float **a;
    FILE *pf;
    if((pf=fopen("in.txt","r"))==NULL)
        return 1;
    fscanf(pf,"%d %d", &m, &n);
    fclose(pf);
    a=(float**)malloc(m*sizeof(float*));
    if(a==NULL)
        return 1;
    for(i=0;i<m;i++)
        a[i]=(float*)malloc(n*sizeof(float));
    if(a[i]==NULL) 
        return 1;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%f", &a[i][j]);
    if((pf=fopen("out.txt","w"))==NULL)
        return 1;
    for(i=0;i<m-1;i++){
        for(j=1;j<n;j++){
            fprintf(pf,"%.2f\t", a[i][j]);
            printf("%.2f\t", a[i][j]);
        }
        fprintf(pf,"\n");
        printf("\n");
    }
    for(i=0;i<m;i++)
        free(a[i]);
    free(a);
    fclose(pf);
    return 0;
}

//in.txt
3 4

//7ZAD 3
//scratch.c
/* U ovoj aktivnosti možete slobodno testirati VPL sustav */
#include<stdio.h>

int main(void) {
    char str[20];
    FILE *pf;
    if((pf=fopen("Prva.txt","r"))==NULL)
        return 1;
    fgets (str,20, pf);
    fclose(pf);
    if((pf=fopen("Druga.txt","w+"))==NULL)
        return 1;
    for(int i=0;i<20;i++){
        if(str[i]>='a'&& str[i]<='z')
        str[i]-=32;
    }
    printf("%s",str);
    fprintf(pf,"%s",str);
    fclose(pf);
    return 0;
}

//Prva.txt
OvO je neKi TeksT.


LV 8

//8ZAD 1
/* Kako bi autograder mogao uspjesno upisati strukturu u datoteku
morate koristiti ovako definirane strukture


struct podaci
{		
	char prezime[20];
	char ime[20];
	int sifra;
	char adresa[100];
	int br_tel;
};

*/

#include <stdio.h>
#include <stdlib.h>

FILE *pf;

typedef struct info{
    char p[20];
    char ime[20];
    int s;
    char a[100];
    int bt;
}INFO;

INFO* cl;

void mtxt(){
    if((pf=fopen("clanovi.txt","wb+"))==NULL){
        fprintf(stderr,"Greska_mtxt");
        exit(EXIT_FAILURE);
    }
}

void rtxt(){
    fseek(pf, 0L, SEEK_END);
    int brcl=ftell(pf)/sizeof(INFO);
    rewind(pf);
    cl=(INFO*)malloc(brcl*sizeof(INFO));
    if(cl==NULL){
        fprintf(stderr,"Greska_rtxt");
        exit(EXIT_FAILURE);
    }
    fread(cl,sizeof(INFO),brcl,pf);
    for (int i = 0; i < brcl; i++) {
		printf("\nPodatci %d.clana:\n", i+1);
		printf("%s\n", cl[i].p);
		printf("%s\n", cl[i].ime);
		printf("%d\n", cl[i].s);
		printf("%s\n", cl[i].a);
		printf("%d\n", cl[i].bt);
    }
	free(cl);
    if(brcl==0)
	    printf("Nema upisanih clanova!\n");
}
    
void atxt(){
   INFO* c=(INFO*)malloc(1*sizeof(INFO));
    if(c==NULL){
        fprintf(stderr,"Greska_rtxt");
        exit(EXIT_FAILURE);
    }
    printf("Unesite podatke clana:\n");
    scanf("%s", c->p);
	scanf("%s", c->ime);
	scanf("%d", &c->s);
	getchar();
	scanf(" %[^\n]", c->a);
	scanf("%d", &c->bt);
	fwrite(c,sizeof(INFO),1,pf);
	free(c);
}

void menu(){
    int n;
    int pfop=0;
    printf ("Opcije:\n 1 - Kreiranje dokumenta popisa clanova\n");
    printf(" 2 - Citanje popisa\n 3 - Dodavanje clanova\n 4 - Izlaz iz programa\n");
    do{
        printf ("\nUpisite broj opcije koju zelite odabrati: ");
        scanf("%d",&n);
        switch(n){
        case(1):
            mtxt();
            pfop=1;
            printf ("Datoteka stvorena/otvorena!\n");
            break;
        case (2):
            rtxt();
            break;
        case (3):
            atxt();
            printf ("Clan uspjesno dodan!\n");
            break;
        case (4):
            if(pfop==1)
                fclose(pf);
            exit(EXIT_SUCCESS);
        }
    }while(n!=4);
}

int main(){
    menu();
}

//8ZAD 2
/* Kako bi autograder mogao uspjesno upisati strukturu u datoteku
morate koristiti ovako definirane strukture


struct podaci
{		
	char prezime[20];
	char ime[20];
	int sifra;
	char adresa[100];
	int br_tel;
};
	
struct posudba{
	char ime_filma[20];
	int datum;
	int sif;
};

Ulazni podaci u program su zapisani ispod. Tekst poslije znaka # označava komentar
linije i ne predstavlja ulaz u program:
1               # kreiranje filea
3               # upis podataka o clanu
Peric                                                                   
Pero                                                                       
1               #sifra clana                                                                  
Osjecka 132     #adresa                                                        
12345           #br tel
4               #izbornik posudbe
2               #broj filmova za posudbu                                  
1               #sifra clana koji posudjuje film                                              
Mrak film 1     #naziv filma
34              #dan posudbe
Mrak film 2     #naziv filma
35              #dan posudbe
5               #zavrsetak rada programa
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

FILE* pf;
FILE* pf1;

typedef struct info {
    char p[20];
    char i[20];
    int s;
    char a[100];
    int bt;
}INFO;

typedef struct {
    char i[20];
    int  d;
    int  s;
}FILM;

INFO* cl;
FILM* film;

void mtxt() {
    if ((pf = fopen("clanovi.txt", "ab+")) == NULL) {
        fprintf(stderr, "Greska_mtxt");
        exit(EXIT_FAILURE);
    }
}

void rtxt() {
    fseek(pf, 0L, SEEK_END);
    int brcl = ftell(pf) / sizeof(INFO);
    rewind(pf);
    cl = (INFO*)malloc(brcl * sizeof(INFO));
    if (cl == NULL) {
        fprintf(stderr, "Greska_rtxt");
        exit(EXIT_FAILURE);
    }
    fread(cl, sizeof(INFO), 1, pf);
    for (int i = 0; i < brcl; i++) {
        printf("\nPodatci %d.clana:\n", i + 1);
        printf("%s\n", cl[i].p);
        printf("%s\n", cl[i].i);
        printf("%d\n", cl[i].s);
        printf("%s\n", cl[i].a);
        printf("%d\n", cl[i].bt);
        free(cl);
    }
    if (brcl == 0)
        printf("Nema upisanih clanova!\n");
}

void atxt() {
    INFO c;
    printf("Unesite podatke clana:\n");
    scanf("%s", c.p);
    scanf("%s", c.i);
    scanf("%d", &c.s);
    getchar();
    scanf("%[^\n]", c.a);
    scanf("%d", &c.bt);
    fwrite(&c, sizeof(INFO), 1, pf);
}

void mpos() {
    if ((pf1 = fopen("posudba.txt", "wb+")) == NULL) {
        fprintf(stderr, "Greska_mpos");
        exit(EXIT_FAILURE);
    }
    if ((pf1 = fopen("posudba", "wb+")) == NULL) {
        fprintf(stderr, "Greska_mpos");
        exit(EXIT_FAILURE);
    }
}

int brf() {
    fseek(pf1, 0L, SEEK_END);
    int brf = ftell(pf1) / sizeof(FILM);
    rewind(pf1);
    return brf;
}


int brfcl(int s) {
    film = (FILM*)malloc(brf() * sizeof(FILM));
    if (film == NULL) {
        fprintf(stderr, "Greska_falloc");
        exit(EXIT_FAILURE);
    }
    fread(film, sizeof(FILM), 1, pf1);
    int i, br = 0;
    for (i = 0; i < brf(); i++)
        if (film[i].s == s)
            br++;
    free(film);
    return br;
}

void pfilm() {
    FILM* f;
    int i, n, s,stop=0;
    do {
        do {
            printf("Koliko filmova zelite posuditi (max.4): ");
            scanf("%d", &n);
        } while (n < 1 || n>4);
        printf("Sifra clana:");
        scanf("%d", &s);
        if ((n + brfcl(s)) > 4) {
            printf("Clan je presao limit.");
            stop = 1;
        }
    } while (stop == 1);
    f = (FILM*)malloc(n * sizeof(FILM));
    if (f == NULL) {
        fprintf(stderr, "Greska_pfilm");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++) {
        printf("Ime filma: ");
        getchar();
        scanf("%[^\n]", f[i].i);
        printf("Datum: ");
        scanf("%d", &f[i].d);
        f[i].s = s;
        fwrite(&f[i], sizeof(f[i]), 1, pf1);
    }
    free(f);
}

void pread() {
    film = (FILM*)malloc(brf() * sizeof(FILM));
    if (film == NULL) {
        fprintf(stderr, "Greska_falloc");
        exit(EXIT_FAILURE);
    }
    fread(film, sizeof(FILM), 1, pf1);
    for (int i = 0; i < brf(); i++) {
        printf("\nPodatci %d. posudjenog filma:\n", i + 1);
        printf("%s\n", film[i].i);
        printf("%d\n", film[i].d);
        printf("%d\n ", film[i].s);
    }
    free(film);
}

void menu() {
    int n;
    int pfop = 0;
    printf("Opcije:\n 1 - Kreiranje dokumenta popisa clanova\n");
    printf(" 2 - Citanje popisa\n 3 - Dodavanje clanova\n 4 - Posudba filma\n 5 - Izlaz iz programa\n");
    do {
        printf("\nUpisite broj opcije koju zelite odabrati: ");
        scanf("%d", &n);
        switch (n) {
        case(1):
            mtxt();
            mpos();
            pfop = 1;
            printf("Datoteka stvorena/otvorena!\n");
            break;
        case (2):
            rtxt();
            pread();
            break;
        case (3):
            atxt();
            printf("Clan uspjesno dodan!\n");
            break;
        case (4):
            pfilm();
            break;
        case (5):
            if (pfop == 1) {
                fclose(pf);
                fclose(pf1);
            }
            exit(EXIT_SUCCESS);
        }
    } while (n != 5);
}

int main() {
    menu();
}


LV9

//9ZAD 1
#include <stdio.h>

FILE *pf;
int c=0;

void mpyr(int h){
    int i;
    c++;
    int s=h-c;
    int p=2*c-1;
    for(i=0;i<s+1;i++)
        fprintf(pf," ");
    for(i=0;i<p;i++)
        fprintf(pf,"*");
    fprintf(pf,"\n");
    if(c<h)
        mpyr(h);
}

int main(){
    if((pf=fopen("piramida.txt","w"))==NULL)
        return 1;
    int h;
    do{
        scanf("%d",&h);
    }while(h<0 || h>30);
    mpyr(h);
    fclose(pf);
    return 0;
}

//9ZAD 2
#include <stdio.h>

FILE*pf;

int digitsum(int n){
    return (n!=0) ? (n%10+digitsum(n/10)):0;
}

int main(){
    if((pf=fopen("suma.txt","w"))==NULL)
        return 1;
    int br;
    scanf("%d",&br);
    fprintf(pf,"%d",digitsum(br));
    return 0;
}


LV 10

//10ZAD 1
//program.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myheader.h"

int main(){
    DOT *d;
    TRIA *t;
    int i,n,m,a,b,c;
    if((pf=fopen("model.txt","r"))==NULL)
        return 1;
    fscanf(pf,"%d\n",&n);
    fscanf(pf,"%d\n",&m);
    d=(DOT*)malloc(n*sizeof(DOT));
    if(d==NULL)
        return 1;
    t=(TRIA*)malloc(m*sizeof(TRIA));
    if(t==NULL)
        return 1;
    for(i=0;i<n;i++)
         fscanf(pf,"%f%f%f\n", &d[i].x, &d[i].y, &d[i].z);
    for(i=0;i<m;i++){
        fscanf(pf,"%d%d%d\n", &a, &b, &c);
        t[i].d1=&d[a];
        t[i].d2=&d[b];
        t[i].d3=&d[c];
    }
    fclose(pf);
    float maxcf=cf(&t[0]);
    for(i=0;i<m;i++)
        if(maxcf<cf(&t[i]))
            maxcf=cf(&t[i]);
    free(t);
    free(d);
    printf("REZULTATI:\n");
    printf("%.2f", maxcf);
    return 0;
}

//myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

FILE *pf;

typedef struct dot {
    float x;
    float y;
    float z;
} DOT;
typedef struct triangle {
    struct dot *d1;
    struct dot *d2;
    struct dot *d3;
} TRIA;

float mod(DOT*, DOT*);
float cf(TRIA*);

#endif

//functions.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myheader.h"

float mod(DOT *a, DOT *b){
    return sqrt(pow(b->x - a->x,2)+pow(b->y - a->y,2)+pow(b->z - a->z,2));
}

float cf(TRIA *t){
    return mod(t->d1,t->d2)+mod(t->d2,t->d3)+mod(t->d1,t->d3);
}

//model.txt
26
36
-0.341005 -0.309224 2.552895
0.525730 0.000000 0.850652
0.162456 0.499995 0.850654
0.276388 -0.850649 0.447220
0.688189 -0.499997 0.525736
0.162456 -0.499995 0.850654
-0.723607 -0.525725 0.447220
-0.262869 -0.809012 0.525738
-0.425323 -0.309011 0.850654
-0.723607 0.525725 0.447220
-0.850648 0.000000 0.525736
-0.425323 0.309011 0.850654
0.276388 0.850649 0.447220
-0.262869 0.809012 0.525738
0.894426 0.000000 0.447216
0.688189 0.499997 0.525736
0.951058 0.309013 0.000000
0.587786 0.809017 0.000000
0.000000 1.000000 0.000000
-0.587786 0.809017 0.000000
-0.951058 0.309013 0.000000
-0.951058 -0.309013 0.000000
-0.587786 -0.809017 0.000000
0.000000 -1.000000 0.000000
0.587786 -0.809017 0.000000
0.951058 -0.309013 0.000000
0 1 2
3 4 5
6 7 8
9 10 11
12 13 2
14 15 1
1 15 2
15 12 2
2 13 11
13 9 11
11 10 8
10 6 8
8 7 5
7 3 5
5 4 1
4 14 1
16 15 14
16 17 15
17 12 15
18 13 12
18 19 13
19 9 13
20 10 9
20 21 10
21 6 10
22 7 6
22 23 7
23 3 7
24 4 3
24 25 4
25 14 4
17 18 12
19 20 9
21 22 6
23 24 3
25 16 14

//10ZAD 2
//program.c
#include<stdio.h>
#include<stdlib.h>
#include"myheader.h"


int main(void) {
    Racun r;
    FILE *pf;
    if ((pf = fopen("racun.txt", "r")) == NULL)
        return 1;
    inputr(&r,pf);
    printf("REZULTATI:\n");
    printf("Ukupan iznos racuna: %.2f", r.ukupan_iznos);
    fclose(pf);
    return 0;
}

//myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

typedef struct artikl {
  char *naziv;
  float cijena;
  int kolicina;
} Artikl;
typedef struct racun {
  char *prodavac;
  char *kupac;
  Artikl *artikli;
  int  broj_artikala;
  float ukupan_iznos;
} Racun;

/* Ukoliko koristite dodatne funkcije mozete ih navesti nakon ovog komentara */
void inputr(Racun*, FILE*);

#endif

//functions.c
#include<stdio.h>
#include<stdlib.h>
#include "myheader.h"

void inputr(Racun *r, FILE *pf) {
    r->kupac=(char*)malloc(50*sizeof(char));
        if(r->kupac==NULL)
            exit(EXIT_FAILURE);
    r->prodavac=(char*)malloc(50*sizeof(char));
        if(r->prodavac==NULL)
            exit(EXIT_FAILURE);
    fscanf(pf,"%[^\n]\n",r->kupac);
    fscanf(pf,"%[^\n]\n",r->prodavac);
    fscanf(pf,"%d\n",&r->broj_artikala);
    r->artikli=(Artikl*)malloc(r->broj_artikala*sizeof(Artikl));
        if(r->artikli==NULL)
            exit(EXIT_FAILURE);
    for(int i=0;i<r->broj_artikala;i++){
        r->artikli[i].naziv=(char*)malloc(50*sizeof(char));
        if(r->artikli[i].naziv==NULL)
            exit(EXIT_FAILURE);
        fscanf(pf,"%[^\n]\n",r->artikli[i].naziv);
        fscanf(pf,"%f\n",&r->artikli[i].cijena);
        fscanf(pf,"%d\n",&r->artikli[i].kolicina);
        r->ukupan_iznos+=r->artikli[i].cijena*r->artikli[i].kolicina;
    }
}

//racun.txt
Petar Kupcevic
Ivan Prodavacevic
4
Pivo Osjecko 0.5l
5.99
120
Brandy Badel 1l


LV 11

//11ZAD 1
//program.c
#include <stdio.h>

int main(){
    int i, n, a[500];
    FILE *pf;
    if((pf=fopen("in1.txt","r"))==NULL)
        return 1;
    for(i=0;i<500;i++)
        fscanf(pf,"%d\n",&a[i]);
    fclose(pf);
    do{
        scanf("%d",&n);
    }while(n<0||n>1000);
    printf("REZULTATI:\n");
    for(i=0;i<500;i++)
        if(a[i]==n){
            printf("Broj %d je pronadjen nakon %d koraka",n,i+1);
            return 0;
        }
        printf("Broj %d nije pronadjen.",n);
        return 0;
}

//in1.txt
98
488
982
282
607
168
538
675
953
263
285
731
143
626
775
81
943
616
557
381
818
166
197
739
637
426
431
826
110
168
794
899
346
466
871
954
634
409
628
586
362
604
316
506
229
781
277
172
396
524
243
904
380
130
643
16
247
73
843
357
933
326
946
278
792
817
922
115
225
550
701
277
844
707
473
72
177
751
935
263
965
869
167
345
689
500
361
936
263
894
983
195
911
929
474
392
435
85
508
350
325
899
627
168
606
100
932
783
541
556
737
505
424
904
850
804
403
902
739
356
485
722
552
395
340
716
788
775
801
295
815
126
193
441
294
489
231
225
963
772
782
699
277
896
292
817
699
385
718
128
741
203
850
983
288
880
698
75
344
189
60
158
315
945
289
299
123
521
215
776
292
687
474
569
272
456
386
972
841
794
790
272
687
329
254
976
208
953
741
552
832
802
400
837
436
689
135
559
209
40
335
502
417
499
761
690
956
146
351
486
631
140
758
317
469
12
292
677
655
724
919
176
215
318
12
651
6
838
209
907
879
234
408
295
734
859
985
379
5
25
865
326
165
313
643
634
15
626
0
360
349
919
536
564
927
548
214
624
385
113
530
954
348
628
249
772
486
924
150
181
950
705
507
114
17
841
439
32
466
439
392
815
48
928
68
975
165
282
288
551
85
508
504
123
135
443
895
312
57
735
493
697
130
691
501
147
531
940
871
687
69
953
501
117
571
259
782
736
231
70
977
316
268
171
440
404
304
24
716
361
450
899
57
580
279
559
417
500
188
978
186
257
621
377
64
191
636
537
617
867
297
284
183
565
455
313
969
759
27
374
811
477
964
558
747
933
116
855
433
996
522
619
943
142
997
7
23
632
544
641
189
841
925
372
405
69
375
64
518
402
128
328
570
782
887
316
715
693
861
147
378
383
456
321
215
452
328
239
775
562
880
964
92
494
25
497
563
400
251
80
492
70
99
61
852
676
68
256
58
619
403
437
1
860
758
217
1
776
146
466
27
25
119
119
209
144
616
772
234
558
542
727
628
331
478
169
6
546
426
756
165
519
883
857
68
330
764
761
105
910
226
132
625
346
251
834
490
557
295
415
805
528
832
122
859
309
983
556
546
408
311
401
617
193
257
686
523
21
446
318

//11ZAD 2
//program.c
#include<stdio.h>
#define n 500
#define m 5

void swap (int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int a[], int low, int high) {
    int i = low, j = high;
    int s = a[(low + high) / 2];
    while (i <= j) {
        while (a[i] < s) {
            i++;
        }
        while (a[j] > s){
            j--;
        }
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    } 
    if (low < j)
    quickSort(a, low, j);
    if (i < high)
    quickSort(a, i, high);
}

int main(){
    int a[n],i,j,p[m],brks=0,brkb=0,uss=0,usb=0,st;
    FILE *pf;
    if((pf=fopen("in1.txt","r"))==NULL)
        return 1;
    for(i=0;i<n;i++)
        fscanf(pf,"%d",&a[i]);
    fclose(pf);
    for(i=0;i<m;i++)
        do{
            scanf("%d",&p[i]);
        }while(p[i]<0 || p[i]>1000);
    printf("REZULTATI:\n");
    printf("Sekvencijalno:\n");
    for(i=0;i<m;i++){
        st=1;
        for(j=0;j<n;j++)
            if(a[j]==p[i]){
                printf("%d. broj %d je pronadjen u %d koraka.\n",i+1,p[i],j+1);
                uss++;
                brks+=j+1;
                st=0;
                break;
            }
        if(st) printf("%d. broj %d nije pronadjen.\n",i+1,p[i]);
    }
        quickSort(a,0,n-1);
        int dg, gg, s, brk;
        printf("\nBinarno:\n");
        for(i=0;i<m;i++){
            dg=0, gg=n-1,brk=0;;
            while (dg<=gg) {
                s = (dg+gg)/2;
                if (p[i] == a[s]) {
                    printf("%d. broj %d je pronadjen u %d koraka.\n",i+1,p[i],brk+1);
                    brkb+=brk+1;
                    usb++;
                    break;
                }
                else if (p[i] > a[s]) {
                    dg = s+1;
                    brk++;
                }
                else if (p[i] < a[s]) {
                    gg = s-1;
                    brk++;
                }
            }if(dg>gg) printf("%d. broj %d nije pronadjen.\n",i+1,p[i]);
        }
        if(uss==0)uss++;
        if(usb==0)usb++;
        printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f\n", (float) brks/uss);
        printf("Srednji broj koraka za binarno pretrazivanje je: %.2f.",(float) brkb/usb);
        return 0;
}

//in1.txt /isti kao u zadnjem zad


LV 12

//12ZAD 1
//main.c
// ovo je main datoteka koja sadrži pozive svih potrebnih funkcija, nju ne trebate dirati

#include <stdio.h>
#include "header.h"


int  main() {
	int n, i, x;
	
	STUDENT *headNode = NULL;
	STUDENT *targetNode = NULL;
	
	printf("Koliko studenata zelis unijeti? ");
	scanf("%d", &n);

	headNode = createSLList();                      // kreiranje povezanog popisa i umetanje prvog člana

	for (i = 0; i < n-1; i++)
	{
		headNode = insertNewNodeSLList(headNode);   // umetanje sljedećih n-1 članova
	}

	printf("Unesite ID studenta kojeg trazite\n");  // unos ID-a studenta kojeg tražimo i brišemo
	scanf("%d", &x);
	
	printf("REZULTATI:\n");
	
	traverseSLList(headNode);                       // obilazak povezanog popisa i ispis svih članova
	printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode)); // izračun prosjeka svih studenata

	targetNode = searchSLList(headNode, x);         // traženje studenta preko ID-a

	if (targetNode == NULL) {
		printf("Student s trazenim ID-em nije pronadjen!\n");   // ispis poruke ako nije pronadjen
	}
	else {                                                      // ako je pronadjen
		deleteNodeSLList(&headNode, targetNode);                // brisanje studenta
		traverseSLList(headNode);                               // ponovni obilazak povezanog popisa i ispis svih članova
		printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode)); // ponovni izračun prosjeka svih preostalih studenata
	}
	headNode = deleteWholeSLList(headNode);                     // oslobađanje memorije za cijeli povezani popis

	return 0;
}

//header.h
#include <stdio.h>

#ifndef HEAD_H
#define HEAD_H

typedef struct student {
	char *ime;
	char *prezime;
	int id;
	float prosjek;
	struct student* nextNode;
}STUDENT;

void inputNodeData(STUDENT*);
float prosjekSvih(STUDENT *);
STUDENT* createSLList(void);
void traverseSLList(STUDENT*);
STUDENT* insertNewNodeSLList(STUDENT*);
STUDENT* searchSLList(STUDENT*, int);
void deleteNodeSLList(STUDENT**, STUDENT*);
STUDENT* deleteWholeSLList(STUDENT*);

#endif

//functions.c
#include<stdio.h>
#include<stdlib.h>
#include "header.h"


void inputNodeData(STUDENT *st){
    st->ime=(char*)malloc(50*sizeof(char));
    if(st->ime==NULL)
            exit(EXIT_FAILURE);
    st->prezime=(char*)malloc(50*sizeof(char));
    if(st->prezime==NULL)
            exit(EXIT_FAILURE);
    printf("Unesite podatke studenata!\n");
        scanf("%d", &st->id);
        scanf("%s", st->ime);
        scanf("%s", st->prezime);
        scanf("%f", &st->prosjek);
}

float prosjekSvih(STUDENT *st){
    float ukp;
    int c=0;
    if (st == NULL) {
        exit(EXIT_FAILURE);
    }
    else {
        while (st) {
            c++;
            ukp+= st->prosjek;
            st = st->nextNode;
        }
    }
    return ukp/c;
}

STUDENT* createSLList(void) {
    STUDENT *headNode = (STUDENT*)malloc(1 * sizeof(STUDENT));
    if (headNode == NULL) {
        perror("Kreiranje");
        return NULL;
    }
    else {
        inputNodeData(headNode);
        headNode->nextNode = NULL;
    }
    return headNode;
}

STUDENT* insertNewNodeSLList(STUDENT* headNode) {
    STUDENT *newHeadNode = (STUDENT*)malloc(1 * sizeof(STUDENT));
    if (newHeadNode == NULL) {
        perror("Kreiranje");
        return headNode;
    }
    else {
        inputNodeData(newHeadNode);
        newHeadNode->nextNode = headNode;
    }
    return newHeadNode;
}

STUDENT* searchSLList(STUDENT* traverseNode, int criteria) {
    while (traverseNode) {
        if (traverseNode->id == criteria) {
            return traverseNode;
        }
        else {
            traverseNode = traverseNode->nextNode;
        }
    }
    printf("Student s trazenim ID-em nije pronadjen!");
    return NULL;
}

void traverseSLList(STUDENT* traverseNode) {
    if (traverseNode == NULL) {
        exit(EXIT_FAILURE);;
    }
    else {
        while (traverseNode) {
            printf("ID: %d - %s %s, prosjek: %.2f\n", traverseNode->id, traverseNode->ime, traverseNode->prezime, traverseNode->prosjek );
            traverseNode = traverseNode->nextNode;
        }
    }
}

void deleteNodeSLList(STUDENT** headNode, STUDENT* targetNode) {
    if (*headNode == targetNode) {
        *headNode = (*headNode)->nextNode;
        free(targetNode);
    }
    else {
        STUDENT* traverseNode = *headNode;
        while (traverseNode->nextNode) {
        if (traverseNode->nextNode == targetNode) {
            traverseNode->nextNode = targetNode->nextNode;
            free(targetNode->ime);
            free(targetNode->prezime);
            free(targetNode);
            break;
        }
        traverseNode = traverseNode->nextNode;
    }
}
}

STUDENT* deleteWholeSLList(STUDENT* traverseNode) {
    STUDENT* deleteNode = NULL;
    while (traverseNode) {
        deleteNode = traverseNode;
        traverseNode = traverseNode->nextNode;
        free(deleteNode->ime);
        free(deleteNode->prezime);
        free(deleteNode);
    }
    return NULL;
}


LV 13

//13ZAD 1
// 1.	Korisnik treba unijeti cjelobrojnu vrijednost u rasponu od 1 do 7, 
//pri čemu 1 predstavlja ponedjeljak, a 7 nedjelju. 
//Ispisati poruku „Vikeeeend!“ ako je unesen broj koji označava neradne dane ili
//poruku „Radis jos %d dana do vikenda.“ ako je unesen broj koji označava radne dane.
//Za dane u tjednu koristiti enumeraciju.
#include <stdio.h>
#include <stdlib.h>

enum{MON=1,TUE,WEN,THU,FRI,SUN,SAT};

int main(){
    int n;
    do{
        scanf("%d",&n);
    } while(n<1||n>7);
    printf("REZULTATI:\n");
    if (n>0 && n<6)
        printf("Radis jos %d dana do vikenda.",5-n);
    else
        printf("Vikeeeend!");
    return 0;
}

//13ZAD 2
// Implementirati makro koji racuna  indeks s u binarnom pretrazivanju (s = (dg+gg)/2).
//U glavnoj funkciji ucitati 500 brojeva iz datoteke in.txt te s tipkovnice traziti unos
//broja koji trazimo u danom polju u intervalu [1, 1000].
//Ispisati poruku „Broj nije nadjen.“ ili „Broj je nadjen.“ s obzirom na rezultat pretrazivanja.

#include <stdio.h>
#include "header.h"

#define makro(dg,gg) (dg+gg)/2
#define n 500

void swap (int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int a[], int low, int high) {
    int i = low, j = high;
    int s = a[(low + high) / 2];
    while (i <= j) {
        while (a[i] < s) {
            i++;
        }
        while (a[j] > s){
            j--;
        }
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    } 
    if (low < j)
    quickSort(a, low, j);
    if (i < high)
    quickSort(a, i, high);
}

int  main() {
	int x,s,dg=0,gg=n-1,a[n];
	FILE *pf;
    if((pf=fopen("in.txt","r"))==NULL)
        return 1;
    for(int i=0;i<n;i++)
        fscanf(pf,"%d",&a[i]);
    fclose(pf);
	do {
	    scanf("%d",&x);
	}while(x<0||x>1000);
	printf("REZULTATI:\n");
	quickSort(a,0,n-1);
	while (dg<=gg) {
    s = makro(dg,gg);
    if (x == a[s]) {
        printf("Broj je nadjen.\n");
        break;
    }
    else if (x>a[s]) 
        dg = s+1;
    else if (x<a[s]) 
        gg = s-1;
	}
if(dg>gg) printf("Broj nije nadjen.\n");
return 0;
}

//in.txt /isto kao in1.txt