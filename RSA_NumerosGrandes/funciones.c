#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>



// funciona
number multiplicar(number* N1, number* N2){
	
	number N3;
	iniciaNumero(&N3);
	int i,j,carga=0,suma;
	
	int n1 = potenciaMayor(N1);
	int n2 = potenciaMayor(N2);
	
	for(i = 0; i<=n1; i++){
			
		number N;
		iniciaNumero(&N);
			
		N = multDigito(N2,N1 -> d[i]);
		desplaza(&N,i);	
		N3 = sumar(&N,&N3);
			
		free(N.d);	
	}
	
	return N3;
}

// funciona
number multDigito(number* A, int d){
	
	number N3;
	iniciaNumero(&N3);
	
	int prod, i, carga=0;
	
	int n = potenciaMayor(A);
	
	for(i=0; i<=n+1; i++){
		
		prod = A->d[i] * d + carga;
		N3.d[i] = prod % 10;
		carga = prod / 10;
		
	}
	
	return N3;
		
}

// funciona
void iniciaNumero(number* N){
	int i;
	N -> d = (short int*) malloc(1024 * sizeof(short int));
	for(i=0; i<1024; i++) N -> d[i] = 0;
}

// funciona
int potenciaMayor(number* N){
	int i;
	for(i=1023; i>0; i--){
		if(N->d[i] != 0) return i;
	}
	return 0;
}

// funciona
number sumar(number* A, number* B){
	number N3;
	iniciaNumero(&N3);
	
	int a = potenciaMayor(A);
	int b = potenciaMayor(B);
	
	int carga=0, i, suma=0;
	
	int m = max(a,b);
	
	for(i=0; i<=m+1; i++){
		suma = A -> d[i] + B -> d[i] + carga;
		N3.d[i] = suma % 10;
		carga = suma / 10;
	}
	
	return N3;
}

// funciona
number restar(number* a, number* b){
	
	number R,A,B;
	iniciaNumero(&R);
	iniciaNumero(&A);
	iniciaNumero(&B);
	
	int i;
	for(i=0; i<1024; i++){
		A.d[i] = a->d[i];
		B.d[i] = b->d[i];
	}
	
	int D = potenciaMayor(&A);
	int aux;
	
	for(i=0; i<=D; i++){
		if(B.d[i] <= A.d[i]){
			R.d[i] = A.d[i] - B.d[i];
		}else{
			aux = i;
			i++;
			while(A.d[i] == 0){
				A.d[i] = 9;
				i++;
			}
			A.d[i] = A.d[i] - 1;
			i = aux;
			R.d[i] = 10 + A.d[i] - B.d[i];
		}
		
	}
	
	free(A.d);
	free(B.d);
	
	return R;
}


int max(int a, int b){
	if(a>b) return a;
	return b;
}

// funciona
void desplaza(number* A, int n){
	if(n==0) return;
	int i, indice = potenciaMayor(A);
	for(i=indice; i>=0; i--){
		A->d[i+n] = A->d[i];
		A->d[i] = 0;
	}
}


number modulo(number* A, number* N){
	
	number mod, q, P;
	iniciaNumero(&mod);
	iniciaNumero(&q);
	iniciaNumero(&P);
	
	q = divide(A,N);
	P = multiplicar(N,&q);
	mod = restar(A,&P);
	
	//------------------------------
	
	free(P.d);
	
	return mod;
}


number divide(number* A, number* B){
	
	number q, N;
	iniciaNumero(&q);
	iniciaNumero(&N);
	
	int DA = potenciaMayor(A);
	int DB = potenciaMayor(B);

	int i;
	for(i=0; i<=DB; i++) N.d[i] = B -> d[i];
	
	//printf(" ");
	//imprimeNumero(N);
	
	desplaza(&N, DA-DB-1);
	
	//printf(" ");
	//imprimeNumero(N);
	
	q.d[DA-DB-1] = 1; 
	
	while( esMenorOIgual(&N,A) ){
		//printf(" ");
		//imprimeNumero(B);
		N = sumar(&N,B);
		//printf(" ");
		//imprimeNumero(N);
		suma1(&q);
		//printf(" ");
		//imprimeNumero(q);
	} 
	
	resta1(&q);
	
	free(N.d);

	return q;
}

// funciona
int esMenorOIgual(number* A, number* B){
	
	int DA = potenciaMayor(A);
	int DB = potenciaMayor(B);
	
	if(DA < DB) return 1;
	if(DB < DA) return 0;
	
	int i;
	for(i=DA; i>=0; i--){
		if(A->d[i] < B->d[i]) return 1;
		if(A->d[i] > B->d[i]) return 0;
	}
	
	return 1;
}

// funciona
void suma1(number* A){
	int i=0;
	while(A->d[i] == 9){
		A->d[i] = 0;
		i++;
	}
	A->d[i] = A->d[i] + 1;
}

