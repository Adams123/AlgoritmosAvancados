#include "matrizes.h"

Matriz Mpower(Matriz x, long long n)
{
  if(n==1 || n==0)
    return (x);

	if(n%2==0) //par (x^(n/2)^2) == (x^2)^(n/2)
    return(Mpower(multiplicaMatriz(x,x),n/2));
	else //impar x*(x^(n/2)^2)
    return(multiplicaMatriz(x,Mpower(multiplicaMatriz(x,x),n/2)));
}

Matriz multiplicaMatriz(Matriz m1, Matriz m2)
{
  //utilizado algoritmo de Strassen para calculo da multiplicação de matriz
  Matriz aux;

  long long r1,r2,r3,r4,r5,r6,r7;
  
  r1= (m1.a + m1.d)*(m2.a+m2.d);
  r2= (m1.c+m1.d)*m2.a;
  r3= m1.a*(m2.b-m2.d);
  r4= m1.d*(m2.c-m2.a);
  r5= (m1.a+m1.b)*m2.d;
  r6= (m1.c-m1.a)*(m2.a+m2.b);
  r7= (m1.b-m1.d)*(m2.c+m2.d);

  aux.a=(r1+r4-r5+r7)%1000000;
  aux.b=(r3+r5)%1000000;
  aux.c=(r2+r4)%1000000;
  aux.d=(r1-r2+r3+r6)%1000000;
  
  return aux;
}

void fibo(long long n)
{

  Matriz M; //matriz inicial {{1,1},{1,0}}
  M.a=1;
  M.b=1;
  M.c=1;
  M.d=0;

  printf("\n#####CALCULANDO FIBONACCI DE %lld#####\n", n);
  if (n<=0){
    printf("Valor de fibonacci: 1\n");
    return;
  }

  M=Mpower(M,n); //calcula o fibonacci
  printf("Valor de fibonacci: %lld\n", M.a);

}