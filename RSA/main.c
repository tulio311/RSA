#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	long long p = 67, q = 91;
	printf("p = %d, q = %d\n", p, q);
	
	long long N = p * q;
	printf("N = %d\n", N);
	
	long long m = 678;
	printf("m = %d\n", m);
	
	long long f = (p-1) * (q-1);
	printf("f = %d\n\n", f);
	
	long long c = buscaCoprimo(f);
	
	printf("c: %lli \n", c);
	
	long long d = buscaInverso(c,f); 
	
	printf("d: %lli \n\n", d);
	
	long long k = encriptar(m,c,N);
	
	printf("k: %lli \n", k);
	
	long long M = desencriptar(k,d,N);
	
	printf("m: %lli ", M);
	
	return 0;
}
