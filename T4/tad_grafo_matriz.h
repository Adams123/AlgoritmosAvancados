#define Vertice int 
#define max 100
/*static*/ int *ind;
/*static*/ int *pai, *pilha, *caminho;
/*static*/ int conta, acao, conta2, *pre,*pos;
int tempo;
int chegada;
int a;



struct digrafo {
   int V; 
   int A; 
   int **adj; 
};


typedef struct digrafo *Digrafo;


Digrafo Digrafoinicia( int V);
int **iniciaMatriz( int r, int c, int val);
void Digrafoinserearesta( Digrafo G, Vertice v, Vertice w);
void Digraforemovearesta( Digrafo G, Vertice v, Vertice w);
void Digrafoimprime( Digrafo G);
int Digrafocaminho( Digrafo G, Vertice s, Vertice t);
void caminhoR( Digrafo G, Vertice v);
void Digrafodfs( Digrafo G);
void dfsR(Digrafo G, Vertice v);
void imprimeCaminho( /*Vertice s, Vertice t*/);

void alocaMemoriaparapontglobais(Digrafo G);