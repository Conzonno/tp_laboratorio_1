

/** \brief La funcion suma los operandos
     *
     * \param Primer operando
     * \param Segundo operando
     * \return Devuelve los operandos sumados
     *
     */
int sumarOperandos (int A , int B)
{
    int suma;
    suma=A+B;
    return suma;

}


 /** \brief La funcion resta los operandos
     *
     * \param Primer operando
     * \param Segundo operando
     * \return Devuelve los operandos restados
     *
     */
int restarOperandos (int A, int B)
{
    int resta;
    resta=A-B;
    return resta;
}


/** \brief La funcion divide los operandos
     *
     * \param Primer operando
     * \param Segundo operando
     * \return Devuelve los operandos divididos
     *
     */
float dividirOperandos (int A, int B)
{
    float division;
    division=(float)A/(float)B;
    return division;
}


/** \brief La funcion multiplica los operandos
     *
     * \param Primer operando
     * \param Segundo operando
     * \return Devuelve los operandos multiplicados
     */
int multiplicarOperandos (int A, int B)
{
    int multiplicacion;
    multiplicacion=A*B;
    return multiplicacion;
}


 /** \brief La funcion realiza el factorial del operando
     *
     * \param Primer operando
     * \return Devuelve el operando factorizado
     *
     */
int factorialOperando(int A)
{
   int fact;
   if(A==0)
   {
       return 1;
   }
   else
   {
       fact=A*factorialOperando(A-1);
       return fact;
   }
}
