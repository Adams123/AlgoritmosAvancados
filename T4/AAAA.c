#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Vertice int
#define INF 1.0/0.0
#define MAX 788

typedef struct Aresta{
  int x; //vertice inicial
  int y; //vertice final
  double peso;
}aresta;

int id[MAX];
int sz[MAX];
double MST[MAX][MAX];
aresta pesosArestas[MAX*MAX]; //grafo completo, temos MAX*MAX arestas
aresta pesosMST[MAX*MAX]; //pesos arestas MST

typedef struct coordenadas{

 double x;
 double y;

}Coordenadas;

Coordenadas coord[MAX];

struct digrafo {
 int V; 
 int A; 
 double **adj; 
};

typedef struct digrafo *Digrafo;


double distancia(int i, int j)
{
  return (sqrt(pow(coord[j].y-coord[i].y,2) + pow(coord[j].x-coord[i].x,2)));
}

double **iniciaMatriz( int r, int c, double val) { 
 Vertice i, j;
 double **m = malloc( r * sizeof (double *));
 for (i = 0; i < r; i++)
  m[i] = malloc( c * sizeof (double));
for (i = 0; i < r; i++)
  for (j = 0; j < c; j++)
   m[i][j] = val;
 return m;
}


Digrafo Digrafoinicia( int V) { 
 Digrafo G = malloc( sizeof *G);
 G->V = V; 
 G->A = 0;
 G->adj = iniciaMatriz  ( V, V, 0.0);
 return G;
}

void Digrafoinserearesta( Digrafo G, Vertice v, Vertice w) 
{ 
 if (v != w && G->adj[v][w] == 0){
  if(v==w) {
    G->adj[v][w] = INF;
  }
  else
  {
    G->adj[v][w] = distancia(v,w);
    G->adj[w][v] = distancia(v,w);
  }
  G->A++;
  }
  MST[v][w] = INF;
}

void INSERE2(Digrafo G)
{
  FILE *fp = fopen("in.txt", "r");
  int i=0, j=0;
  double n;
  while(fscanf(fp,"%lf",&n) !=EOF)
  {
    G->adj[i][j]=n;
    j++;
    if(j==5)
    {
      j=0;
      i++;
    }
  }

  fclose(fp);
}

void Digrafoinserearesta2( Digrafo G, Vertice v, Vertice w) 
{ 
 if (v != w && G->adj[v][w] == 0){
  if(v==w) {
    G->adj[v][w] = INF;
  }
  else
  {
    G->adj[v][w] = distancia(v,w);
    G->adj[w][v] = distancia(v,w);
  }
  G->A++;
  }
  MST[v][w] = INF;
}


void Digraforemovearesta( Digrafo G, Vertice v, Vertice w) 
{
  if (G->adj[v][w] != INF) {
    G->adj[v][w] =  G->adj[w][v] = INF; 
    G->A--;
  }
}

void Digrafoimprime( Digrafo G) { 
 Vertice v, w; 
 for (v = 0; v < G->V; v++)
 {
  for (w = 0; w < G->V; w++)
  {
   printf("%.2lf ",G-> adj[v][w]);
  }
 printf("\n");
 }
}

int Find(int x)
{
  while(x != id[x]){
    id[x]=id[id[x]];
    x=id[x];
  }
  return x;
}
void Union(int x,int y)
{
  int i;
  x=Find(x);
  y=Find(y);
  if(x!=y){
    if(sz[x] < sz[y])
    {
      sz[y]+=sz[x];
      id[x] = y;
    }
    else
    {
      sz[x]+=sz[y];
      id[y]=x;
    }
  }
}


void MontaCoord()
{
  FILE *fp = fopen("data.txt", "r");
  int i=0;
  while((fscanf(fp,"%lf %lf", &coord[i].x,&coord[i].y))!=EOF)
    i++;
  fclose(fp);
}

void Kruskal(Digrafo G){
  int i,j,auxi,auxj;

  for(i=0;i<MAX*MAX;i++)
    {
      if(pesosArestas[i].peso != 0)
      {
        auxi=pesosArestas[i].x;
        auxj=pesosArestas[i].y;

        if(Find(auxi)!=Find(auxj))
        {
          MST[auxi][auxj]=G->adj[auxi][auxj];
          MST[auxj][auxi]=G->adj[auxj][auxi];
          
          Union(auxi,auxj);
          pesosArestas[auxi].peso=0;

          printf("Aresta (%d,%d) %lf\n", auxi, auxj, MST[auxi][auxj]);
        }
    }
  }
}

int compare(const void *a, const void *b){
  if((*(aresta*)a).peso < (*(aresta*)b).peso)
   return -1;
  else if((*(aresta*)a).peso > (*(aresta*)b).peso)
    return 1;
  else return 0;
}

int main(void){

  Digrafo G;
  int i,j, k=0;

  MontaCoord();
  G=Digrafoinicia(MAX);

  for(i=0;i<MAX;i++){
    id[i]=i;
    sz[i]=1;
  }
  

  //--------TESTE 5X5 -------------
  INSERE2(G);

  for(i=0;i<MAX;i++)
  {
    for(j=0;j<MAX;j++)
    {
      pesosArestas[k].peso=G->adj[i][j];
      pesosArestas[k].x=i;
      pesosArestas[k].y=j;
      k++;
    }
  }
  //--------TESTE 5X5 -------------

  // for(i=0;i<MAX;i++)
  //   for(j=0;j<MAX;j++){
  //     Digrafoinserearesta(G,i,j);
  //     pesosArestas[k].peso=distancia(i,j);
  //     pesosArestas[k].x=i;
  //     pesosArestas[k].y=j;
  //     k++;
  //   }
  
  qsort(pesosArestas,MAX*MAX,sizeof(aresta),compare); //ordena todas as arestas por peso

  Kruskal(G);
  k=0;
  for(i=0;i<MAX;i++)
  {
    for(j=0;j<MAX;j++)
    {
      pesosMST[k].peso=MST[i][j];
      pesosMST[k].x=i;
      pesosMST[k].y=j;
      k++;
    }
  }

  qsort(pesosMST,MAX*MAX,sizeof(aresta),compare);

  for(i=(MAX*MAX)-1;i>=0;i--)
  {
    if(pesosMST[i].peso != 0)
      break;
  }

  for(i=0;i<MAX;i++)
    id[i]=1;

  MST[pesosMST[i].x][pesosMST[i].y]=0.0;



  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      printf("%lf ", MST[i][j]);
    }
    printf("\n");
  }
  return 0;

}






void percorre(){

  for ( i = 0;   }



}







