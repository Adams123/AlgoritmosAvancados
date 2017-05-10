#ifndef _DTW_H_
#define _DTW_H_

	#include "Arquivos.h"
	
	/*! Calcula o DTW usando os dois arquivos fornecidos: treino.txt e teste.txt
	*/
	void DTW();
	/*! Realiza o calculo DTW de duas series e retorna o seu valor
	*	\param double* ponteiro para o primeiro vetor
	*	\param double* ponteiro para o segundo vetor
	*	\param int tamanho do primeiro vetor
	*	\param int tamanho do segundo vetor
	*	\return Retorna o valor DTW dos dois vetores
	*/
	double DTWDistance(double *, double *, int, int);

	/*!	Calcula o modulo de dois numeros, usando (A-B)²
	*	\param double Numero A
	*	\param double Numero B
	*	\return Retorna o resultado
	*/
	double modulo(double,double);
	/*!	Retorna o minimo entre 3 valores
	*	\param double Numero A
	*	\param double Numero B
	*	\param double Numero C
	*	\return Retorna o valor do menor numero
	*/
	double minimum(double , double , double );
#endif