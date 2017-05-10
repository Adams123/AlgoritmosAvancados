#ifndef _ARQUIVOS_H_
#define _ARQUIVOS_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>

	#define INF 1.0/0.0
	
	/*!	Le todos os dados de um arquivo, e monta um vetor contendo as classes e uma matriz contendo os dados
	*	\param FILE* ponteiro para o arquivo
	*	\param int* Ponteiro para um vetor de classes, em que cada linha representa a classe da respectiva linha no arquivo
	*	\return Retorna uma matriz contendo todos os dados do arquivo.
	*/
	void lerArquivo(FILE *, int*, double**);

#endif