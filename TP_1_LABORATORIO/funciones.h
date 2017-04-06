#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float ingresoFloat1();
float ingresoFloat2();
float suma(float, float);
float resta(float, float);
float multiplicar(float, float);
float dividir(float, float, int);
factorial(float, float, int);
verificacionIngreso(float, float, float);
int verificacionDivisor(float);
mostrarOperaciones(float, float, int, int, int);




/** \brief Ingreso del primer parametro
 *
 *\return numero ingresado (float)
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
float dividir(float x, float y, int z)
{
    float resultado = x/y;
    return resultado;
}



 /** \brief Verifica si el segundo operando es distinto de 0
  *
  * \param Segundo operando (float x)
  * \return Devuelve 1 si el valor es distinto de 0(int)
  * \return Devuelve 0 si el valor es igual a 0(int)
  */

 int verificacionDivisor(float x)
{
        if (x != 0)
        {
            return 1;
        }else
        {
            return 0;
        }
}

/** \brief verifica que se hayan ingresado ambos operandos.
 *
 * \param bandera que verifica que el primer numero fue ingresado (int x)
 * \param bandera que verifica que el segundo numero fue ingresado (int y)
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

        printf("\nDebe ingresar ambos operandos para poder realizar esta accion\n");

    }
}



/** \brief muestra todas las operaciones (suma, resta, division, multiplicacion, factorial)
 *
 * \param el primer numero ingresado por el usuario (float primerOperando)
 * \param el segundo numero ingresado por el usuario (float segundoOperando)
* \param bandera que afirma que el primer numero fue ingresado (int flagOperando1)
 * \param bandera que afirma que el segundo numero fue ingresado (int flagOperando2)
 * \param bandera que afirma que el segundo numero ingresado es distinto de 0 (int flagDivisor0)
 *
 */
mostrarOperaciones(float primerOperando, float segundoOperando, int flagOperando1, int flagOperando2, int flagDivisor0)
{
    if(flagOperando1 == 1 && flagOperando2 == 1)
    {
        printf("\nLa suma entre %f y %f, es: \n", primerOperando, segundoOperando);
        verificacion(flagOperando1, flagOperando2, suma(primerOperando, segundoOperando));
        printf("\nLa resta entre %f y %f, es: \n", primerOperando, segundoOperando);
        verificacion(flagOperando1, flagOperando2, resta(primerOperando, segundoOperando));
        if(flagDivisor0 == 1)
        {
           printf("\nLa division entre %f y %f, es: \n", primerOperando, segundoOperando);
            verificacion(flagOperando1, flagOperando2, dividir(primerOperando, segundoOperando, flagDivisor0));
        }else
        {
            printf("\nEl divisor debe ser distinto de 0\n");
        }

        printf("\nLa multiplicacion entre %f y %f, es: \n", primerOperando, segundoOperando);
        verificacion(flagOperando1, flagOperando2, multiplicar(primerOperando, segundoOperando));
        factorial(primerOperando, segundoOperando, flagOperando1);
    }else if(flagOperando1 == 1 && flagOperando2 == 0)
    {
        factorial(primerOperando, segundoOperando, flagOperando1);
        printf("\nDebe ingresar ambos operandos para poder ver las operaciones faltantes\n");
    }
    else
    {
        printf("\nDebe ingresar ambos operandos para poder realizar esta accion\n");
    }

}



/** \brief realiza el factorial del numero elegido, ya ingresado previamente.
 *
 * \param el primer numero ingresado por el usuario (float x)
 * \param el segundo numero ingresado por el usuario (float y)
 * \param bandera que afirma que el primer numero fue ingresado (int flag1)
 *
 */
factorial(float x, float y, int flag1)
{
    float factorial = 1;
    float z;
    if ( flag1 == 1)
    {
        for(z=x; z>1; z--)
            {
                factorial = factorial * z;
            }
            printf("\nEl factorial de %f es : %f\n",x,factorial);
    }else if(x == 0)
{
    printf("\nEl factorial de %f es : 1\n",x);
}else
{
    printf("\nDebe ingresar el primer operando para poder realizar el factorial\n");
}

}

#endif // FUNCIONES_H_INCLUDED
