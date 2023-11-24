#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
int valinum (int ri, int rf, const char msge[ ]);
int vali_num2(int ri, int rf, int t);
void ordenar(int vect[], int m);
int busq_sec(int vect[], int n, int num);
void vali_cad(char apepat[]);



int valinum(int ri, int rf,const char msge[ ])
{
	int num,  i;
    i = 0;

	char xnum[30];
	do{
		puts(msge);
		fflush(stdin);
		gets(xnum);
		num = atoi(xnum);

	}while(num < ri || num > rf);
	
	return num;

}


int vali_num2(int ri, int rf, int t) {
    int i = 0, tecla;
    char str[30];
    
    do {
        tecla = getch();

        if (isdigit(tecla) && i < t) {
            printf("%c", tecla);
            str[i++] = tecla;
        } else if (tecla == 8 && i > 0) {  // Manejo de tecla de retroceso
            printf("\b \b");
            i--;
        }
    } while (i != t);

    str[i] = '\0';
    int num = atoi(str);

    if (num >= ri && num <= rf) {
        return num;
    } else {
        printf("\n");
        return vali_num2(ri, rf, t);
    }
}




int lee_num(int ri, int rf, int t) 
{
    int i, tecla;
	char str[30];
    i = 0;
    do {
        tecla = getch();

        if (isdigit(tecla)) 
		{
			printf("%c",tecla);
            str[i++] = tecla;
        }

    } while (i != t);

    str[i] = '\0';
    int num = atoi(str);

    if (num >= ri && num <= rf)
	{
        return num;
    } 
	else 
	{
		printf("\b\b");
		i = i-2;
	
        return lee_num(ri, rf, t);
    }
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
    num = valinum(100, 200, "QUE NUMERO BUSCAS");
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

void vali_cad(char cadena[])
{
	char tecla;
    int i, esp, punto, diagonal;
    i = 0;
    esp = 1;
    punto = 1;
    diagonal = 1;
    do {
        //aqui se guarda la letra intrducida por el usuario
        tecla = toupper(getch());//CONVIERTE A MAYUSCULAS
                              
        if (isalpha(tecla)) //verifica si es una letra
        {   
            printf("%c", tecla);
            //si es una letra se le asigna esa misma en la poscion i de la cadena
            //incrementa para la siguiente letra
            cadena[i++] = tecla;  
            esp = 0;
            punto = 0;
            diagonal = 0;
        } 
        
        else
        {
            if(tecla == 32 && esp == 0)
            {
                cadena[i++] = tecla;
                printf("%c", tecla);
                esp = 1;
            }
            else
            {
                if(tecla == -92)
                {
                    tecla == -91;
                     printf("%c", -91);
                    cadena[i++] = -91;
                }
                if(tecla == -91)
                {
                    printf("%c", -91);
                    cadena[i++] = -91; 
                }
              
            }
            if(tecla == 46 && punto == 0)
            {
                printf("%c", 46);
                cadena[i++] = 46;
                punto = 1;
            }
            if(tecla == 47 && diagonal == 0)
            {
                printf("%c", 47);
                cadena[i++] = 47;
                diagonal = 1;

            }
            

        }
        //si no es un letra vuelve al incio sin hacer cambios en la cadena
        //si el usuario preciona enter se termina el ciclo y se guardan solo los datos validos en la cadena
    } while (tecla != 13);
    cadena[i] = '\0';
    if(esp)
    {
        cadena[i-1] = '\0';
    }  
    if(punto)
    {
        cadena[i-1] = '\0';
    }  
    if(diagonal)
    {
        cadena[i-1] = '\0';
    } 


}

void lee_numm(char str[], int t, const char msge[])
{
    int i, tecla;
    i = 0;
    
    do{
        tecla = getch();
        
        if(isalpha(tecla))
        {
            printf("%c", tecla);
            str[i++] = tecla;
        }

        str[i] = '\0';
        printf("\n");
    }while(i != t);
}
