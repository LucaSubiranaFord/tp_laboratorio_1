#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float, float);
float resta(float, float);
float multiplicar(float, float);
float dividir(float, float);
float factorial(float, float, int, int);
float ingresoFloat1();
float ingresoFloat2();
mostrarOperaciones(float, float, int, int, int);

int main()
{
    char seguir='s';
    int opcion=0;
    float primerOperando;
    float segundoOperando;
    int flagOperando1 = 0;
    int flagOperando2 = 0;
    int flagDivisor = 0;

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
            flagOperando1 = 1;
            break;
        case 2:
            segundoOperando = ingresoFloat2();
            flagOperando2 = 1;
            if (segundoOperando != 0)
            {
                flagDivisor = 1;
            }
            else
            {
                flagDivisor = 0;
            }
            break;
        case 3:
            if (flagOperando1 == 1 && flagOperando2 == 1)
            {
                printf("\nLa suma entre %f y %f, es: %f\n",primerOperando, segundoOperando, suma(primerOperando, segundoOperando));
            }
            else
            {
                printf("Debe ingresar ambos operandos para poder realizar esta accion");
            }
            break;
        case 4:
            if (flagOperando1 == 1 && flagOperando2 == 1)
            {
                printf("\nLa resta entre %f y %f es: %f\n", primerOperando, segundoOperando, resta(primerOperando, segundoOperando));
            }
            else
            {
                printf("Debe ingresar ambos operandos para poder realizar esta accion");
            }
            break;
        case 5:
            if (flagOperando1 == 1 && flagOperando2 == 1)
            {
                if(flagDivisor == 1)
                {
                    printf("\nLa division entre %f y %f es: %f\n", primerOperando, segundoOperando, dividir(primerOperando, segundoOperando));
                }
                else
                {
                    printf("\nEl dividendo tiene que ser distinto de 0\n");
                }
            }
            else
            {
                printf("Debe ingresar ambos operandos para poder realizar esta accion");
            }
            break;
        case 6:
            if (flagOperando1 == 1 && flagOperando2 == 1)
            {
                printf("\nLa multiplicacion entre %f y %f es: %f\n", primerOperando, segundoOperando, multiplicar(primerOperando, segundoOperando));
            }
            else
            {
                printf("Debe ingresar ambos operandos para poder realizar esta accion");
            }

            break;
        case 7:
            if (flagOperando1 == 1 || flagOperando2 == 1)
            {
                printf("\nEl factorial es: %f\n", factorial(primerOperando, segundoOperando, flagOperando1, flagOperando2));
            }
            else
            {
                printf("Debe ingresar ambos operandos para poder realizar esta accion");
            }
            break;
        case 8:
            if (flagOperando1 == 1 && flagOperando2 == 1)
            {
                mostrarOperaciones(primerOperando, segundoOperando, flagOperando1, flagOperando2, flagDivisor);
            }
            else
            {
                printf("Debe ingresar ambos operandos para poder realizar esta accion");
            }

            break;
        case 9:
            seguir = 'n';
            break;
        }
    }

    return 0;
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

mostrarOperaciones(float primerOperando, float segundoOperando, int flagOperando1, int flagOperando2, int flagDivisor)
{
    printf("\nLa suma entre %f y %f, es: %f\n",primerOperando, segundoOperando, suma(primerOperando, segundoOperando));
    printf("\nLa resta entre %f y %f es: %f\n", primerOperando, segundoOperando, resta(primerOperando, segundoOperando));
    if(flagDivisor == 1)
    {
        printf("\nLa division entre %f y %f es: %f\n", primerOperando, segundoOperando, dividir(primerOperando, segundoOperando));
    }else
    {
        printf("\nEl dividendo tiene que ser distinto de 0\n");
    }

    printf("\nLa multiplicacion entre %f y %f es: %f\n", primerOperando, segundoOperando, multiplicar(primerOperando, segundoOperando));
    printf("\nEl factorial es: %f\n", factorial(primerOperando, segundoOperando, flagOperando1, flagOperando2));
}

float factorial(float x, float y, int flagOperando1, int flagOperando2)
{
    int eleccion;
    int z;
    int factorial = 1;

    if(flagOperando1 == 1 && flagOperando2 == 1)
    {
         do
    {
        printf("\nElija con que operando ya introducido desea realizar esta accion. Para elegir el primero ingrese 1, para elegir el segundo ingrese 2: ");
        scanf("%d",&eleccion);
    }
        while(eleccion != 1 && eleccion != 2);

        if(eleccion == 1)
    {
        for(z=x; z>1; z--)
        {
            factorial = factorial * z;
        }

        return factorial;
    }
    else
    {
        for(z=y; z>1; z--)
        {
            factorial = factorial * z;
        }

        return factorial;
    }

    }else if(flagOperando1 == 1 && flagOperando2 == 0)
    {
        for(z=x; z>1; z--)
        {
            factorial = factorial * z;
        }

        return factorial;
    }else if(flagOperando1 == 0 && flagOperando2 == 1)
    {
        for(z=y; z>1; z--)
        {
            factorial = factorial * z;
        }

        return factorial;
    }



}


