#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float ingresoFloat1();
float ingresoFloat2();
suma(float, float, int, int);
resta(float, float, int, int);
multiplicar(float, float, int, int);
dividir(float, float, int, int);
factorial(float, float, int, int);
float mostrarOperaciones(float, float, int, int, int);


/** \brief Ingreso del primer parametro
 *
 *\return numero ingresado (float)
 *
 */
float ingresoFloat1()
{
    float x;
    printf("\nIngrese el primer operando: \n");
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
    printf("\nIngrese el segundo operando: \n");
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
suma(float x, float y, int z, int w)
{
    float resultado = x+y;
    if(z == 1 && w == 1)
    {

        printf("\nLa suma entre %f y %f, es : %f\n",x,y,resultado);
    }else
    {
        printf("\nDebe ingresar ambos operandos para realizar la suma\n");
    }

}



/** \brief resta dos numeros
 *
 * \param el primer numero a restar (float x)
 * \param el segundo numero a restar(float y)
 * \return resultado de la resta (float)
 *
 */
resta(float x, float y, int z, int w)
{
    float resultado = x-y;
    if(z == 1 && w == 1)
    {
        printf("\nLa resta entre %f y %f, es : %f\n",x,y,resultado);
    }else
    {
        printf("\nDebe ingresar ambos operandos para realizar la resta\n");
    }

}



/** \brief multiplica dos numeros
 *
 * \param el primer numero a multiplicar (float x)
 * \param el segundo numero a multiplicar (float y)
 * \return resultado de la multiplicacion (float)
 *
 */
multiplicar(float x, float y, int z, int w)
{
    float resultado = x*y;
    if(z == 1 && w == 1)
    {
    printf("\nLa multiplicacion entre %f y %f, es : %f\n",x,y,resultado);
    }else
    {
        printf("\nDebe ingresar ambos operandos para realizar la multiplicacion\n");
    }

}



/** \brief divide dos numeros
 *
 * \param el primer numero a dividir (float x)
 * \param el segundo numero a dividir (float y)
 * \return resultado de la division(float)
 *
 */
dividir(float x, float y, int z, int w)
{
    float resultado = x/y;

    if(z == 1 && w == 1)
    {

    if(y != 0)
    {
    printf("\nLa division entre %f y %f, es : %f\n",x,y,resultado);

    }else
    {
      printf("\nEl divisor debe ser distinto de 0\n");
    }


    }else
    {
        printf("\nDebe ingresar ambos operandos para realizar la suma\n");
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
        suma(primerOperando, segundoOperando,flagOperando1, flagOperando2);
        resta(primerOperando, segundoOperando,flagOperando1, flagOperando2);
        dividir(primerOperando, segundoOperando,flagOperando1, flagOperando2);
        multiplicar(primerOperando, segundoOperando,flagOperando1, flagOperando2);
        factorial(primerOperando, segundoOperando, flagOperando1, flagOperando2);
    }
    else
    {
        printf("\nDebe ingresar ambos operandos para poder mostrar todas las operaciones\n");
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

factorial(float x, float y, int flagOperando1, int flagOperando2)
{
    int eleccion;
    int z;
    int factorial = 1;

    if(flagOperando1 == 1 && flagOperando2 == 1)
    {
        do
        {
            printf("\nElija con que operando ya introducido desea realizar esta accion. Para elegir el primero ingrese 1, para elegir el segundo ingrese 2: \n");
            scanf("%d",&eleccion);
        }
        while(eleccion != 1 && eleccion != 2);

        if(eleccion == 1)
        {
            for(z=x; z>1; z--)
            {
                factorial = factorial * z;
            }

            printf("\nel factorial de %f, es: %f\n", x, factorial);
        }
        else
        {
            for(z=y; z>1; z--)
            {
                factorial = factorial * z;
            }

            printf("\nel factorial de %f, es: %f\n", y, factorial);
        }

    }
    else if(flagOperando1 == 1 && flagOperando2 == 0)
    {
        for(z=x; z>1; z--)
        {
            factorial = factorial * z;
        }

        printf("\nel factorial de %f, es: %f\n", x, factorial);
    }
    else if(flagOperando1 == 0 && flagOperando2 == 1)
    {
        for(z=y; z>1; z--)
        {
            factorial = factorial * z;
        }

        printf("\nel factorial de %f, es: %f\n", y, factorial);
    }



}
#endif // FUNCIONES_H_INCLUDED
