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

void main()
{
    int opcion = 0, ejercicio = 0;
    Pila pila, otra, ordenada;
    inicpila(&pila);
    inicpila(&otra);
    inicpila(&ordenada);
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
        contarTitulo("1-Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario.");
        imprimirTecho(ANCHO);
        contarTitulo("2-Hacer una funcion que pase todos los elementos de una pila a otra.");
        imprimirTecho(ANCHO);
        contarTitulo("3-Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.");
        imprimirTecho(ANCHO);
        contarTitulo("4-Hacer una funcion que encuentre el menor elemento de una pila y lo retorna.");
        contarTitulo("La misma debe eliminar ese dato de la pila.");
        imprimirTecho(ANCHO);
        contarTitulo("5-Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.");
        contarTitulo("Usar la funci�n del ejercicio 4.");
        imprimirTecho(ANCHO);
        contarTitulo("6. Hacer una funci�n que inserta en una pila ordenada un nuevo elemento, conservando el orden de �sta.");
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
            printf("2-Hacer una funcion que pase todos los elementos de una pila a otra. \n");

            cargarPilaRandom(&pila, limite);
            ///int superior = tope(&pila);
            printf("PILA");
            imprimirPila(pila);
            pasarPila (&pila, &otra);
            printf("OTRA PILA");
            imprimirPila(otra);
            pasarPila (&otra, &pila);
            break;

        case 3:
            printf("3-Hacer una funci�n que pase todos los elementos de una pila a otra, pero conservando el orden.\n");
            cargarPilaRandom(&pila, limite);
            printf("PILA");
            imprimirPila(pila);
            pasarPilaIgual (&pila, &otra);
            printf("OTRA");
            imprimirPila(pila);
            break;

        case 4:
            printf("4. Hacer una funci�n que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.\n");
            cargarPilaRandom(&pila, limite);
            imprimirPila(pila);
            menor = encontrarMenor (&pila);
            printf("\n\nEL elemento menor de la pila es: %i\n\n", menor);
            printf("PILA SIN EL MENOR ELEMENTO: \n");
            imprimirPila(pila);

            break;

        case 5:
            printf("Hacer una funci�n que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funci�n del ejercicio 4. (Ordenamiento por selecci�n\n");
            cargarPilaRandom(&pila, limite);
            printf("PILA ANTES DE LA ORDENACION\n");
            imprimirPila(pila);
            apilarOrdenado(&pila);
            printf("PILA DESPUES DE LA ORDENACION\n");
            imprimirPila(pila);
            break;

        case 6:
            printf("6. Hacer una funci�n que inserta en una pila ordenada un nuevo elemento, conservando el orden de �sta. \n");
            cargarPilaRandom(&pila, limite);
            insertarElementoEnOrdenada(&pila);
            imprimirPila(pila);

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
    //printf("\n");
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




