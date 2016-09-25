#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

/** \brief Inicializa del estado de una persona (0 para vacio, 1 para lleno)
 *
 * \param persona - persona a ser cargada
 * \param tam - tamaño de la estructura (20)
 * \return no retorna; solamente inicia el estado de la persona
 *
 */
void initEstado(ePersona* persona, int tam)
{
    int i;

    if(tam>0 && persona != NULL)
    {
        for(i=0;i<tam;i++)
        {
            persona[i].estado=0;
        }
    }
}


/** \brief Busca el primer estado vacio de una persona en la estructura, siendo 0 para vacio y 1 para lleno.
 * \param persona - persona a ser cargada
 * \param tam - tamaño de la estructura (20)
 * \return retorna un valor de entero que sirve para indicar el indice de la primera posicion vacia del array. Devuelve -1 si esta lleno
 */
int primerVacio(ePersona* persona, int tam)
{
    int i;
    int completo=-1;

    if(tam>0 && persona != NULL)
    {
        for(i=0;i<tam;i++)
        {
            if(persona[i].estado==0)
            {
                completo=i;
                break;
            }
        }
        if(completo==-1)
            printf("\nERROR! Base de datos completa. No se puede agregar mas personas.\n");
    }
    return completo;
}

/** \brief Solicita al usuario los datos a ingresar en cada campo de la estructura en la posicion indicada
 *
 * \param ePersona* persona - la posicion de memoria inicial del array
 * \param int i - Indice de la posicion del array donde se cargaran todos los datos
 * \param int tam - Tamaño del array de estructuras
 * \return void
 *
 */
void agregarPersona(ePersona* persona, int i, int tam)
{
    int auxDni;
    int edad;
    int dniOk=0;
    int dniValido;

    if(tam>0 && persona != NULL)
    {

    while(dniOk==0)
    {
        do{
        dniValido=rangoNroDni(&auxDni,"\nIngrese el DNI: ","\nERROR! El numero ingresado no es un DNI valido.\n",1000000,99999999);
        }while(dniValido==-1);

        if(buscaDni(persona, tam, auxDni)==0)
        {
            persona[i].dni=auxDni;
            persona[i].estado=1;
            dniOk=1;
        }
        else
        {
            printf("\nERROR!");
            printf("\nEl DNI ingresado se encuentra en la base de datos\n");
            persona[i].estado=0;
            system("pause");
            break;
        }

    formatoApellido(persona,i);

    do{
    dniValido=rangoNroDni(&edad,"\nIngrese la edad: ","\nERROR! Ingrese una edad valida: \n",1,100);
    }while(dniValido==-1);
    persona[i].edad=edad;
    }
    }
}


/** \brief "borra" una persona de la base de datos (baja logica: cambia su estado a 0)
 *
 * \param ePersona* persona - la posicion de memoria inicial del array
 * \param int tam - Tamaño del array de estructuras
 * \return void
 *
 */
void borrarPersona(ePersona* persona, int tam)
{
    int i;
    int dni;
    int dniValido;
    int flag=0;

    if(tam>0 && persona != NULL)
    {
        do{
        dniValido=rangoNroDni(&dni,"\nIngrese el DNI de la persona a borrar: ","ERROR! El numero ingresado no es un DNI valido. Favor reingresar: \n",1000000,99999999);
        }while(dniValido==-1);

        for(i=0;i<tam;i++)
            {
                if(persona[i].dni==dni)
                {
                    if(persona[i].estado==1)
                    {
                        persona[i].estado=0;
                        printf("\nBaja efectuada con suceso! El DNI fue borrado exitosamente\n");
                        flag=1;
                    }
                }
            }
            if(flag==0)
            {
                printf("\n ERROR! El DNI ingresado no existe.\n");
            }
    }
}


/** \brief ordena los nombres de la base de datos (swap)
 *
 *
 * \param ePersona* persona - la posicion de memoria inicial del array.
 * \param int tam -  Tamaño del array de estructuras.
 * \return retorna -1 (si hay algun error) o 0 (si no hay errores)
 *
 */
