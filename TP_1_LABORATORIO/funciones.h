#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float ingresoFloat1();
float ingresoFloat2();
float suma(float, float);
float resta(float, float);
float multiplicar(float, float);
dividir(float, float);
float factorial(float, float, int, int);
verificacionIngreso(float, float, float);
float mostrarOperaciones(float, float, int, int, int);


/** \brief Ingreso del primer parametro
 *
 *\return numero ingresado (float)
 *
 */
float ingresoFloat1()
{
    float x;
    printf("\nIngrese el primer operando: ");
    scanf("%f", &x);
    return x;
}



/** \brief Ingreso del segundo parametro
 *
 *\return numero ingresado (float)
 *
 */
float ingresoFloat2()
{
    float x;
    printf("\nIngrese el segundo operando: ");
    scanf("%f", &x);
    return x;
}



/** \brief suma dos numeros
 *
 * \param el primer numero a sumar (float x)
 * \param el segundo numero a sumar (float y)
 * \return resultado de la suma (float)
 *
 */
float suma(float x, float y)
{
    float resultado = x+y;
    return resultado;
}



/** \brief resta dos numeros
 *
 * \param el primer numero a restar (float x)
 * \param el segundo numero a restar(float y)
 * \return resultado de la resta (float)
 *
 */
float resta(float x, float y)
{
    float resultado = x-y;
    return resultado;
}



/** \brief multiplica dos numeros
 *
 * \param el primer numero a multiplicar (float x)
 * \param el segundo numero a multiplicar (float y)
 * \return resultado de la multiplicacion (float)
 *
 */
float multiplicar(float x, float y)
{
    float resultado = x*y;
    return resultado;
}



/** \brief divide dos numeros
 *
 * \param el primer numero a dividir (float x)
 * \param el segundo numero a dividir (float y)
 * \return resultado de la division(float)
 *
 */
dividir(float x, float y)
{
    float resultado = x/y;
    if(y != 0)
    {
        printf("La division entre %f y %f, es : %f",x,y,resultado);
    }else
    {
        printf("El divisor debe ser distinto de 0");
    }

}



/** \brief verifica que se hayan ingresado ambos operandos.
 *
 * \param bandera que afirma que el primer numero fue ingresado (int x)
 * \param bandera que afirma que el segundo numero fue ingresado (int y)
 * \param la funcion a realizar (float z)
 *
 */
verificacion(float x, float y, float z)
{
    if( x == 1 && y == 1)
    {
        printf("\n%f\n", z);
    }
    else
    {
        char mensaje[] = "Debe ingresar ambos operandos para realizar esta accion";
        printf("\n%s\n", mensaje);

    }
}




/** \brief muestra todas las operaciones (suma, resta, division, multiplicacion, factorial)
 *
 * \param el primer numero ingresado por el usuario (float primerOperando)
 * \param el segundo numero ingresado por el usuario (float segundoOperando)
* \param bandera que afirma que el primer numero fue ingresado (int flagOperando1)
 * \param bandera que afirma que el segundo numero fue ingresado (int flagOperando2)
 * \param bandera que afirma que el segundo numero ingresado es distinto de 0 (int flagDivisor)
 *
 */
float mostrarOperaciones(float primerOperando, float segundoOperando, int flagOperando1, int flagOperando2, int flagDivisor)
{
    if(flagOperando1 == 1 && flagOperando2 == 1)
    {
        verificacion(flagOperando1, flagOperando2, suma(primerOperando, segundoOperando));
        verificacion(flagOperando1, flagOperando2, resta(primerOperando, segundoOperando));
        verificacion(flagOperando1, flagOperando2, dividir(primerOperando, segundoOperando));
        verificacion(flagOperando1, flagOperando2, multiplicar(primerOperando, segundoOperando));
        verificacion(flagOperando1, flagOperando2, factorial(primerOperando, segundoOperando, flagOperando1, flagOperando2));
    }
    else
    {
        printf("Debe ingresar ambos operandos para poder realizar esta accion");
        return 0;
    }

}



/** \brief realiza el factorial del numero elegido, ya ingresado previamente. Si se ingreso uno solo, se muestra ese mismo.
 *
 * \param el primer numero ingresado por el usuario (float x)
 * \param el segundo numero ingresado por el usuario (float y)
 * \param bandera que afirma que el primer numero fue ingresado (int flagOperando1)
 * \param bandera que afirma que el segundo numero fue ingresado (int flagOperando2)

 * \return resultado del factorial(float factorial)
 *
 */

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

    }
    else if(flagOperando1 == 1 && flagOperando2 == 0)
    {
        for(z=x; z>1; z--)
        {
            factorial = factorial * z;
        }

        return factorial;
    }
    else if(flagOperando1 == 0 && flagOperando2 == 1)
    {
        for(z=y; z>1; z--)
        {
            factorial = factorial * z;
        }

        return factorial;
    }



}
#endif // FUNCIONES_H_INCLUDED
