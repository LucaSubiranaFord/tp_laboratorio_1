#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float , float);
float resta(float, float);
float multiplicar(float, float);
float dividir(float, float);
float factorial(float, float);
float ingresoFloat1();
float ingresoFloat2();
mostrarOperaciones(float, float);


int main()
{
    char seguir='s';
    int opcion=0;
    float primerOperando;
    float segundoOperando;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                primerOperando = ingresoFloat1();
                break;
            case 2:
                segundoOperando = ingresoFloat2();
                break;
            case 3:
                printf("\nLa suma entre %f y %f, es: %f\n",primerOperando, segundoOperando, suma(primerOperando, segundoOperando));
                break;
            case 4:
                printf("\nLa resta entre %f y %f es: %f\n", primerOperando, segundoOperando, resta(primerOperando, segundoOperando));
                break;
            case 5:
                printf("\nLa division entre %f y %f es: %f\n", primerOperando, segundoOperando, dividir(primerOperando, segundoOperando));
                break;
            case 6:
                printf("\nLa multiplicacion entre %f y %f es: %f\n", primerOperando, segundoOperando, multiplicar(primerOperando, segundoOperando));
                break;
            case 7:
                printf("\n%f\n", factorial(primerOperando, segundoOperando));
                break;
            case 8:
                mostrarOperaciones(primerOperando, segundoOperando);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

float suma(float x, float y)
{
    float resultado = x+y;
    return resultado;
}

float resta(float x, float y)
{
    float resultado = x-y;
    return resultado;
}

float multiplicar(float x, float y)
{
    float resultado = x*y;
    return resultado;
}

float dividir(float x, float y)
{
    float resultado = x/y;
    return resultado;
}



float ingresoFloat1()
{
    float x;
    printf("\nIngrese el primer operando: ");
    scanf("%f", &x);

    return x;

}

float ingresoFloat2()
{
    float x;
    printf("\nIngrese el segundo operando: ");
    scanf("%f", &x);
    return x;

}

mostrarOperaciones(float primerOperando, float segundoOperando)
{
    printf("\nLa suma entre %f y %f, es: %f\n",primerOperando, segundoOperando, suma(primerOperando, segundoOperando));
     printf("\nLa resta entre %f y %f es: %f\n", primerOperando, segundoOperando, resta(primerOperando, segundoOperando));
     printf("\nLa division entre %f y %f es: %f\n", primerOperando, segundoOperando, dividir(primerOperando, segundoOperando));
     printf("\nLa multiplicacion entre %f y %f es: %f\n", primerOperando, segundoOperando, multiplicar(primerOperando, segundoOperando));
}

float factorial(float x, float y)
{
    int z;
    int factorial = 1;

    for(z=x; z>1; z--)
    {
        factorial = factorial * z;
    }

return factorial;

}


