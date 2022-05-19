#include <stdio.h>
#include"menu.h"
/*aqui se agrupan las funciones de los printf,
se guardan todas las preguntas y menus del programa que se
imprimen constantemente*/
void menu(int *op){
    printf("\n");
    printf("|*****************************************|\n");
    printf("|************EL HUARACHE VELOZ************|\n");
    printf("|*****************************************|\n");
    printf("\n----------------------------------------------------\n");
    printf("|      TIENDA ONLINE 100 POR CIENTO MEXICANA       |\n");
    printf("----------------------------------------------------\n");
    printf("|+ HAS TU CARRITO Y NOSOTROS TE LO LLEVAMOS        |\n");
    printf("|+ ABIERTO LAS 24 HORAS LOS 7 DIAS DE LA SEMANA    |\n");
    printf("|+ ALTA VARIEDAD DE PRODCUTOS SELECTOS             |\n");
    printf("|+ FACIL, RAPIDO, SEGURO, CONFIABLE                |\n");
    printf("----------------------------------------------------\n\n");
    printf("---------------------------------\n");
    printf("|Creado por:                    |\n");
    printf("---------------------------------\n");
    printf("|+ Gonzalez Sanchez Jose Manuel |\n");
    printf("|+ Jimenez Urrutia Raymundo     |\n");
    printf("|+ Carrillo Gil Santiago        |\n");
    printf("---------------------------------\n\n\n");
    printf("****************\n");
    printf("* IDENTIFICATE *\n");
    printf("****************\n");
    printf("*[1]ALMACENISTA*\n*[2]CLIENTE    *\n*[3]GERENTE    *\n*[4]REPARTIDOR *\n*[5]SALIR      *\n");
    printf("****************\n\n");

    scanf("%d",op);
}
void menu_cliente(int *opcion)
{
    printf("*****CLIENTE*****\n");
    printf("[1]LLENAR CARRITO\n[2]EDITAR CARRITO\n[3]CONSULTAR CARRITO COMPLETO\n");
    printf("[4]FINALIZAR PEDIDO\n[5]SALIR\n");
    scanf("%d",opcion);
}
void menu_almacenista(int *opcion)
{
    printf("*****ALMACENISTA*****\n");
    printf("[1]CONSULTAR EL INVENTARIO\n[2]MODIFICAR INVENTARIO\n[3]SALIR\n");
    scanf("%d",opcion);
}

void menu_gerente(int*opcion)
{
    printf("*****GERENTE*****\n");
    printf("[1]COLA DE PEDIDOS\n[2]REPARTIDORES DISPONIBLES\n[3]REPARTIDORES EN TRANSITO\n");
    printf("[4]ASIGNAR PEDIDO\n[5]SALIR\n");
    scanf("%d",opcion);
}
void menu_repartidor(int*opcion)
{
     printf("*****REPARTIDOR*****\n");
    printf("[1]PEDIDO ASIGNADO\n[2]NOTIFICAR ENTREGA\n[3]SALIR\n");
    scanf("%d",opcion);
}
void preguntas_usuario(int*op,int n)
{
    switch(n)
    {
        case 1:
            printf("desea agregar el producto al carrito? 1[SI] - 0[NO]: ");
            scanf("%d",op);
            return;
        case 2:
            printf("cuantos productos desea agregar?: ");
            scanf("%d",op);
            return;
        case 3:
            printf("FINALIZAR COMRA [1] - SEGUIR COMPRANDO [0]: ");
            scanf("%d",op);
            return;
        case 4:
            printf("deseas eliminar este producto? 1[SI] - 0[NO]: ");
            scanf("%d",op);
            return;
        case 5:
            printf("cuantos productos desea eliminar?: ");
            scanf("%d",op);
            return;
        case 6:
             printf("FINALIZAR PEDIDO[1] - SEGUIR EDITANDO[0]: ");
            scanf("%d",op);
            return;
    }
    return;
}
void navegacion(char *caracter)
{
    printf("SIGUIENTE [s] - ANTERIOR [a] - FINAL[f] - INICIO [i]: ");
    scanf("%c",caracter);
}
void imprimirCorazon()
{
      int a, b, line = 12;
   for (a = line/2; a <= line; a = a+2) { //Para la parte superior del corazon
      for (b = 1; b < line-a; b = b+2) //crear espacio antes de la primera prominencia
         printf(" ");
      for (b = 1; b <= a; b++) //imprimir la primera prominencia
         printf("*");
      for (b = 1; b <= line-a; b++) //crear espacio antes de la segunda prominencia
         printf(" ");
      for (b = 1; b <= a-1; b++) //imprimir la segunda prominencia
         printf("*");
      printf("\n");
   }
   for (a = line; a >= 0; a--) { //la base del corazon es un triangulo invertido
      for (b = a; b < line; b++) //generar espacio antes del triangulo
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) //imprimir el triangulo
         printf("*");
      printf("\n");
   }
   printf("<3 LOS AMO PERROS <3\n");
   return;
}
