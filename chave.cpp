#include <stdio.h>
#include <math.h>

int primo(int x)   //fun��o para verificar se o n�mero � primo
{
	int cont = 3;
	if (x < 2){
		return(false);
	} else if (x == 2){
		return(true);
	} else if (x % 2 == 0){
		return(false);
	} else {
		while (cont <= sqrt(x)) {
			if (x % cont == 0){
				return(false);
			}
			else {
				cont = cont + 2;
			}
		}
	}
	if (sqrt(x) < cont){
		return(true);
	}
}

int mdc_euclides(int a, int b){  //fun��o para calcular o mdc de Euclides
	int res;
	while (b != 0){
		res = a % b;
		a = b;
		b = res;
	} 
	return(a);
}

int mmc (int a, int b){   //fun��o para calcular o mmc
	int res;
	res = a * b / mdc_euclides(a, b);
	return(res);
}


int main()
{
	int p, q, n;
	printf("Digite o valor de p: ");
	scanf("%d", &p);
	while (primo(p) == false)
	{
		printf("O n�mero digitado precisa ser primo\n");
		printf("Digite o valor de p: ");
		scanf("%d", &p);
	}
	printf("Digite o valor de q: ");
	scanf("%d", &q);
	while (primo(q) == false)
	{
		printf("O n�mero digitado precisa ser primo\n");
		printf("Digite o valor de q: ");
		scanf("%d", &q);
	}
	n = p * q;
}
