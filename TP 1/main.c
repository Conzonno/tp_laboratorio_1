    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "funciones.h"

    int main()
    {
        char seguir='s';
        int opcion=0;
        int x;
        int y;
        int suma;
        int resta;
        int multiplicacion;
        float division;
        int factorial;
        int flag=0;
        char valorCambiado;

        while(seguir=='s')
        {
            if(flag==2)
            {
                system("cls");
                printf("1- Ingresar 1er operando (A=%d)\n", x);
                printf("2- Ingresar 2do operando (B=%d)\n", y);
                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operacione\n");
                printf("9- Salir\n");
                printf("Elija una opcion: ");
                scanf("%d",&opcion);
                while(opcion==0)
                {
                    //system("cls");
                    printf("Cero no es una opcion valida, por favor ingrese una opcion nuevamente: ");
                    //system("pause");
                    fflush(stdin);
                    scanf("%d", &opcion);
                    //break;
                }
            }
            else
            {
                system("cls");
                printf("1- Ingresar 1er operando (A=x)\n");
                printf("2- Ingresar 2do operando (B=y)\n");
                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");
                printf("Elija una opcion: ");
                scanf("%d",&opcion);
                while(opcion==0)
                {
                    //system("cls");
                    printf("Cero no es una opcion valida, por favor ingrese una opcion nuevamente: ");
                    //system("pause");
                    fflush(stdin);
                    scanf("%d", &opcion);
                    //break;
                }
                flag++;
            }
            system("cls");
            switch(opcion)
            {
                case 1:
                    printf("Asigne valor a 'A': ");
                    scanf("%d", &x);
                    break;
                case 2:
                    printf("Asigne valor a 'B': ");
                    scanf("%d", &y);
                    break;
                case 3:
                    suma= sumarOperandos(x, y);
                    printf("La suma es: %d\n", suma);
                    printf("Desea seguir?");
                    fflush(stdin);
                    scanf("%c",&seguir);
                    break;
                case 4:
                    resta=restarOperandos(x, y);
                    printf("La resta es: %d\n", resta);
                    printf("Desea seguir?");
                    fflush(stdin);
                    scanf("%c",&seguir);
                    break;
                case 5:
                    while(x==0 || y==0)
                    {
                        printf("No se puede dividir por cero, ingerese que valor quiere cambiar: ");
                        fflush(stdin);
                        scanf("%c", &valorCambiado);
                        valorCambiado=toupper(valorCambiado);
                        if(valorCambiado=='A')
                        {
                            printf("Ingrese un numero valor para 'A': ");
                            fflush(stdin);
                            scanf("%d", &x);
                        }
                        else if(valorCambiado=='B')
                        {
                            printf("Ingrese un numero valor para 'B': ");
                            fflush(stdin);
                            scanf("%d", &y);
                        }
                    }
                    division= dividirOperandos(x, y);
                    printf("La division es: %.2f\n", division);
                    printf("Desea seguir?");
                    fflush(stdin);
                    scanf("%c",&seguir);
                    break;
                case 6:
                    multiplicacion= multiplicarOperandos(x, y);
                    printf("La multiplicacion es: %d\n", multiplicacion);
                    printf("Desea seguir?");
                    fflush(stdin);
                    scanf("%c",&seguir);
                    break;
                case 7:
                    factorial= factorialOperando(x);
                    printf("El factorial es: %d\n", factorial);
                    printf("Desea seguir?");
                    fflush(stdin);
                    scanf("%c",&seguir);
                    break;
                case 8:
                    while(x==0 || y==0)
                    {
                        printf("No se puede realizar esta opcion con un operando en cero, ingerese que valor quiere cambiar: ");
                        fflush(stdin);
                        scanf("%c", &valorCambiado);
                        valorCambiado=toupper(valorCambiado);
                        if(valorCambiado=='A')
                        {
                            printf("Ingrese un numero valor para 'A': ");
                            fflush(stdin);
                            scanf("%d", &x);
                        }
                        else if(valorCambiado=='B')
                        {
                            printf("Ingrese un numero valor para 'B': ");
                            fflush(stdin);
                            scanf("%d", &y);
                        }
                    }
                    suma= sumarOperandos(x, y);
                    printf("La suma es: %d\n", suma);
                    resta=restarOperandos(x, y);
                    printf("La resta es: %d\n", resta);
                    division= dividirOperandos(x, y);
                    printf("La division es: %.2f\n", division);
                    multiplicacion= multiplicarOperandos(x, y);
                    printf("La multiplicacion es: %d\n", multiplicacion);
                    factorial= factorialOperando(x);
                    printf("El factorial es: %d\n", factorial);
                    printf("Desea seguir?");
                    fflush(stdin);
                    scanf("%c",&seguir);
                    break;
                case 9:
                    seguir = 'n';
                    break;
            }
        }
        return 0;
    }
