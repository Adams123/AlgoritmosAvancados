#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo_matriz.h"


Digrafo Digrafoinicia( int V) { 
   Digrafo G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = iniciaMatriz( V, V, 0);
   return G;
}



int **iniciaMatriz( int r, int c, int val) { 
   Vertice i, j;
   int **m = malloc( r * sizeof (int *));
   for (i = 0; i < r; i++)
      m[i] = malloc( c * sizeof (int));
   for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         m[i][j] = val;
   return m;
}

void Digrafoinserearesta( Digrafo G, Vertice v, Vertice w) { 
   if (v != w && G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->A++;
   }
}

void Digraforemovearesta( Digrafo G, Vertice v, Vertice w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->A--;
   }
}



void Digrafoimprime( Digrafo G) { 
   Vertice v, w; 
   for (v = 0; v < G->V; v++) {
      printf( "%2d:", v);
      for (w = 0; w < G->V; w++)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

int Digrafocaminho( Digrafo G, Vertice s, Vertice t) { 
   Vertice v;
   chegada = t;
   printf("%d\n\n",chegada);
   int i;
   for (v = 0; v < G->V; v++)
      ind[v] = 0;
  printf("%d %d\n", caminho[conta2], tempo);
   caminhoR( G, s);
   if (ind[t] == 0) return 0;
   else return 1;
}


void caminhoR( Digrafo G, Vertice v) { 
  Vertice w;
  int k;
  if(v == chegada){
    caminho[conta2] = v;
    ind[v]  = 1;
    a=1;
   }
   /*ind[v] = 1;*/
  if(a==1)
     return;
  else
  if(tempo == 2){
    for(k=0;k<G->V;k++){
      if(G->adj[v][k]==1){
	if(pre[k]<pos[k]&&pos[k]<pre[v]&&pre[v]<pos[v] && acao != 1){
	  acao = 1;
	  tempo = 1;
	  if(ind[v]==1)
	    ind[v] = 2;
	  else 
	    ind[v] = 1;
	    caminho[conta2] = v;		
	  printf("%d %d\n", caminho[conta2], tempo);
	    conta2 ++;
	    caminhoR(G,k);
	}
	if(pre[k]<pre[v]&&pre[v]<pos[v]&&pos[v]<pos[k] && acao != 2){
	  acao = 2;
	  tempo = 1;
	  if(ind[v]==1)
	  ind[v] = 2;
	else 
	  ind[v] = 1;
	  caminho[conta2] = v;
	printf("%d %d\n", caminho[conta2], tempo);
	  conta2 ++;
	  caminhoR(G,k);
	}
      }
    }
	  
  }
  if(tempo == 3){
    for(k=v+1;k<G->V;k++){
      if(G->adj[v][k]==1){
	if(pre[k]<pos[k]&&pos[k]<pre[v]&&pre[v]<pos[v] && acao != 1){
	  acao = 1;
	  tempo = 1;
	  if(ind[v]==1)
	    ind[v] = 2;
	  else 
	    ind[v] = 1;
	  caminho[conta2] = v;
	  printf("%d %d\n", caminho[conta2], tempo);
	  conta2 ++;
	  caminhoR(G,k);
	}
      }
    }
    for(k=v+2;k<G->V;k++){
      if(G->adj[v][k]==1){
	  if(pre[v]<pre[k]&&pre[k]<pos[k]&&pos[k]<pos[v] && acao!= 3){
	    acao = 3;
	    tempo = 1;
	    if(ind[v]==1)
	    ind[v] = 2;
	    else 
	    ind[v] = 1;
	    caminho[conta2] = v;
	     printf("%d %d\n", caminho[conta2], tempo);
	    conta2 ++;
	    caminhoR(G,k);
	  }
      }
    }
  }

  if(tempo==4)
    tempo = 1;
   
    for (w = v; w < G->V; w++){
      if (G->adj[v][w] == 1 && ind[w] !=2){
	if(ind[v]==0)
	  ind[v] = 1;
	else
	  ind[v] = 2;
	if(tempo==4)
	  tempo = 1;
	else{
	  tempo ++;
	}
	caminho[conta2] = v;
	printf("%d %d %d\n", caminho[conta2], w, tempo);
	conta2 ++;
        caminhoR( G, w);
      }
   }  
}


void Digrafodfs( Digrafo G){
  Vertice v;
  conta = 0;
  for(v=0;v<G->V;v++){
    pre[v] = -1;
  }
  for(v=0;v<G->V;v++)
    if(pre[v]==-1){
      pai[v]=-1;
      
      dfsR(G,v);
    }
      
}

void dfsR(Digrafo G, Vertice v){
  
  Vertice w;
  pre[v]=conta++;
  for(w=0;w<G->V;w++)
    if(G->adj[v][w] != 0 && pre[w] == -1){
      pai[w]=v;
     
      dfsR(G,w);
    }
  pos[v]=conta++;
}

void imprimeCaminho(/*Vertice s, Vertice t*/) {
  Vertice w;
  /*int topo = 0;
  for (w = t; w != s; w = caminho[w]) 
    pilha[topo++] = w;
    printf( "%d", s);
    while (topo > 0) 
      printf( "-%d", pilha[--topo]);   
    printf( "\n");*/
  for(w=0;w<=conta2;w++){
    printf( "%d-", caminho[w]);
    
  }
}


void alocaMemoriaparapontglobais(Digrafo G){
  ind = (int*) malloc((G->V)*sizeof(int));
  pai = (Vertice*) malloc((G->V)*sizeof(Vertice));
  pilha = (Vertice*) malloc((G->V)*sizeof(Vertice));
  pre = (int*) malloc((G->V)*sizeof(int));
  pos = (int*) malloc((G->V)*sizeof(int));
  caminho = (int*) malloc((max)*sizeof(int));
  conta2 = 0;
  tempo = 0;
  a=0;

  
}