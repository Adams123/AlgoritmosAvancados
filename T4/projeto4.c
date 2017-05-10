#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5
#define INF 1.0/0.0

#define BRANCO 1
#define CINZA 2
#define PRETO 3





int i,j,k,a,b,u,v,n,ne=0;


int id[MAX],sz[MAX];


int cor[MAX];

double min,mincost=0,cost[MAX][MAX], custo[MAX][MAX];
int parent[MAX];
int find(int);
int uni(int,int);

typedef struct coordenadas{

 double x;
 double y;

}Coordenadas;

Coordenadas coord[MAX];

double distancia(int i, int j)
{
  return (sqrt(pow(coord[j].y-coord[i].y,2) + pow(coord[j].x-coord[i].x,2)));
}

void Inserearesta(int v, int w) 
{ 
  if(v==w) {
    cost[v][w] = INF;
  }
  else
  {
    cost[v][w] = distancia(v,w);
    cost[w][v] = distancia(v,w);
  }
}
void Inserearesta2() 
{ 
  int i=0,j=0, n=0;
  FILE *fp = fopen("in.txt", "r");
  while(fscanf(fp,"%d",&n) != EOF)
  {
    if(n==0)
      cost[i][j]=INF;
    else
      cost[i][j]=n;
    j++;
    if(j==5)
    {
      i++;  
      j=0;
    }
  }
  fclose(fp);
}

void MontaCoord()
{
  FILE *fp = fopen("in.txt", "r");
  int i=0;
  while((fscanf(fp,"%lf %lf", &coord[i].x,&coord[i].y))!=EOF)
    i++;
  fclose(fp);
}


void main()
{

  for(i=0;i<MAX;i++){
      sz[i] = 1;
      id[i] = i;
  }
  MontaCoord();
  printf("\n\n\tImplementation of Kruskal's algorithm\n\n");
  Inserearesta2();
  // for(i=0;i<MAX;i++)
  // {
  //   for(j=0;j<MAX;j++)
  //   {
  //     Inserearesta(i,j);
  //   }
  // }

printf("\n");
  printf("Matriz:\n");
  for(i=0;i<MAX;i++)
  {
    for(j=0;j<MAX;j++)
    {
      printf("%.2lf ",cost[i][j]);
    }
    printf("\n");
  }
getchar();
  // printf("Parent init:\n");
  // for(i=0;i<n;i++){printf("%d ", parent[i]);}

  printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
  while(ne<MAX)
  {
    for(i=0,min=INF;i<MAX;i++)
    {
      for(j=0;j<MAX;j++)
      {
        if(cost[i][j]<min)
        {
          min=cost[i][j];
          a=u=i;
          b=v=j;
        }
      }
    }

    
    /*if((cor[u]!=PRETO)||(cor[v]!=PRETO)){*/
      // printf("\nFind %d: ", u);
      u=find(u);
      // printf("%d. Find %d: ", u,v);
      v=find(v);
      // printf("%d.\n", v);
      if(uni(u,v))
      {
        printf("\n%d edge (%d,%d) =%.2lf\n",ne++,a,b,min);
        custo[a][b]=custo[b][a]=min;
        mincost +=min;
      }
      // printf("Apos iteracao %d\n", ne);
      // for(i=0;i<n;i++){printf("%d ", parent[i]);}
      /*if(cor[a]==CINZA)
          cor[a] = PRETO;
      else
        cor[a] = cor[b] = CINZA;

      if(cor[b]==CINZA)
          cor[b] = PRETO;
      else
        cor[b] = CINZA;
      */
      cost[a][b]=cost[b][a]=INF;
      
 }
 printf("\n\tMinimum cost = %.2lf\n",mincost);



 for(i=0;i<MAX;i++)printf("%d ", parent[i]);
// 
// for ( i = 1; i <= n; i++)
// {
//   for ( j = 1; j<=n; j++)
//   {
//     printf("%d ",cost[i][j]);
//   }
//   printf("\n");
// }


 
}



int find(int i)
{
 while(parent[i]){
  i=parent[i]; 
}
  
 return i;
}

int uni(int i,int j)
{
 if(i!=j)
  {
  parent[j]=i;
  
  return 1;
 }

 return 0;
}


