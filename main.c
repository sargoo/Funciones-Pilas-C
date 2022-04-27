#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#include <time.h>
#define ESC 27
#define ANCHO 118

void contarTitulo(char titulo[]);
void cargarPila (Pila*p);
void pasarPila (Pila *p, Pila *p2);
void pasarPilaIgual (Pila *p, Pila *p2);
int encontrarMenor (Pila *p);
void apilarOrdenado(Pila *p);
void insertarElementoEnOrdenada(Pila *p);
void imprimirPila(Pila p);
void cargarPilaRandom(Pila *p, int lim);
void pasarPilaDeMenorAMayor (Pila *p, Pila *p2);
int sumarElementos (Pila p);

void main()
{
    int opcion = 0, ejercicio = 0, topeP, siguienteTope, suma;
    Pila pila, otra, ordenada;
    inicpila(&pila);
    inicpila(&otra);
    srand(time(NULL));
    int limite = rand()%(11-5) + 5;
    int menor = 0;


    while (opcion != ESC)
    {

        imprimirTecho(ANCHO);
        contarTitulo("GUIA PRACTICA 3 - FUNCIONES");
        imprimirTecho(ANCHO);
        contarTitulo("INGRESE EL NUMERO DEL EJERCICIO QUE DESEA EJECUTAR");
        imprimirTecho(ANCHO);
        contarTitulo("1- Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario.");
        imprimirTecho(ANCHO);
        contarTitulo("2- Hacer una funcion que pase todos los elementos de una pila a otra.");
        imprimirTecho(ANCHO);
        contarTitulo("3- Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.");
        imprimirTecho(ANCHO);
        contarTitulo("4- Hacer una funcion que encuentre el menor elemento de una pila y lo retorna.");
        contarTitulo("La misma debe eliminar ese dato de la pila.");
        imprimirTecho(ANCHO);
        contarTitulo("5-Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.");
        contarTitulo("Usar la funcion del ejercicio 4.");
        imprimirTecho(ANCHO);
        contarTitulo("6- Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el orden de esta.");
        imprimirTecho(ANCHO);
        contarTitulo("7- Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.");
        contarTitulo("Usar la función del ejercicio 6.  (Ordenamiento por inserción).");
        imprimirTecho(ANCHO);
        contarTitulo("8- Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior),");
        contarTitulo(" sin alterar su contenido. ");
        imprimirTecho(ANCHO);
        contarTitulo("9- Hacer una funcion que calcule el promedio de los elementos de una pila,");
        contarTitulo("para ello hacer tambien una funcion que calcule la suma, otra para la cuenta y otra que divida.");
        contarTitulo("En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3. ");
        imprimirTecho(ANCHO);
        contarTitulo("10- Hacer una funcion que reciba una pila con numeros de un solo digito,");
        contarTitulo("(es responsabilidad de quien usa el programa) y que transforme esos dígitos en un numero decimal");
        imprimirTecho(ANCHO);
        scanf("%i", &ejercicio);
        system("cls");
        switch(ejercicio)
        {
        case 1:
            contarTitulo("1-Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario. ");
            cargarPila (&pila);
            imprimirPila(pila);
            break;

        case 2:
            contarTitulo("2-Hacer una funcion que pase todos los elementos de una pila a otra. \n");

            cargarPilaRandom(&pila, limite);
            ///int superior = tope(&pila);
            contarTitulo("PILA: ");
            imprimirPila(pila);
            pasarPila (&pila, &otra);
            contarTitulo("OTRA PILA: ");
            imprimirPila(otra);
            pasarPila (&otra, &pila);
            break;

        case 3:
            contarTitulo("3-Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.\n");
            cargarPilaRandom(&pila, limite);
            contarTitulo("PILA: ");
            imprimirPila(pila);
            pasarPilaIgual (&pila, &otra);
            contarTitulo("OTRA: ");
            imprimirPila(pila);
            break;

        case 4:
            contarTitulo("4. Hacer una funcion que encuentre el menor elemento de una pila y lo retorna.");
            contarTitulo("La misma debe eliminar ese dato de la pila.");
            cargarPilaRandom(&pila, limite);
            imprimirPila(pila);
            menor = encontrarMenor (&pila);
            contarTitulo("EL elemento menor de la pila es: ");
            printf("\t\t\t\t\t\t\t%i\n", menor);
            contarTitulo("PILA SIN EL MENOR ELEMENTO: ");
            imprimirPila(pila);

            break;

        case 5:
            contarTitulo("Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por seleccion\n");
            cargarPilaRandom(&pila, limite);
            contarTitulo("PILA ANTES DE LA ORDENACION: ");
            imprimirPila(pila);
            apilarOrdenado(&pila);
            contarTitulo("PILA DESPUES DE LA ORDENACION: ");
            imprimirPila(pila);
            break;

        case 6:
            contarTitulo("6. Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el orden de esta. \n");
            cargarPilaRandom(&pila, limite);
            insertarElementoEnOrdenada(&pila);
            imprimirPila(pila);
            break;

        case 7:
            contarTitulo("7. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.");
            contarTitulo("Usar la función del ejercicio 6.  (Ordenamiento por insercion).");
            cargarPilaRandom(&pila, limite);
            contarTitulo("PILA -PILA-: ");
            imprimirPila(pila);
            pasarPilaDeMenorAMayor (&pila, &otra);
            contarTitulo("PILA -OTRA-: ");
            imprimirPila(otra);
            pasarPila(&otra, &pila);
            break;

        case 8:
            contarTitulo("8- Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior),");
            contarTitulo(" sin alterar su contenido. ");
            cargarPilaRandom(&pila, limite);
            printf("\t\t\t\t\t\tPILA RANDOM: \n");
            printf("\t\t\t\t\t\t");
            imprimirPila(pila);
            suma = sumarElementos (pila);
            printf("\n \t\t\t\t\t\tLA SUMA DE LOS VALORES  es: %i \n", suma);
            break;





        default:
            printf(" EJERCICIO NO DISPONILE.\n");

        }
        printf("QUIERE VER OTRO EJERCICIO?\n");
        printf("CUALQ.TECLA: SI.\n");
        printf("ESC: NO.\n");
        opcion = getch();
        system("cls");
    }
}

