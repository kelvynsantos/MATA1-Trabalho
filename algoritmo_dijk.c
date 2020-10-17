#include <stdio.h>
#include <stdlib.h>
#define INF 99999
#define V 10

void main()
{
   	int g[V][V], n, inicio;
	int i, j;
    printf("Quantos Vertices? ");
    scanf("%d", &n);
    
    grafo(g, n);
    
    printf("\nDigite o vertice inicial:\n");
	scanf("%d", &inicio);
	
	dijkstra(g, n, inicio);
	
	return 0;
}

// Função que define as arestas e seus pesos
int grafo(int g[V][V], int n)
{
    int i, j, p;
    char resposta;
    for (i = 1 ; i <= n ; i++)
    {
        for (j = 1 ; j <= n ; j++)
        {
            if (i == j)
            {
                g[i][j] = 0;
				continue;
			}
            printf("\nOs vertices %d e %d formam uma aresta? (S/N):",i , j);
            scanf(" %c", &resposta);
            if (resposta == 's' || resposta == 'S')
            {
				printf("Qual o peso? ");
                scanf("%d", &p);
                g[i][j] = p;
            }
            else 
            {
                g[i][j] = 0;
        	}
		}
    }
}

// Função que implementa o algoritmo de Dijkstra em um grafo ou digrafo
void dijkstra(int g[V][V], int n, int inicio)
{
	int peso[V][V], distancia[V], marcado[V], anterior[V];
	int i, j, cont, dist_minima, proximo;
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(g[i][j] == 0)
			{
				peso[i][j] = INF;
			}
			else
			{
				peso[i][j] = g[i][j];
			}
		}
	}
	
	for(i = 1; i <= n; i++)
	{
		distancia[i] = peso[inicio][i];
		anterior[i] = inicio;
		marcado[i] = 0;
	}
	
	distancia[inicio] = 0;
	marcado[inicio] = 1;
	cont = 1;
	
	while(cont <= n-1)
	{
		dist_minima = INF;
		for(i = 1; i < n; i++)
		{
			if(distancia[i] < dist_minima && !marcado[i])
			{
				dist_minima = distancia[i];
				proximo = i;
			}
		}
		
		marcado[proximo] = 1;
		
		for(i = 1; i <= n; i++)
		{
			if(!marcado[i])
			{
				if((dist_minima + peso[proximo][i]) < distancia[i])
				{
					distancia[i] = dist_minima + peso[proximo][i];
					anterior[i] = proximo;
				}
			}
		}
		cont++;
	}
	
	for(i = 1; i <= n; i++)
	{
		if(i != inicio)
		{
			printf("A menor distancia ate o vertice %d eh %d\n", i, distancia[i]);
			printf("O caminho realizado: %d", i);
			
			j = i;
			do{
				j = anterior[j];
				printf(" <- %d", j);
			}while (j != inicio);
		}
		printf("\n");
	}
}
