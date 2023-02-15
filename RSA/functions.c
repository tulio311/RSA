#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

long long mcd(long long a, long long b){
    if (a == 0)
        return b;
    long long q = b / a;    
    long long r = b - q*a;
    return mcd(r, a);
}



long long buscaCoprimo(long long N){
	
	double aleat = ((double) rand()) / RAND_MAX;
	long long c =  aleat * N;
	
	while(mcd(c,N) != (long long) 1){
		c++;
	}
	
	return c;	
}




long long buscaInverso(long long c, long long N){
	
	long long r=c, i=1, q, P, aux;
	while(r != 1){
		aux = r;
		P = r*c;
		q = P / N;
		r = P - N*q;
		i++;
	}
	return aux;
	
}


long long longMod(long long a, long long b){
	long long q,r;
	q = a / b;
	r = a - q*b;
	return r;
}


/*
long long buscaInverso(long long c, long long N){
	
	int r1 = N, r2 = c, aux;
	
	while(r2 != 1){
		
		aux = r2;
		r2 = r1 % r2;
		ri = aux;
		
	}
	
	return 
	
} 
*/

long long encriptar(long long m, long long c, long long N){
	long long i, res = m, q;
	for(i=2; i<=c; i++){
		res = res * m;
		res = longMod(res,N);
	}
	
	return res;
}


long long desencriptar(long long k, long long d, long long f){
	
	/*long long aux, q, r;
	q = k / f;
	r = k - 
	*/
	
	long long res = k, i, q;
	for(i=2; i<=d; i++){
		res = res * k;
		q = res / f;
		res = res - q*f;
	}
	
	return res;

}
