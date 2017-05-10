#include "Arquivos.h"

void lerArquivo(FILE *fp, int *matrix, double **m1)
{
	int i, j=0;
    i=0;
    char c;
    //salvando o arquivo em uma matriz
    while(fscanf(fp,"%d",&matrix[i])!=EOF){ //le a classe e verifica se chegou no final do arquivo
        while((c=getc(fp))!='\r'){ //enquanto nao chegar no final da linha
          if(c==EOF) break; //caso chegue no final do arquivo (exemplo, digitou ultima linha e fechou arquivo sem \r)
            fscanf(fp,"%lf",m1[i]+j); //le o valor
            j++;
        }
        m1[i][j]=INF; //marcando o final da linha com double_MAX
        j=0;
        i++;
    }
    fclose(fp);
}