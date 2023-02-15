#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	
	srand(time(NULL));
	
	/*
	
	number a,b,I;
	iniciaNumero(&a);
	iniciaNumero(&b);
	iniciaNumero(&I);
	
	a.d[0] = 7;
	a.d[1] = 4;
	a.d[2] = 4;
	
	b.d[0] = 8;
	b.d[1] = 2;
	b.d[2] = 9;
	
	I = buscaInverso(&a,&b);
	
	imprimeNumero(&I);
	
	*/
	
	number p, q;
	iniciaNumero(&p);
	iniciaNumero(&q);

	
	p.d[0] = 7;
	p.d[1] = 1;
	
	
	q.d[0] = 3;
	q.d[1] = 2;
	
	
	printf("p = ");
	imprimeNumero(&p);
	printf("\nq = ");
	imprimeNumero(&q);
	
	
	number N;
	N = multiplicar(&p,&q);
	printf("\nN = ");
	imprimeNumero(&N);
	
	
	/*
	number N;
	int n;
	iniciaNumero(&N);
	N = toNumber(121072240);
	
	//printf("n: %d", n);
	imprimeNumero(N);
	*/
	
	number m;
	iniciaNumero(&m);
	
	m.d[0] = 8;
	m.d[1] = 3;
	
	printf("\nm = ");
	imprimeNumero(&m);
	
	resta1(&q);
	resta1(&p);
	number f;
	iniciaNumero(&f);
	f = multiplicar(&p, &q);
	
	printf("\nf: ");
	imprimeNumero(&f);
	
	
	number c;
	iniciaNumero(&c);
	c = buscaCoprimo(&f);
	
	printf("\nc: ");
	imprimeNumero(&c);
	
	number d;
	iniciaNumero(&d);
	d = buscaInverso(&c,&f); 
	
	printf("\nd: ");
	imprimeNumero(&d);


	number k;
	iniciaNumero(&k);
	k = encriptar(&m,&c,&N);
	
	printf("\nk: ");
	imprimeNumero(&k);
	
	number M;
	iniciaNumero(&M);
	M = desencriptar(&k,&d,&N);
	
	printf("\nM: ");
	imprimeNumero(&M);

	
	return 0;
}
