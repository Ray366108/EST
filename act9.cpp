//RAYMUNDO MIGUEL AGUILERA MATRICULA: 366108
//6 DE OCTUBRE DE 2023
//LLENAR VECTOR, LLENAR MATRIZ, IMPRIMIR VECTOR,
//IMPRIMIR MATRIZ, ORDENA VECTOR, BUSCAR VALOR EN VECTOR 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 15
#define M2 16
#include "gordillo.h"
void menu();
int msges();
void llena_vec_aleatorio(int vect[], int m, int ri, int rf);
void llenavec_alemat(int vectmat[], int m2, int ri, int rf);
void llena_mat (int mat[][4], int vectmat[], int m2, int n);
void imprime_vect (int vect1[], int m);
void imprime_mat (int matriz[][4], int m, int n);
void imprime_ordenado(int vect1[], int m);

int main ()
{
    menu();
    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("    M    E    N    U\n");
    printf("1.- LLENA VECTOR ALEATORIAENTE\n");
    printf("2.- LLENA MATRIZ ALEATORIAMENTE\n");
    printf("3.- IMPRIMIR VECTOR\n");
    printf("4.- IMPRIMIR MATRIZ\n");
    printf("5.- ORDENAR VECTOR\n");
    printf("6.- BUSCAR VALOR EN VECTOR\n");
    printf("7.- IMPRIME VECTOR ORDENADO\n");
    printf("0.- SALIR\n");
    printf("ESCOGE UNA OPCION:");
    scanf("%d", &op);

    return op;
}

void menu ()
{
    int op, vec1[M], vecmat[M2], mat[4][4];
    do{
        op = msges();
        switch(op)
        {
            case 1:
                  llena_vec_aleatorio(vec1, M, 100, 200);
                  break;
            case 2: 
                  llenavec_alemat(vecmat, M2, 1, 16);
                  llena_mat (mat, vecmat, 4, 4);
                  break;
            case 3:
                  imprime_vect (vec1, M);
                  break;
            case 4:
                  imprime_mat(mat, 4, 4);
                  break;
            case 5:
                  ordenar(vec1, M);
                  break;
            case 6:
                  buscar(vec1, M);
                  break;
            case 7:
                  imprime_ordenado(vec1, M);
                  break;
                  
        }
    }while(op != 0);
}

void llena_vec_aleatorio(int vect[], int m, int ri, int rf)
{
    int i, j, numero, pos, rango;
	rango = (rf - ri) + 1;
	srand(time(NULL));
	for(i=0; i <m; i++)
	{
		do{
		numero = (rand() % rango) + ri;
		pos = 0;
		for(j=0; j<i; j++)
		{
			if(vect[j] == numero)
			{
				pos = 1;
			    break;
			}
		}
			
		}while(pos);
		vect[i] = numero;
	}
}

void llenavec_alemat(int vectmat[], int m2, int ri, int rf)
{
    int i, j, numero, pos, rango;
	rango = (rf - ri) + 1;
	srand(time(NULL));
	for(i=0; i <m2; i++)
	{
		do{
		numero = (rand() % rango) + ri;
		pos = 0;
		for(j=0; j<i; j++)
		{
			if(vectmat[j] == numero)
			{
				pos = 1;
			    break;
			}
		}
			
		}while(pos);
		vectmat[i] = numero;
	}
}

void llena_mat (int mat[][4], int vectmat[], int m2, int n)
{
	int i, j, k=0;
	for(i=0; i<m2; i++)
	{
		for(j=0; j < n; j++)
		{
			mat[i][j] = vectmat[k++];
		}
	}
}

void imprime_vect (int vect1[], int m)
{
	int i;
	system("CLS");
	printf(" V E C T O R 1\n\n");
	for(i=0; i<m; i++)
	{
		printf("VECTOR [%d] = %d\n", i, vect1[i]);
	}
	system("PAUSE");
}

void imprime_mat (int matriz[][4], int m, int n)
{
	int i, j;
	system("CLS");
	printf("    M A T R I Z\n\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j < n; j++)
		{
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	system("PAUSE");
}

void imprime_ordenado(int vect1[], int m)
{
    int i;
	system("CLS");
	printf(" V E C T O R 1\n\n");
	for(i=0; i<m; i++)
	{
		printf("VECTOR [%d] = %d\n", i, vect1[i]);
	}
	system("PAUSE");

}