// funciona
void resta1(number* A){
	int i=0;
	while(A->d[i] == 0){
		A->d[i] = 9;
		i++;
	}
	A->d[i] = A->d[i] - 1;
}

void imprimeNumero(number* A){
	int i,ind=0;
	for(i=1023; i>0; i--){
		
		if(A->d[i] == 0){
			if(ind == 1){
				printf("0");
			}
		}else{
			
			printf("%d", A->d[i]);
			ind = 1;
			
		}
	
	}
	printf("%d", A->d[0]);
}


int esCero(number* A){
	int i;
	for(i=0;i<=1023;i++){
		if(A->d[i] != 0) return 0;
	}
	return 1; 
}


int esUno(number* A){
	int i;
	if(A->d[0] != 1) return 0;
	for(i=1;i<=1023;i++){
		if(A->d[i] != 0) return 0;
	}
	return 1; 
}


number toNumber(int N){
	
	number N1;
	iniciaNumero(&N1);
	
	int i;
	for(i=0; i<32; i++){
		N1.d[i] = N % 10;
		N = N / 10;
	}
	
	return N1;
}


///////////////////////////////////////////////////////////


number mcd(number* a, number* b){
	
    if (esCero(a))
        return *b;
        
    number AB,A,B;
	iniciaNumero(&AB);
	iniciaNumero(&A);
	iniciaNumero(&B);
	
	int i;
	for(i=0; i<1024; i++){
		A.d[i] = a->d[i];
		B.d[i] = b->d[i];
	}
	
	AB = divide(&B,&A);  
	
	number r,M;
	iniciaNumero(&r);
	iniciaNumero(&M);
	M = multiplicar(&AB,&A);
    r = restar(&B , &M);
    
    //printf(" ");
    //imprimeNumero(&B);
    
    free(B.d);
    //---------------
    
    M = mcd(&r, &A);
    
    free(A.d);
    free(r.d);
    
    return M;
}



number buscaCoprimo(number* N){
	
	number c, aux, P, r;
	iniciaNumero(&c);
	iniciaNumero(&aux);
	iniciaNumero(&r);
	iniciaNumero(&P);
	
	aux = toNumber(rand());
	r = toNumber(RAND_MAX);
	
	P = multiplicar(N,&aux); 
	
	c = divide(&P, &r);
	
	//printf(" ");
	//imprimeNumero(&c);
	
	number f;
	iniciaNumero(&f);
	f = mcd(&c,N);
	
	//printf(" ");
	//imprimeNumero(&M);
	
	//printf(" ");
	//imprimeNumero(&c);
	
	
	while(!esUno(&f)){
		suma1(&c);
		
		
		
		//printf(". ");
		//imprimeNumero(&c);
		
		f = mcd(&c,N);
		
		//printf(" ");
		//imprimeNumero(&M);
		
	}
		
	free(aux.d);
	free(P.d);
	free(r.d);
	
	return c;	
}




number buscaInverso(number* c, number* N){
	
	number r, P, aux;
	iniciaNumero(&r);
	iniciaNumero(&P);
	iniciaNumero(&aux);
	
	aux.d[0] = 1;
	r=*c;
	
	int i=1;
	
	while(!esUno(&r)){
		aux = r;
		P = multiplicar(&r,c);
		
		//printf(" ");
		//imprimeNumero(&P);
		
		r = modulo(&P,N);
		i++;
		
		//printf(" ");
		//imprimeNumero(&r);
		
	}
	
	free(r.d);
	free(P.d);
	
	return aux;
	
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

number encriptar(number* m, number* c, number* N){
	
	number res, res2, q, I;
	iniciaNumero(&I);
	iniciaNumero(&res);
	iniciaNumero(&res2);
	iniciaNumero(&q);
	
	res = *m;
	
	//printf(" ");
	//imprimeNumero(&res);
	
	I.d[0] = 2;
	
	res2 = res;
	
	while(esMenorOIgual(&I,c)){
		res = multiplicar(&res2,m);
		//printf(" ");
		//imprimeNumero(&res);
		res2 = modulo(&res,N);
		//printf(" ");
		//imprimeNumero(&res2);
		suma1(&I);
	}
	
	free(q.d);
	free(I.d);
	free(res.d);
	
	return res2;
}


number desencriptar(number* k, number* d, number* f){
	
	number res, res2, q, I;
	iniciaNumero(&I);
	iniciaNumero(&res);
	iniciaNumero(&res2);
	iniciaNumero(&q);
	
	res = *k;
	
	I.d[0] = 2;
	
	res2 = res;
	
	while(esMenorOIgual(&I,d)){
		res = multiplicar(&res2,k);
		res2 = modulo(&res,f);
		suma1(&I);
	}
	
	free(q.d);
	free(I.d);
	free(res.d);
	
	return res2;

}

