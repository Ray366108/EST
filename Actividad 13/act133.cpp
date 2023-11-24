//RAYMUNDO MIGUEL AGUILERA MATRICULA: 3666108
//23 DE NOVIEMBRE DE 2023
//ARCHIVOS BINARIOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "gordillo.h"

#define N 5000
bool cargadoDesdeBinario = false;

typedef struct _datos {
    int status;
    int id;
    char nombre[30];
    char appat[30];
    char apmat[30];
    int edad;
    char sexo[30];
} Tdatos;

int msges();
void menu();
Tdatos gen_reg_aut();
void impr_regs(Tdatos vect[], int n);
void buscar_reg(Tdatos vect[], int n);
void editar_registro(Tdatos vect[], int n);
void delete_for_num(Tdatos vect[], int *n);
void ordenar_reg(Tdatos vect[], int n);
void generar_archivo_texto(Tdatos vect[], int n);
void mostrar_archivo_texto();
void guardar_a_binario(Tdatos vect[], int n);
void cargar_desde_binario(Tdatos vect[], int* n);
void mostrar_eliminados();



int main() {
    srand(time(NULL));
    menu();
    return 0;
}

void gen_nom_mujer(char cadena[]) 
{
    char nom[20][10] = {"KARLA", "SARA", "SOFIA", "ANDREA", "VICTORIA", "ISABEL", "ANA",
                        "MARTA", "CRISTINA", "MIRIAM", "ALEJANDRA", "ADRIANA","DIANA",
                        "VANESA", "ELSA", "BELEN", " NAHOMY", "MARGARITA", "ANGELA","SONDRA"};
    strcpy(cadena, nom[rand() % 20]);
}

void gen_nom_hombre(char cadena[]) 
{
     char nom[20][10] = {"CARLOS", "ALFREDO", "MAURICIO", "MIGUEL", "JOSE", "ALEJANDRO", "DAVID",
                        "ENRIQUE", "FRANCISCO", "PEDRO", "JESUS", "JASON", "MISAEL", "KENEETH",
                        "MANUEL", "ROBERTO", "FRANCO", "IVAN", "CESAR", "OSCAR"};
    strcpy(cadena, nom[rand() % 20]);
}

void gen_ape(char cadena[]) 
{
    char ap[20][10] = {"HERNANDEZ", "LOERA", "GALINDO", "TOLEDO", "GARCIA", "MARTINEZ", "LOPEZ",
                       "SANCHEZ", "SMITH", "VALDEZ", "AGUILAR", "RODRIGUEZ", "RAMOS", "CASILLAS",
                       "ORTIZ", "CASTRO", "GUZMAN", "NOSE", "SALAZAR", "GOMEZ"}; 
    strcpy(cadena, ap[rand() % 20]);
}

int msges()
{
    int op;
    printf("        M     E     N     U\n");
    printf("=================================\n");
    printf("1.- AGREGAR (AUTOM 100 REGISTROS)\n");
    printf("2.- EDITAR REGISTRO\n");
    printf("3.- ELIMINAR REGISTRO (logico)\n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR\n");
    printf("6- IMPRIMIR \n");
    printf("7.- GENERAR ARCHIVO TEXTO\n");
    printf("8.- VER ARCHIVO TEXTO\n");
    printf("9.- CREAR ARCH BINARIO \n");
    printf("10.- CARGAR ARCH BINARIO\n");
    printf("11.- MOSTRAR ELIMINADOS \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION ");

    op = vali_num2(0, 11, 2);
    return op;

}


void menu() {
    Tdatos vect[N];
    int op, n = 0, i = 0;
    int cargaExitosa = 0;

    do {
        op = msges();

        switch (op) {
            case 1:
            system("cls");
                for (int j = 0; j < 100; j++) {
                    vect[i] = gen_reg_aut();
                    i++;
                }
                n += 100;
                printf("Se agregaron 100 registros\n");
                system("pause");
                break;

            case 2:
                editar_registro(vect, i);
                break;
            
            case 3:
                delete_for_num(vect, &i);
                break;
            case 4:
                buscar_reg(vect, i);
                break;

            case 5: 
                ordenar_reg(vect, i);
                printf("REGISTRO ORDENADO POR NUMERO DE TRABAJADOR\n");
                break;

            case 6:  
                impr_regs(vect, i);
                break;
            
            case 7:
                generar_archivo_texto(vect, i);
                break;
            
            case 8:
                mostrar_archivo_texto();
                break;
            
             case 9:
                guardar_a_binario(vect, n);
                break;
            case 10:
                cargar_desde_binario(vect, &i);
                break;
            case 11:
                mostrar_eliminados();
                break;
                                        
        }
    } while (op != 0);
}