int ordenarNombres(ePersona* persona, int tam)
{
    ePersona aux;
    int i;
    int j;
    int resultado=-1;

    if(tam>0 && persona != NULL)
    {
        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                    aux=persona[i];
                    persona[i]=persona[j];
                    persona[j]=aux;
                }
            }
        }
        resultado=0;
    }
    return resultado;
}


/** \brief Genera un grafico de barras, donde el eje marca la cantidad de personas pertenecientes a un grupo,  detallado en eje x.
 *
 * \param contMenor int - primer grupo de edades pertenecientes al rango <18
 * \param contInter int - segundo grupo de edades pertenecientes al rango 19-35
 * \param contMayor int - tercer grupo de edades pertenecientes al rango >35
 *
 */
void graficoNombres(int contMenor, int contInter, int contMayor)
{
    int i;
    int max;
    char espacio=' ';
    char asterix='*';
    char printMenor;
    int printInter;
    int printMayor;

    if(contMenor>=contInter && contMenor>=contMayor)
    {
        max=contMenor;
    }
    else
    {
        if(contInter>=contMenor && contInter>=contMayor)
        {
            max=contInter;
        }
        else
        {
            max=contMayor;
        }
    }

    for(i=max;i>=1;i--)
    {
        if(contMenor>=i)
            {
                printMenor=asterix;

            }
        else
            {
                printMenor=espacio;
            }

        if(contInter>=i)
            {
                printInter=asterix;
            }
        else
            {
                printInter=espacio;
            }

        if(contMayor>=i)
            {
                printMayor=asterix;
            }
        else
            {
                printMayor=espacio;
            }
        printf("%02d\t%c\t%c\t%c\t\n",i, printMenor, printInter, printMayor);
    }

        printf("\n       <18    19-35    >35\n\n");
}

/** \brief recorre la edad de las personas de la estructura y cuenta el nro de veces en que hay un entero dentro de un rango especifico
 *
 * \param ePersona* persona - la posicion de memoria inicial del array
 * \param int tam - Tamaño del array de estructuras.
 * \param int RangoMin - limite inferior del rango incluyendolo
 * \param int RangoMax - limite superior del rango incluyendolo
 * \return retorna -1 en caso de error
 *
 */
int contadorPorRango(ePersona* persona, int tam, int RangoMin, int RangoMax)
{
    int i;
    int cont=0;

    if(tam>0)
    {
        for(i=0;i<tam;i++)
        {
            if(persona[i].estado==1 && (persona[i].edad>=RangoMin && persona[i].edad<=RangoMax))
            {
                cont++;
            }
        }
    }
    return cont;
}


/** \brief  imprime por pantalla todas las personas cargadas en el array de estructuras
 *
 * \param ePersona* persona - la posicion de memoria inicial del array
 * \param int tam - tamaño del array de estructuras
 * \return void
 *
 */
void imprimirPersonas(ePersona* persona, int tam)
{
    int i;

        printf("\n");
        printf("\nDNI         Edad    Nombre Completo          ");
        printf("\n---         ----    ---------------          \n");

    if(tam>0 && persona != NULL)
    {
        for(i=0;i<tam;i++)
        {
            if(persona[i].estado==1)
            {
                /*printf("\n");
                printf("\n\tDNI         Nombre Completo          Edad");
                printf("\n\t---         ---------------          ----\n");*/
                printf("\n%d     %d     %s", persona[i].dni, persona[i].edad, persona[i].nombre);
                printf("");
            }
        }
    }
}


/** \brief pide un nro (int) de DNI al usuario y lo valida dentro de un rango especificado
 * \param input int* - la dir de memoria de la variable a validar
 * \param mensajePedido[] - mensaje pidiendo nro de DNI
 * \param mensajeError[] - mensaje de error
 * \param int RangoMin - minimo nro posible de DNI
 * \param int RangoMax - max nro posible de DNI
 * \return retorna un entero: 0 si el numero es valido, -1 si no es valido
 *
 */
