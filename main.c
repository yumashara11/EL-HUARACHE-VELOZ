#include <stdio.h>
#include <stdlib.h>
#include"inventario.h"
#include "menu.h"
#include "gerente.h"
#include "repartidor.h"
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
    //variables para llenar cola de repartidores
    char nombreRepartidor[20];
    double id;
    lista *catalogo=nuevaLista();
    colaRepartidores*repartidores=nuevaColaR();
    colaPedidos *datos=nuevaCola();
        do{
        lista *carrito=nuevaLista();
        menu(&opcion_2);
        switch(opcion_2)
        {
        case 1:

            do{
                menu_almacenista(&opcion);
                switch(opcion)
                {
                case 1:
                //imprimeCarrito(catalogo);
                navegarInventario(catalogo);
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
        free(carrito);
        break;
    case 3:
        do{
            menu_gerente(&opcion);
            switch(opcion)
            {
            case 1:
                imprimirCola(datos);
                break;
            case 2:
                llenarRepartidores(nombreRepartidor,20,&id,repartidores);
                imprimirCola_R(repartidores);
                break;
            }

            }while(opcion!=5);
        break;
    case 4:
        do{
            menu_repartidor(&opcion);
            /*switch(opcion){
            case 1:
            }*/

        }while(opcion!=3);
        break;

    }
    }while(opcion_2!=5);

    return 0;
}
