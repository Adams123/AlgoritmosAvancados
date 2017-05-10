#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Cores{
    Branco=-1,
    Azul=0,
    Amarelo=1,
    Verde=2,
    Vermelho=3
};

typedef struct bloco {
        int valor; //valor do no referente ao vertice correspondente no grafo
        char estado[50]; //nome do estado representado
        enum Cores cor; //cor do vertice atual
        struct bloco *prox; //ponteiro para o proximo vertice
} no;

typedef struct {
        no *inicio, *fim; //ponteiros para inicio e fim da lista de vertices
} Lista;

void cria(Lista*);
void finaliza(Lista*);
void inserir(Lista*,int, char*);
int tamanho(Lista*);
int esta_na_lista(Lista*,int);
void imprimir(Lista*);
void reseta(Lista*);
const char* getColor(enum Cores);


#endif
