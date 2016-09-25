/*
UTN FRA - TSP
PROGRAMACION/LABORATORIO 01
TP 02 - ESTRUCTURAS
PROGRAMADOR: CARLOS FELIPE M. HENRIQUES
EMAIL: CFMH1985@GMAIL.COM
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 20

int main()
{
    int opcion;
    char rta='n';
    ePersona persona[TAM];

    initEstado(persona, TAM);  //inicializa el campo Estado (0 = vacio, 1 = lleno)

    do{
        system("cls");
        printf("\n*** TP 02 - ESTRUCTURAS ***\n\n");
        printf(" 1- Agregar persona\n");
        printf(" 2- Borrar persona\n");
        printf(" 3- Imprimir lista ordenada por  nombre\n");
        printf(" 4- Imprimir grafico de edades\n");
        printf(" 5- SALIR\n");

        printf("\n\nElija una opcion: \n");
        scanf("%d", &opcion);

        while(opcion<1 || opcion>5)
        {
            printf("\nERROR! Debe ingresar una opcion valida (1 - 5): \n");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
            case 1: //agrega una persona a la base de datos
                system("cls");
                printf("\nAgregar persona a la base de datos\n");
                if(primerVacio(persona, TAM) != (-1))
                    {
                        agregarPersona(persona, primerVacio(persona, TAM),TAM);
                    }
                break;

            case 2: //borra una persona de la base de datos
                system("cls");
                printf("\nBorrar persona de la base de datos\n");
                borrarPersona(persona, TAM);
                system("pause");
                break;

            case 3: //imprime listado de personas ordenadas por nombre
                system("cls");
                printf("\nLista de personas (ordenadas por nombre)\n");
                ordenarNombres(persona, TAM);
                imprimirPersonas(persona, TAM);
                printf("\n\n");
                system("pause");
                break;

            case 4: //imprime grafico de edades
                system("cls");
                graficoNombres(contadorPorRango(persona,TAM,1,18),contadorPorRango(persona,TAM,19,35),contadorPorRango(persona,TAM,36,100));
                printf("\n\n");
                system("pause");
                break;

            case 5: //sale del programa
                printf("\n\n\t *** FIN DEL PROGRAMA ***\t\n\n");
                rta='s';
                break;

        }
        }while(rta=='n');
return 0;
}