void cargarPila (Pila *p)
{
    int valor;
    int corte = 0;

    while (corte != ESC)
    {
        printf("\n Ingrese un numero: \n");
        scanf("%i",&valor);
        apilar(p, valor);
        printf(" Desea seguir ingresando datos?\n Si: Cualquier tecla. \n No: ESC.");
        corte = getch();
        system("cls");
    }
}

void imprimirPila(Pila p)
{
    int superior = 0;
    Pila aux;
    inicpila(&aux);
    pasarPila(&p, &aux);
    while(!pilavacia(&aux))
    {
        superior = tope(&aux);
        printf("|%i|", superior);
        apilar(&p, desapilar(&aux));
    }
    printf("\n");
}

void pasarPila (Pila *p, Pila *p2)
{
    while(!pilavacia(p))
    {
        apilar(p2, desapilar(p));
    }
}

void pasarPilaIgual (Pila *p, Pila *p2)
{
    pasarPila (p, p2);
    pasarPila (p2, p);

}

int encontrarMenor (Pila *p)
{
    Pila aux, menor;
    inicpila(&menor);
    inicpila(&aux);
    int valor;

    if(!pilavacia(p))
    {
        apilar(&menor, desapilar(p));
        while(!pilavacia(p))
        {
            if(tope(p) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(p));
            }
            else
            {
                apilar(&aux, desapilar(p));
            }
        }

    }
    if(!pilavacia(&menor))
    {
        valor = tope(&menor);

    }
    while (!pilavacia(&aux))
    {
        apilar(p, desapilar(&aux));
    }

    return valor;

}

void apilarOrdenado(Pila *p)

{
    Pila aux, menor;
    inicpila(&menor);
    inicpila(&aux);

    while(!pilavacia(p))
    {
        apilar(&menor, desapilar(p));
        while(!pilavacia(p))
        {
            if(tope(p) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(p));
            }
            else
            {
                apilar(&aux, desapilar(p));
            }
        }

        if(pilavacia(p))
        {
            pasarPila(&aux, p);
        }
    }
    pasarPila(&menor, &aux);
    pasarPila(&aux, p);
}



void contarTitulo(char titulo[])
{
    int anchoTotal = 118;
    char* largo = titulo;
    int contador = 0;
    while (largo[contador] != 0)
    {
        contador ++;
    }
    int espacio = anchoTotal - contador;

    printf("||");
    for(int i = 0; i < anchoTotal-4; i++)
    {
        printf(" ");
    }
    printf("||");
    printf("\n");
    printf("||");
    for(int i = 0; i < (espacio/2)-2; i++)
    {
        printf(" ");
    }

    printf("%s", titulo);


    if(espacio % 2 != 0)
    {
        for(int i = 0; i < (espacio/2)-1; i++)
        {
            printf(" ");
        }
    }
    else
    {
        for(int i = 0; i < (espacio/2)-2; i++)
        {
            printf(" ");
        }

    }

    printf("||");
    printf("\n");
    printf("||");
    for(int i = 0; i < anchoTotal-4; i++)
    {
        printf(" ");
    }
    printf("||");
    printf("\n");
}

void imprimirTecho(int longitud)
{

    for(int i = 0; i < longitud; i++)
    {
        printf("=");
    }
    printf("\n");
}




void insertarElementoEnOrdenada(Pila *p)
{
    int valor;

    printf("\n Ingrese un numero: \n");
    scanf("%i",&valor);
    apilar(p, valor);
    apilarOrdenado(p);
}

void cargarPilaRandom(Pila *p, int lim)
{
    if(pilavacia(p))
    {
        for(int i = 0; i < lim; i ++)
        {
            apilar(p, rand()%(11-2) + 2);
        }
    }
}

void pasarPilaDeMenorAMayor (Pila *p, Pila *p2)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(p,p2);
    apilarOrdenado(p2);
}

int sumarElementos (Pila p)
{
    int total = 0,valor1 = 0, valor2 = 0;
    Pila aux;
    inicpila(&aux);

    if(!pilavacia(&p))
    {
        valor1 = tope(&p);
        apilar(&aux, desapilar(&p));

        if(!pilavacia(&p))
        {
            valor2 = tope(&p);
            apilar(&aux, desapilar(&p));
        }
        total = valor1 + valor2;
    }
    return total;
}


