#ifndef FUNCIONES_H
#define FUNCIONES_H 

typedef struct Number {
	short int* d;
} number;

void asignaNumero(number* N, char* str);

number multiplicar(number* N1, number* N2);
void iniciaNumero(number* N);
void imprimeNumero(number* A);
int potenciaMayor(number* N);
void desplaza(number* A, int n);
number sumar(number* A, number* B);
number restar(number* a, number* b);
number multDigito(number* A, int d);
number modulo(number* A, number* N);
int max(int a, int b);
void suma1(number* A);
void resta1(number* A);
int esCero(number* A);
int esUno(number* A);
number toNumber(int N);
int esMenorOIgual(number* A, number* B);
number divide(number* A, number* B);

number mcd(number* a, number* b);
number buscaCoprimo(number* N);
number buscaInverso(number* c, number* N);
number encriptar(number* m, number* c, number* N);
number desencriptar(number* k, number* d, number* f);

#endif