int rangoNroDni(int* input, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax)
{
    int retorno=0;
    int validoScanf;
    int valor;
    puts(mensajePedido);
    fflush(stdin);
    validoScanf=scanf("%d",&valor); ///valida retorno de scanf si ingreso tipo de dato correcto o no de acuerdo a la mascara

    if((validoScanf!=1) || (!(valor>=RangoMin && valor<=RangoMax)))
    {
        puts(mensajeError);
        retorno=-1;
    }
    else
    {
        *input=valor;
    }
    return retorno;
}


/** \brief Solicita al usuario nombre y apellido, luego lo acomoda a la forma Apellido, Nombre
 *          Soporta nombre y apellido de 50 caracteres contando espacio y coma.
 *
 * \param ePersona* persona - la posicion de memoria inicial del array
 * \param j int indice del array de estructuras donde cargar la cadena en el campo persona[j].nombre.
 * \return void
 *
 */
void formatoApellido(ePersona* persona, int j)
{
    int i;
    int auxCad;
    char nombre[20];
    char apellido[28];
    char auxCaptura[250];
    char auxiliar[50];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCaptura);

    for(i=0; auxCaptura[i]!= '\0'; i++)
    {
        if(isalpha(auxCaptura[i])==0) //isalpha - checkea si el caracter es alfabetico
        {
            auxCad=0;
        }
        else
        {
            auxCad=1;
        }
    }

    while((strlen(auxCaptura)>20) || auxCad==0)
    {
        printf("ERROR!!! El nombre debe tener un maximo de 20 letras.\n");
        printf("Reingrese nombre: ");
        fflush(stdin);
        gets(auxCaptura);
            for(i=0; auxCaptura[i]!= '\0'; i++)
            {
                if(isalpha(auxCaptura[i])==0)
                {
                    auxCad=0;
                }
                else
                {
                    auxCad=1;
                }
            }
    }
    strcpy(nombre,auxCaptura);

    printf("\nIngrese apellido: ");
    fflush(stdin);
    gets(auxCaptura);

    for(i=0; auxCaptura[i]!= '\0'; i++)
    {
        if(isalpha(auxCaptura[i])==0)
        {
            auxCad=0;
        }
        else
        {
            auxCad=1;
        }
    }

    while(strlen(auxCaptura)>28 || auxCad==0)
    {
        printf("ERROR! El apellido debe tener un maximo de 28 letras. Reingrese el apellido: \n");
        fflush(stdin);
        gets(auxCaptura);
        for(i=0; auxCaptura[i]!= '\0'; i++)
        {
            if(isalpha(auxCaptura[i])==0)
            {
                auxCad=0;
            }
            else
            {
                auxCad=1;
            }
        }
    }
    strcpy(apellido,auxCaptura);
    strcpy(auxiliar, apellido);
    strcat(auxiliar, ", ");
    strcat(auxiliar, nombre);

    strlwr(auxiliar);

    auxiliar[0] = toupper(auxiliar[0]);

    for(i=0; auxiliar[i]!= '\0'; i++)
    {
        if(auxiliar[i] == ' ')
        {
            auxiliar[i+1] = toupper(auxiliar[i+1]);
        }
    }
    strcpy(persona[j].nombre,auxiliar);
}

/** \brief busca un nro de DNI y verifica si el mismo ya esta en uso
 *
 * \param ePersona* persona - la posicion de memoria inicial del array
 * \param int tam - Tamaño del array de estructuras
 * \param int dni - numero de DNI a chequear si esta en uso
 * \return retorna 0 si no esta en uso y 1 si ya existe
 *
 */
int buscaDni(ePersona* persona, int tam, int dni)
{
    int i, retorno=0;

    if(tam>0&&persona!=NULL)
    {
        for(i=0;i<tam;i++)
        {
            if(persona[i].dni==dni && persona[i].estado==1)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