Tdatos gen_reg_aut() 
{
    Tdatos reg;
    int sexo;
    reg.status = 1;
    reg.id = rand() % 100 + 300;
    sexo=(rand()%2)+1; 
    if (sexo == 1)
    {
        strcpy(reg.sexo,"MASCULINO");
        gen_nom_hombre(reg.nombre); 
    } 
    else
    {
        strcpy(reg.sexo,"FEMENINO");
        gen_nom_mujer(reg.nombre);

    }
    gen_ape(reg.appat);
    gen_ape(reg.apmat);
    reg.edad = rand() % 50 + 20; 

    return reg;

}


void buscar_reg(Tdatos vect[], int n) 
{
    int numero;
    printf("Ingrese el id que desea buscar: ");
    numero = vali_num2(100, 400, 3);

    int encontrado = 0; // Variable para rastrear si se encuentra el registro
    for (int i = 0; i < n; i++) {
        if (vect[i].status == 1 && vect[i].id == numero) {
            encontrado = 1;
            printf("Registro encontrado:\n");
            printf("Numero de trabajador: %d\n", vect[i].id);
            printf("Nombre: %s\n", vect[i].nombre);
            printf("Apellido Paterno: %s\n", vect[i].appat);
            printf("Apellido Materno: %s\n", vect[i].apmat);
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

    if (!encontrado) {
        printf("No se encontro ningun registro con el numero de trabajador\n");
    }
}

void editar_registro(Tdatos vect[], int n) 
{
    int numero;
    printf("Ingresa id que desea editar: ");
    numero = vali_num2(100, 400, 3);

    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (vect[i].status == 1 && vect[i].id == numero) 
        {
            encontrado = 1;
            printf("Registro encontrado:\n");
            printf("Numero de trabajador: %d\n", vect[i].id);
            printf("Nombre: %s\n", vect[i].nombre);
            printf("Apellido Paterno: %s\n", vect[i].appat);
            printf("Apellido Materno: %s\n", vect[i].apmat);
            printf("Edad: %d\n", vect[i].edad);
            printf("Sexo: %s\n", vect[i].sexo);

            int campo;
            printf("\n [EDITAR DATOS DE EMPLEADO]\n");
            printf("1. Nombre\n");
            printf("2. Apellido Paterno\n");
            printf("3. Apellido Materno\n");
            printf("4. Edad\n");
            printf("5. Sexo\n");
            printf("Escoga el campo a editar: ");
            campo = vali_num2(1, 5, 1);

            switch (campo) {
                case 1:
                    printf("Ingrese el nuevo nombre: ");
                    scanf("%s", vect[i].nombre);
                    break;

                case 2:
                    printf("Ingrese el nuevo apellido paterno: ");
                    scanf("%s", vect[i].appat);
                    break;

                case 3:
                    printf("Ingrese el nuevo apellido materno: ");
                    scanf("%s", vect[i].apmat);
                    break;

                case 4:
                    printf("Ingrese la nueva edad: ");
                    scanf("%d", &vect[i].edad);
                    break;

                case 5:
                    printf("Ingrese el nuevo sexo: ");
                    scanf("%s", vect[i].sexo);
                    break;

            }

            printf("DATOS ACTUALIZADOS...\n");
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontro ningun registro con el id del trabajador\n");
    }
}

void delete_for_num(Tdatos vect[], int *n)
{
    int numero, com = 0, op;
    printf("Ingrese el id del trabajador que desea eliminar: ");
    numero = vali_num2(100, 400, 3);

    int indice = -1; // indice del registro a eliminar
    for (int i = 0; i < *n; i++) 
    {
        if (vect[i].status == 1 && vect[i].id == numero) 
        {
            printf("\nempleado encontrado\n");
            com=1;
            printf("ESTA SEGURO DE ELIMINARLO? [1.-SI][2.-NO]: ");
            op = vali_num2(1, 2, 1);
            if(op == 1)
            {
                vect[i].status = 0; 
                indice = i;
                break;
            }

        }
    }

    if (indice != -1) 
    {
        printf("Registro eliminado...\n");
    } 
    else 
    {
        printf("No se encontro ningun registro con el id...\n");
    }
}

void impr_regs(Tdatos vect[], int n) 
{
    int i;
    printf("\n\n\n[No]   [ID DE TRABAJADOR]  [NOMBRE]            [APPAT]             [APMAT]             [EDAD]    [SEXO[\n");
    for (i = 0; i < n; i++) 
    {
        if (vect[i].status == 1)
        {
            printf("%-10d %-13d %-17s %-17s %-17s %-6d %-s\n", i, vect[i].id, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
        }
    }
    getchar();
}


void ordenar_reg(Tdatos vect[], int n)
{
    Tdatos temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vect[j].id > vect[j + 1].id) {
                temp = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = temp;
            }
        }
    }
}

