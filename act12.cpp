#include <stdio.h>
#include <stdlib.h>
#include "gordillo.h"
#define N 1500

typedef struct _datos {
    int status;
    int matri;
    int edad;
    char nombre[50];
    char appat[50];
    char apmat[50];
    char sexo[15];
} Tdatos;

int msges();
void menu();
int lee_arch(Tdatos vect[], int i);
Tdatos gen_reg_man();
void delete_reg(Tdatos vect[], int *n);
void busca_reg(Tdatos vect[], int n);
void ordena_reg(Tdatos vect[], int n);
void imprime_reg(Tdatos vect[], int n);
void genfilenew(Tdatos vect[], int n);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("   M   E   N   U\n");
    printf("1.- Cargar archivo\n");
    printf("2.- agregar\n");
    printf("3.- eliminar\n");
    printf("4.- buscar\n");
    printf("5.- ordenar\n");
    printf("6.- Imprimir\n");
    printf("7.- crear archivo (txt)\n");
    printf("0.- Salir\n");
    printf("ESCOGE UNA OPCION: ");
    op = vali_num2(0, 6, 1);

    return op;
}

void menu()
{
    Tdatos vect[N];
    int i = 0, op, j;
    int band = 0;
    int n = 0, cargaex = 0;

    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            if (i < N)
            {
                i = lee_arch(vect, i);
                if (i > n)
                {
                    cargaex = 1;
                    n = i;
                    printf("datos cargados ..\n");
                }
                else
                {
                    printf("error al cargar datos");
                }
                break;
            }
            else
            {
                printf("no se puede agregar mas registros");
            }
            system("pause");
        case 2:
            if (i < N)
            {
                vect[i] = gen_reg_man();
                i++;
                printf("Registro agregado correctamente.\n");
            }
            else
            {
                printf("No se pueden agregar mÃ¡s registros. El arreglo estÃ¡ lleno.\n");
            }
            break;
        case 3:
            delete_reg(vect, &i);
            break;
        case 4:
            busca_reg(vect, i);
            break;
        case 5:
            ordena_reg(vect, i);
            printf("Los registros se ordenaron exitosamente...\n");
            break;
        case 6:
            imprime_reg(vect, i);
            break;
        case 7:
            if (cargaex)
            {
                genfilenew(vect, i);
            }
            else
            {
                printf("No hay datos cargados...\n");
            }
            break;
        }
    } while (op != 0);
}

int lee_arch(Tdatos vect[], int i)
{
    int x;
    FILE *fa;
    Tdatos reg;
    system("cls");
    fa = fopen("datos.txt", "r");
    if (fa)
    {
        do
        {
            if (fscanf(fa, "%d  %d  %s  %s  %s   %d   %s", &x, &reg.matri, &reg.nombre, &reg.appat, &reg.apmat, &reg.edad, &reg.sexo) == 7)
            {
                reg.status = 1;
                vect[i++] = reg;
            }
            else
            {
                printf("error al leer datos en la linea %d. saliendo \n", i + 1);
                break;
            }
        } while (!feof(fa));
        fclose(fa);
        return i;
    }
    else
    {
        printf("archivo no existe\n");
    }
    return i;
}

Tdatos gen_reg_man()
{
    Tdatos reg;
    int sexo;
    char op;
    system("CLS");
    reg.status = 1;
    printf("DAME TU MATRICULA: ");
    reg.matri = vali_num2(300000, 399999, 6);
    printf("\nDAME TU EDAD: ");
    reg.edad = vali_num2(14, 60, 2);
    printf("\nDAME TU NOMBRE: ");
    vali_cad(reg.nombre);
    printf("\nAPELLIDO PATERNO: ");
    vali_cad(reg.appat);
    printf("\nAPELLIDO MATERNO: ");
    vali_cad(reg.apmat);
    printf("\nCUAL ES TU SEXO? 1.- HOMBRE 2.- MUJER: ");
    sexo = vali_num2(1, 2, 1);

    if (sexo == 1)
    {
        strcpy(reg.sexo, "HOMBRE");
    }
    else
    {
        strcpy(reg.sexo, "MUJER");
    }
    printf("\n");
    system("pause");

    return reg;
}

void delete_reg(Tdatos vect[], int *n)
{
    int matricula;
    printf("Ingrese la matricula del estudiante que desea eliminar: ");
    matricula = vali_num2(300000, 399999, 6);

    int indice = -1;
    for (int i = 0; i < *n; i++)
    {
        if (vect[i].status == 1 && vect[i].matri == matricula)
        {
            vect[i].status = 0;
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
        printf("Registro eliminado....\n");
    }
    else
    {
        printf("Matricula inexistente...\n");
    }
}

void busca_reg(Tdatos vect[], int n)
{
    int matricula;
    printf("Ingrese la matricula que desea buscar: ");
    matricula = vali_num2(300000, 399999, 6);

    int encontrado = 0; // bandera para saber si se encuentra el registro
    for (int i = 0; i < n; i++)
    {
        if (vect[i].status == 1 && vect[i].matri == matricula)
        {
            encontrado = 1;
            printf("Registro encontrado:\n");
            printf("Matricula: %d\n", vect[i].matri);
            printf("Nombre: %s\n", vect[i].nombre);
            printf("Ap Paterno: %s\n", vect[i].appat);
            printf("Ap Materno: %s\n", vect[i].apmat);
            printf("Edad: %d\n", vect[i].edad);

            if (strcmp(vect[i].sexo, "MASCULINO") == 0)
            {
                printf("Sexo: MASCULINO\n");
            }
            else
            {
                printf("Sexo: FEMENINO\n");
            }

            break;
        }
    }

    if (!encontrado)
    {
        printf("No se encontro ningun registro con la matricula ingresada...\n");
    }
}

void ordena_reg(Tdatos vect[], int n)
{
    Tdatos temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vect[j].matri > vect[j + 1].matri)
            {
                temp = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = temp;
            }
        }
    }
}

void imprime_reg(Tdatos vect[], int n)
{
    int i;
    printf("\n\n\nNo.   MATRICULA  NOMBRE            APPAT             APMAT             EDAD    SEXO\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status == 1)
        {
            printf("%-4d %-11d %-17s %-17s %-17s %-6d %-s\n", i, vect[i].matri, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
        }
    }
    getchar();
}

void genfilenew(Tdatos vect[], int n) 
{
    FILE *newfile;
    newfile = fopen("newfile.txt", "w");

    if (newfile) 
    {
        for (int i = 0; i < n; i++) 
        {
            if (vect[i].status == 1) 
            {
                fprintf(newfile, "%d %d %s %s %s %d %s\n",
                        i, vect[i].matri, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
            }
        }

        fclose(newfile);
        printf("Archivo 'newfile.txt' generado\n");
    } else 
    {
        printf("Error al abrir el archivo para escritura.\n");
    }
}