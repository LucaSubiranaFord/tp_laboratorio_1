#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float primerOperando;
    float segundoOperando;
    int flagOperando1 = 0;
    int flagOperando2 = 0;
    int flagDivisor = 0;
    float operandoMenu = 0;
    float operandoMenu2 = 0;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=%f)\n", operandoMenu);
        printf("2- Ingresar 2do operando (B=%f)\n", operandoMenu2);
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
            operandoMenu = primerOperando;
            flagOperando1 = 1;
            break;
        case 2:
            segundoOperando = ingresoFloat2();
            operandoMenu2 = segundoOperando;
            flagOperando2 = 1;
            break;
        case 3:
           suma(primerOperando, segundoOperando,flagOperando1, flagOperando2);
            break;
        case 4:
            resta(primerOperando, segundoOperando,flagOperando1, flagOperando2);
            break;
        case 5:
             dividir(primerOperando, segundoOperando,flagOperando1, flagOperando2);
            break;
        case 6:
          multiplicar(primerOperando, segundoOperando,flagOperando1, flagOperando2);
            break;
        case 7:
            factorial(primerOperando, segundoOperando, flagOperando1, flagOperando2);
            break;
        case 8:
           mostrarOperaciones(primerOperando, segundoOperando, flagOperando1, flagOperando2, flagDivisor);
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }

    return 0;
}

