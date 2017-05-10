#ifndef _MATRIZES_H_
#define _MATRIZES_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>

	struct matriz 
	/*Matriz representada como: [a,b]
								[c,d]
	*/
	{
		long long a;
		long long b;
		long long c;
		long long d;
	};
	typedef struct matriz Matriz;

	/*! Calcula o valor da matriz 'x^n' 
	*	/param Matriz x Matriz a ser calculada
	*	/param long long n Valor da potencia
	*	/return Retorna a matriz resultante
	*/
	Matriz Mpower(Matriz x, long long n);
	/*!	Multiplica duas matrizes e retorna a matriz resultante
	*/
	Matriz multiplicaMatriz(Matriz a, Matriz b);
	/*! Calcula o termo 'n' da sequencia de fibonacci
	*/
	void fibo(long long n);

#endif