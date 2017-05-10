#include"grafoo.h"

int debug = 0;

void rearranjaGrafo(Grafo *G, int tam)
{
    int i=0;
    for(i=0; i<tam; i++)
    {
        rearranja(G,G[i].L, tam);
    }
}

void rearranja(Grafo *G, Lista *L, int tam)
{
    no *p;
    p=L->inicio;
    while (p!=NULL)
    {
        p->valor=PosGrafo(G,p->estado, tam);
        p=p->prox;
    }
}
int PosGrafo(Grafo *G, char *nome, int tam)
{
    int i=0;
    while(strcmp(G[i].estado, nome)!=0)
        i++;
    return i;

}
void resetaGrafo(Grafo *G, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        G[i].cor=Branco;
        reseta(G[i].L);
        printf("\n");
    }
}

int backtracking(int *interacoes, Grafo *G, int tam, int start)
{
    int heuristica1 = 1; //verificacao adiante
    int heuristica2 = 1; //MVR
//    int heuristica3 = 0;
/* Observacao:
a heuristica 3, ao compilar pelo terminal, da segmentation fault, simplesmente ao declararmos a flag. Como não foi possivel resolver esse problema de forma alguma,
ela nao foi testada a fundo.
*/

    enum Cores corAux;
    if(start!=tam) //enquanto nao chegar ao fim
    {
        for(corAux=0; corAux<=3; corAux++) //garante que vai verificar todas as cores possiveis
        {
            if(heuristica2)
            {
                int menor=5, aux, cor;
                if((aux=conflitos(G,G[start].L,corAux))!=-1) //caso algum vertice nao fique sem possibilidades de pintar
                {
                    if(menor>aux)
                    {
                        menor=aux;
                        cor=corAux;
                    }
                }

                if(!verificaConsist(G,G[start].L))
                {
                    G[start].cores[cor]=1;
                    goto end;
                }
            }
            if(podePintar(G,G[start].L,corAux))
            {

                G[start].cor=corAux;
                (*interacoes)++;
                if(heuristica1)
                {
                    G[start].cores[corAux]=1;
                    marcaAdjacentes(G,G[start].L,corAux);
                    if(!verificaConsist(G,G[start].L))
                    {
                        G[start].cores[corAux]=1;
                        goto end;
                    }
                }

//                if(heuristica3)
//                {
//                    if(backtracking(interacoes,G,tam,escolheVertice(G,tam)))
//                        return 1;
//                }
//                if(backtracking(interacoes,G,tam,start+1) && !heuristica3)
                if(backtracking(interacoes,G,tam,start+1)) //comentar esta linha caso heuristica 3 seja ativa
                    return 1;
            }
end:
            ;
        }
        G[start].cor=-1;
        if(heuristica1)
        {
            for(corAux=0; corAux<=3; corAux++)
            {
                desmarcaAdjacentes(G,G[start].L,corAux);
                G[start].cores[corAux]=0;
            }
        }
        return 0;
    }
    else return 1;
}

int escolheVertice(Grafo *G, int tam)
{
    int i=0, vertice=0, maior=-1;

    while(i<tam)
    {
        if(G[i].cor==Branco)
        {
            if(tamanho(G[i].L)>maior)
            {
                maior=tamanho(G[i].L);
                vertice=i;
            }
        }
        i++;
    }
    return vertice;
}

int conflitos(Grafo *G, Lista *L, enum Cores cor)
{
    int i, cont, total=0;
    no *p;
    p=L->inicio;
    while(p!=NULL)
    {
        G[p->valor].cores[cor]=1;
        cont=0;
        for(i=0; i<=3; i++)
        {
            if(G[p->valor].cores[i]==1)
                cont++;
        }
        total+=cont;
        if(cont==4) return -1; //algum vertice fica sem opcoes
        G[p->valor].cores[cor]=0;
        p=p->prox;
    }
    return total;
}


void marcaAdjacentes(Grafo *G, Lista *L, enum Cores corUsada)
{
    no *p;
    p=L->inicio;
    while(p!=NULL)
    {
        G[p->valor].cores[corUsada]=1;
        p=p->prox;
    }
}
void desmarcaAdjacentes(Grafo *G, Lista *L, enum Cores corUsada)
{
    no *p;
    p=L->inicio;
    while(p!=NULL)
    {
        G[p->valor].cores[corUsada]=0;
        p=p->prox;
    }
}

int verificaConsist(Grafo *G, Lista *L)
{
    no *p;
    p=L->inicio;
    int cont, i;
    while(p!=NULL)
    {
        cont=0;
        for(i=0; i<=3; i++)
            if(G[p->valor].cores[i]==1) cont++;
        if(cont==4) return 0;
        p=p->prox;
    }
    return 1;
}

int podePintar(Grafo *G, Lista *L, enum Cores corUsada)
{
    no *p;
    p = L->inicio;
    while(p!=NULL)
    {
        if(G[p->valor].cor == corUsada) return 0;
        p=p->prox;
    }
    return 1;
}

const char* printaCor(int cor)
{
    switch(cor)
    {
    case -1:
        return "branco";
        break;
    case 0:
        return "azul";
        break;
    case 1:
        return "amarelo";
        break;
    case 2:
        return "verde";
        break;
    case 3:
        return "vermelho";
        break;
    default:
        return "branco";
        break;
    }

}

Grafo* criaGrafo(int tam)   //função que cria o grafo!
{
    Grafo *G;
    G = (Grafo*)malloc(sizeof(Grafo)*tam);

//    printf("Criando lista de tamanho %d\n", tam);
    int i=0, j=0;
    char str[200];
    const char s[] = ".:,";
    char *vertice, *arestas;
    arestas=malloc(sizeof(char)*50);
    while(i<tam)
    {
//        printf("Origem: destinos.\n");
        fgets(str, sizeof(str), stdin);
//        printf("String lida: \n-----\n %s \n-----\n", str);
        vertice = strtok(str, s);
        arestas = strtok(NULL, s);
        G[i].L = (Lista*)malloc(sizeof(Lista));
        strcpy(G[i].estado, vertice);
        G[i].cor=Branco;
        cria(G[i].L);
        for(j=0; j<3; j++)
            G[i].cores[j]=0;
        j=0;
        while(strcmp(arestas,"\n")!=0)
        {
            adicionaAresta(G,i,j, arestas);
            j++;
            arestas = strtok(NULL, s);
        }
        i++;
        j=0;
    }
    return G;
}

void adicionaAresta(Grafo *G, int first, int second, char *aresta)   //função que adiciona a aresta ao grafo valorado!(caso quiser fazer um grafo não valorado(não é um digrafo) é só você colocar embaixo do inserir)
{
    aresta++; //ignora o espaco inicial
    inserir(G[first].L,second, aresta);

}

void printaGrafo(Grafo *G, int tam)   //printa o grafo existente a partir das suas listas de adjacencia
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("Vertice %d (%s): ",i, G[i].estado);
        imprimir(G[i].L);
        printf("\n");
    }
}

void printaCores(Grafo *G, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
//        printf("Vertice %d (%s): ",i, G[i].estado);
        printf("%s: ",G[i].estado);
        switch(G[i].cor)
        {
        case Azul:
            printf("Azul.\n");
            break;
        case Amarelo:
            printf("Amarelo.\n");
            break;
        case Verde:
            printf("Verde.\n");
            break;
        case Vermelho:
            printf("Vermelho.\n");
            break;
        case Branco:
            printf("Branco.\n");
            break;
        }
    }
}
