#include <stdio.h>
#include <stdlib.h>
#include"inventario.h"
#include "menu.h"
#include "gerente.h"
int main()
{
    //variables para almacenista y cliente
    char nombre[30];
    float precio;
    int cantidad;
    int opcion,opcion_2;
    //variables para gerente
    char cliente[50],direccion[50];
    double telefono;

    lista *catalogo=nuevaLista();
    lista *carrito=nuevaLista();
    colaPedidos *datos=nuevaCola();
    do{

        menu(&opcion_2);
        switch(opcion_2)
        {
        case 1:

            do{
                menu_almacenista(&opcion);
                switch(opcion)
                {
                case 1:
                imprimeCarrito(catalogo);
                break;
                case 2:
                llenarInventario(nombre,30,&precio,&cantidad,catalogo);
                break;
                }

             }while(opcion!=3);
        break;
        case 2:
            do{
                menu_cliente(&opcion);
                switch(opcion)
                {
                case 1:
                llenarCarrito(catalogo,carrito);
                break;
                case 2:
                confirmarCarrito(catalogo,carrito);
                break;
                case 3:
                imprimeCarrito(carrito);
                break;
                case 4:
                llenarDatos(cliente,direccion,50,&telefono,carrito,datos);
                break;
                }
              }while(opcion!=5);
        break;
    case 3:
        break;
    case 4:
        break;

    }
    }while(opcion_2!=5);
    imprimirCola(datos);
    return 0;
}

