#include "DTW.h"

void DTW()
{
    FILE *fp1;
    FILE *fp2;
    fp1=fopen("teste.txt", "r+");
    fp2=fopen("treino.txt", "r+");

    int i=0,j=0, k=0, l=0; //apenas contadores
    double **m1; //matriz para guardar o arquivo teste.txt
    double **m2; //matriz para guardar o arquivo treino.txt
    double *results; //vetor para guardar o resultado DTW de uma unica linha do arquivo teste.txt
    double cont=0; //contador de acertos DTW
    int *classeM1, *classeM2; //vetores para guardar as classificações de cada linha de cada arquivo
    int *finalResults; //vetor para guardar qual a melhor série do arquivo treino.txt correspondente a posicao 'i' do vetor
    //Exemplo: se a linha 1 do arquivo teste.txt possui a melhor classificao na linha 2 de treino.txt, entao a posicao 1
    //de finalResults ira conter 2

    //ALOCACOES
    classeM1=(int*) malloc(sizeof(int)*960);
    finalResults=(int*) malloc(sizeof(int)*960);
    classeM2=(int*) malloc(sizeof(int)*240);
    results=(double*) malloc(sizeof(double)*240);

    m2 = (double **) malloc (sizeof(double*) * 240);
    for(i=0;i<240;i++)
    {
        m2[i] = (double *) malloc (sizeof(double) * 165);
    }

    m1 = (double **) malloc (sizeof(double*) * 960);
    for(i=0;i<960;i++)
    {
        m1[i] = (double *) malloc (sizeof(double) * 165);
    }
    //FIM ALOCACOES

    lerArquivo(fp1, classeM1, m1); //carrega arquivo teste.txt na matriz
    lerArquivo(fp2, classeM2, m2); //carrega arquivo treino.txt na matriz
    
    for(i=0;i<960;i++) //percorrendo todas as linhas do teste.txt
    {
        for(k=0;k<164;k++){ //conta quantidade de valores da linha atual do arquivo teste.txt
            if(m1[i][k] == INF) //usamos INF como marcador
                break;
        }
        for(j=0;j<240;j++) //percorrendo todas as linhas do treino.txt
        {
            for(l=0;l<165;l++)//conta quantidade de valores da linha atual do arquivo treino.txt
                if(m2[j][l] == INF) 
                    break;
            results[j] = DTWDistance(m1[i], m2[j], k,l); //calcula DTW entre a linha 'i' do arquivo teste.txt e a linha 
        }
        
        if(classeM1[i]==classeM2[menor(results, j)]) //verifica se as classes do arquivo teste.txt sao condizentes com o arquivo treino.txt
            cont++;
    }
    printf("Contagem de acertos: %.0f\n", cont);
    printf("Porcentagem: %.2f\n", ((cont/960)*100));

    free(classeM1);
    free(classeM2);
    for(i=0;i<240;i++)
        {
            free(m1[i]);
            free(m2[j]);
        }
    free(m1); free(m2);
}

int menor(double *v, int tam)
{
    int i, pos=0;
    double menor;
    menor=INF;
    for(i=0;i<tam;i++)
    {
        if(v[i] < menor){
            menor=v[i]; //guarda o menor valor para proxima comparacao
            pos=i; //guarda a posicao do menor valor
        }
    }
    return pos; //retorna a posicao do menor valor
}

double DTWDistance(double *m1, double *m2, int n, int m) //algoritmo DTW, baseado no algoritmo disponível na wikipedia.
{
	int i, j;
    double DTW[n][m];

    for(i=0;i<n;i++)
    	DTW[i][0] = INF;

    for(i=0;i<m;i++)
    	DTW[0][i]=INF;

    DTW[0][0]=0;

    for(i=1;i<n;i++)
    	for(j=1;j<m;j++)
    		DTW[i][j]=modulo(m1[i], m2[j])+minimum(DTW[i-1][j], DTW[i][j-1], DTW[i-1][j-1]);

    return DTW[n-1][m-1];
}

double minimum(double a, double b, double c)
{
    if(a<=b && a<=c)
            return a;
    else if(b<=c && b<=a)
            return b;
    else return c;
}

double modulo(double a, double b)
{
	return (pow(a-b,2));
}