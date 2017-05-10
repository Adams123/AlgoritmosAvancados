#include "grafoo.h"

int main()
{
    int a;
    char in[10];
    fgets(in, sizeof(in), stdin);
    a=atoi(in);
//    printf("Criando com %d\n", a);
    Grafo *G = criaGrafo(a);
//    printaGrafo(G, a);
    rearranjaGrafo(G, a);
//    printaGrafo(G,a);
    int interacoes=0;
    backtracking(&interacoes, G, a, 0);
//    int i=0;
//    while(!verificaSolucao(G,a) && i<a){
//        printf("Solucao fail\n");
//        backtracking(&interacoes, G, a, i++);
//    }
    printaCores(G,a);
    printf("Interacoes: %d\n", interacoes);
    return 0;
}
