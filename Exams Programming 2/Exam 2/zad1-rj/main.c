#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main()
{
    int n,m;
    MATRICA *M, *B;
    scanf("%d",&n);
    scanf("%d",&m);
    
    M=alokacija(n,m);
    unos_elemenata(M);
    print(M);
    printf("REZULTATI:\n");
    B=alokacija(n,m);
    najveci(M,B);
    print(B);
    M=Oslobadjanje(M);
    B=Oslobadjanje(B);
    return 0;
}
