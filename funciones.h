#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char nombre[50];
    int edad;
    int estado;
    int dni;
}ePersona;

void initEstado(ePersona* unaPersona, int tam);
int primerVacio(ePersona* persona, int tam);
void agregarPersona(ePersona* persona, int i, int tam);
void borrarPersona(ePersona* persona, int tam);
int ordenarNombres(ePersona* persona, int tam);
void graficoNombres(int cont1, int cont2, int cont3);
int contadorPorRango(ePersona* persona, int tam, int RangoMin, int RangoMax );
void imprimirPersonas(ePersona* persona, int tam);
int rangoNroDni(int* input, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax);
void formatoApellido(ePersona* persona,int i);


#endif // FUNCIONES_H_INCLUDED