void generar_archivo_texto(Tdatos vect[], int n) 
{
    FILE *fa;
    fa = fopen("empleados.txt", "w");

    if (fa) {
        fprintf(fa, "NUM. DE TRABAJADOR  NOMBRE            APPAT             APMAT             EDAD    SEXO\n");
        for (int i = 0; i < n; i++) 
        {
            if (vect[i].status == 1) 
            {
                fprintf(fa, "%-13d %-17s %-17s %-17s %-6d %-s\n", vect[i].id, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
            }
        }

        fclose(fa);
        printf("Archivo generado correctamente...\n");
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}

void mostrar_archivo_texto()
{
    char nombre_archivo[50];
    FILE *archivo;

    printf("Ingrese el nombre del archivo (sin extension): ");
    scanf("%s", nombre_archivo);


    strcat(nombre_archivo, ".txt");


    archivo = fopen(nombre_archivo, "r");

    if (archivo) {
        char caracter;

        printf("\nContenido del archivo %s:\n", nombre_archivo);
        while ((caracter = fgetc(archivo)) != EOF) {
            putchar(caracter);
        }

        fclose(archivo);
    } else {
        printf("Error al abrir el archivo. AsegÃºrese de que el archivo existe.\n");
    }
}

void guardar_a_binario(Tdatos vect[], int n) 
{
    FILE* archivo_binario;
    
    archivo_binario = fopen("datos.dll", "wb");

    if (archivo_binario)
    {
        for (int i = 0; i < n; i++) {

            fwrite(&vect[i], sizeof(Tdatos), 1, archivo_binario);
            
        }

        fclose(archivo_binario);
    } 
    else 
    {
        printf("Error al crear el archivo binario.\n");
    }
}

void cargar_desde_binario(Tdatos vect[], int* n) 
{
    if (cargadoDesdeBinario) 
    {
        printf("El archivo binario ya se ha cargado anteriormente.\n");
        return;
    }

    FILE* archivo_binario;
    archivo_binario = fopen("datos.dll", "rb");

    if (archivo_binario) 
    {

        while (fread(&vect[*n], sizeof(Tdatos), 1, archivo_binario) == 1) 
        {
            (*n)++; 
        }

        fclose(archivo_binario);
        cargadoDesdeBinario = true;

        printf("Registros cargados desde el archivo binario.\n");
    } 
    else 
    {
        printf("El archivo binario no existe o no se puede abrir.\n");
    }
}

void mostrar_eliminados() 
{
    FILE* archivo_binario;
    archivo_binario = fopen("datos.dll", "rb");

    if (archivo_binario) 
    {
        Tdatos reg;

        printf("\nRegistros Eliminados:\n");
        printf("NUM. DE TRABAJADOR  NOMBRE            APPAT             APMAT             EDAD    SEXO\n");

        // Leer registros desde el archivo binario
        while (fread(&reg, sizeof(Tdatos), 1, archivo_binario) == 1) 
        {
            if (reg.status == 0) 
            {
                printf("%-13d %-17s %-17s %-17s %-6d %-s\n", reg.id, reg.nombre, reg.appat, reg.apmat, reg.edad, reg.sexo);
            }
        }

        fclose(archivo_binario);
    } 
    else 
    {
        printf("El archivo binario no existe o no se puede abrir.\n");
    }
}