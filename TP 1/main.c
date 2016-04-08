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
                fflush(stdin);
                scanf("%d",&opcion);
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
                fflush(stdin);
                scanf("%d",&opcion);
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
                    resta=restarOperandos(x, y);
                    division= dividirOperandos(x, y);
                    multiplicacion= multiplicarOperandos(x, y);
                    factorial= factorialOperando(x);
                    printf("La suma es: %d.\nLa resta es: %d.\nLa division es: %.2f.\nLa multiplicacion es: %d.\nEl factorial es: %d.\nDesea seguir?", suma, resta, division, multiplicacion, factorial);
                    fflush(stdin);
                    scanf("%c",&seguir);
                    break;
                case 9:
                    seguir = 'n';
                    break;
                default:
                    printf("Esa opcion no es valida, por favor ingrese otra\n");
                    system("pause");
                    seguir= 's';
                    break;
            }
        }
        return 0;
    }
