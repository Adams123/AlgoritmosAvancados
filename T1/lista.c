#include "lista.h"

const char* getColor(enum Cores cor)
{
    switch(cor)
    {
    case 0: return "Azul"; break;
    case 1: return "Amarelo"; break;
    case 2: return "Verde"; break;
    case 3: return "Vermelho"; break;
    default: return "Branco"; break;
    }
}

void cria(Lista *L)  //função que seta os poteiros de um nó(criação da lista)
{
    L->inicio=NULL;
    L->fim=NULL;
}

void finaliza(Lista *L)  //finaliza a lista
{
    no *p;
    p=L->inicio;
    while (p!=NULL)
    {
        L->inicio=L->inicio->prox;
        free(p);
        p=L->inicio;
    }
    L->fim=NULL;
}

void reseta(Lista *L)  //imprimi a lista de adjacência
{
    no *p;

    p=L->inicio;
    while (p!=NULL)
    {
        p->cor=Branco;
        p=p->prox;
    }
}
void inserir(Lista *L, int x, char *aresta)  //o insere ordenado
{
    no *p;
    no *aux;
    no *anterior;

    anterior = L->inicio;
    aux = L->inicio;
    p=(no*) malloc(sizeof(no));
    p->valor = x;
    p->cor=Branco;
    strcpy(p->estado, aresta);
    p->prox=NULL;
    if (L->inicio==NULL)
    {
        L->inicio=p;
        L->fim = p;
    }
    else
    {
        while(aux != NULL && aux->valor < p->valor)
        {
            anterior = aux;
            aux = aux->prox;
        }
        if(L->inicio == anterior && anterior->valor > p->valor)
        {
            p->prox = anterior;
            L->inicio = p;
        }
        else
        {
            if(aux == NULL && L->inicio != anterior)
            {
                p->prox = anterior->prox;
                anterior->prox = p;
                L->fim = p;
            }
            else
            {
                p->prox = anterior->prox;
                anterior->prox = p;
            }
        }
    }
}


int tamanho(Lista *L)  //retorna o tamanho da lista
{
    no *p;
    int contador=0;

    p=L->inicio;
    while (p!=NULL)
    {
        contador++;
        p=p->prox;
    }
    return(contador);
}



int esta_na_lista(Lista *L, int x)  //procura se o elemento está na lista de adjacência
{
    no *p;

    p=L->inicio;
    while ((p!=NULL) && (p->valor!=x))
    {
        p=p->prox;
    }

    if (p!=NULL) return 1;
    else return 0;
}



void imprimir(Lista *L)  //imprimi a lista de adjacência
{
    no *p;

    p=L->inicio;
    while (p!=NULL)
    {
        printf(" %s (%d),",p->estado, p->valor);
        p=p->prox;
    }
}
