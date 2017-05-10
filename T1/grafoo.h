#ifndef _GRAFOO_H_
#define _GRAFOO_H_

#include "lista.h"

typedef struct grafo{
   char estado[50]; //nome do estado representado no vertice
   enum Cores cor; //cor do estado representado no vertice
   Lista *L; //ponteiro para lista de adjacencia
   int cores[4]; //vetor contendo as possiveis cores, usados para verificacao adiante
}Grafo;
/*! Esta funcao retorna 1 caso o vertice possa ser pintado com a cor desejada e 0 caso contrario
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param Lista* - Ponteiro para a lista de adjacencia do vértice a ser usado
*   \param enum Cores - Cor a ser verificada
*   \return Retorna 1 caso possa pintar, 0 caso contrario
*
*/
int podePintar(Grafo*, Lista*, enum Cores );
/*!Esta funcao verifica a consistencia de um vertice, ou seja, se ainda ha alguma cor disponivel para ser usada no vertice
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param Lista* - Ponteiro para a lista de adjacencia do vértice a ser usado
*   \return 1 Caso seja consistente, 0 caso contrario
*/
int verificaConsist(Grafo*, Lista*);
/*!Esta funcao libera a cor de todos os adjacentes a um vertice no grafo
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param Lista* - Ponteiro para a lista de adjacencia do vértice a ser usado
*   \param enum Cores - Cor a ser liberada
*/
void desmarcaAdjacentes(Grafo*, Lista*, enum Cores );
/*! Esta funcao retorna a quantidade de conflitos envolvidos ao pintar um vertice de uma cor
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param Lista* - Ponteiro para a lista de adjacencia do vértice a ser usado
*   \param enum Cores - Cor a ser verificada
*   \return Numero de conflitos gerados. Caso algum vertice adjacente fique indisponviel, retorna -1;
*/
int conflitos(Grafo*, Lista*, enum Cores);
/*!Esta funcao pinta, dada uma cor, todos os adjacentes a um vertice no grafo
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param Lista* - Ponteiro para a lista de adjacencia do vértice a ser usado
*   \param enum Cores - Cor a ser pintada
*/
void marcaAdjacentes(Grafo*, Lista*, enum Cores );
/*!Esta funcao escolhe o vertice que mais restringe as escolhas do grafo. Utilizada na heuristica grau
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param int - tamanho do grafo
*/
int escolheVertice(Grafo*, int );

/*! Cria um grafo. É necessário digitar os vertices e ligacoes no formato "Vertice: Ligacao1, Ligacao2, ..., LigacaoN."
*   \param int - Tamanho do grafo a ser criado (quantidade de vertices)
*   \return - retorna o grafo
*/
Grafo* criaGrafo(int);
/*! Adiciona uma aresta entre dois vertices.
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param int - Vertice de origem
*   \param int - Vertice de destino
*   \param char* - Nome do vértice de destino (necessario estar no grafo)
*/
void adicionaAresta(Grafo*,int,int, char*);
/*! Imprime o grafo, com os vertices ordenados e seus vertices adjacentes
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param int - Tamanho do grafo
*/
void printaGrafo(Grafo*,int);
/*! Colore o grafo inteiro de branco
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param int - Tamanho do grafo
*/
void resetaGrafo(Grafo*, int);
/*! Realiza o backtracking no grafo. Sempre comeca pelo vertice 0.
*   \param int* - quantidade de interacoes do programa
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param int - Tamanho do grafo
*   \param int - vertice inicial do backtrack
*   \return 0 Caso falhou, 1 Caso sucesso
*/
int backtracking(int *interacoes, Grafo*, int, int);
/*! Dado um nome de vertice, retorna sua posicao de insercao
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param char* - Nome do vertice a ser procurado
*   \param int - Tamanho do grafo
*   \return Retorna posicao do vertice no grafo
*/
int PosGrafo(Grafo*, char*, int);
/*! Seta os valores dos vertices de uma lista de adjacencia para os valores da ordem de insercao
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param Lista* - Ponteiro para a lista de adjacencia a ser ordenada
*   \param int - Tamanho do grafo
*/
void rearranja(Grafo*, Lista*, int);
/*! Seta os valores dos vertices de todas as listas de adjacencia do grafo para os valores da ordem de insercao
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param int - Tamanho do grafo
*/
void rearranjaGrafo(Grafo*, int);
/*! Imprime as cores atuais de todos os vertices do grafo
*   \param Grafo* - Ponteiro para um grafo previamente criado.
*   \param int - Tamanho do grafo
*/
void printaCores(Grafo*, int);
/*!Dada uma cor, retorna seu nome.
*/
const char* printaCor(int cor);
#endif
