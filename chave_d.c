#include <stdio.h>
#include <math.h>

// Função para verificar se o número é primo
int primo(int x)   
{
	int cont = 3;
	if (x < 2){
		return 0;
	} else if (x == 2){
		return 1;
	} else if (x % 2 == 0){
		return 0;
	} else {
		while (cont <= sqrt(x)) {
			if (x % cont == 0){
				return 0;
			}
			else {
				cont = cont + 2;
			}
		}
	}
	if (sqrt(x) < cont){
		return 1;
	}
}

// Função para calcular o mdc de Euclides
int mdc_euclides(int a, int b){  
	int res;
	while (b != 0){
		res = a % b;
		a = b;
		b = res;
	} 
	return(a);
}

// Função para calcular o mmc
int mmc (int a, int b){   
	int res;
	res = a * b / mdc_euclides(a, b);
	return(res);
}

int main()
{
	int p, q, n;
	printf("Digite o valor de p: ");
	scanf("%d", &p);
	while (primo(p) == 0)
	{
		printf("O numero digitado precisa ser primo\n");
		printf("Digite o valor de p: ");
		scanf("%d", &p);
	}
	printf("Digite o valor de q: ");
	scanf("%d", &q);
	while (primo(q) == 0)
	{
		printf("O numero digitado precisa ser primo\n");
		printf("Digite o valor de q: ");
		scanf("%d", &q);
	}
	n = p * q;
	
    int e, f;
	f = mmc(p-1,q-1);
    printf("Digite o valor da chave e: ");
    scanf("%d", &e);
    
    // Verificar se a chave pública e a função lambda são co-primas, mdc(e,f) = 1
    while(mdc_euclides(e,f) != 1)
    {
    	printf("Os valores da chave publica e da funcao lambda nao sao primos entre si\n");
		printf("Digite o valor da chave e: ");
    	scanf("%d", &e);
	}
	
	// Calcular o valor da chave privada d (result), usando o algoritmo extendido de Euclides
 	int a=f, b=f, c=e, d=1;
	int x, y, result;
 	while (x != 1)
	{	
		x = (a - floor(a/c)*c);
		y = (b - floor(a/c)*d);
		
		a = c;
		b = d;
		c = x;
		d = y;
	}
	result = d % f;
	
	// Se o valor da chave privada for negativo, calcular o menor valor não negativo congruente
	while (result < 0)
	{
		result = result + f;
	}

	printf("\nd = %d",result);
}
