#include <stdio.h>
#include <time.h>
#include <string.h>
int vali_num (int ri, int rf, const char msge[ ]);
void ordenar(int vect[], int m);
int busq_sec(int vect[], int n, int num);



int vali_num (int ri, int rf, const char msge[ ])
{
	int num;
	char xnum[30];
	do{
		puts(msge);
		fflush(stdin);
		gets(xnum);
		num = atoi(xnum);

	}while(num < ri || num > rf);
	
	return num;

}

void ordenar(int vect[], int m)
{
    int i, j;
    int temp;

    for(i=0; i<m-1; i++)
    {
        for(j=i+1; j<m; j++)
        {
            if(vect[j] < vect[i])
            {
                 temp = vect[i];
                 vect[i] = vect[j];
                 vect[j] = temp;
            }
        }
    }
}

void buscar(int vect[], int m)
{
    int num, x, i;
    system("CLS");
    num = vali_num(100, 200, "QUE NUMERO BUSCAS");
    x = busq_sec(vect, m, num);

    if(x != -1)
    {
        printf("EL NUMERO INGRESADO SI ESTA EN EL VECTOR\n\n");
        printf("%d ESTA EN EL INDICE %d\n\n", num, x);
    }
    else
    {
        printf("EL NUMERO QUE INGRESASE EN EL VECTOR NO EXISTE");
    }
    system("PAUSE");

}

int busq_sec(int vect[], int n, int num)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(num == vect[i])
        {
            return i;
        }
    }
    return -1;
}
