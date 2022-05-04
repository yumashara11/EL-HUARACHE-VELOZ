#include <stdio.h>
#include <stdlib.h>
#include"inventario.h"
#include "menu.h"
int main()
{
    char nombre[30];
    float precio;
    int cantidad;
    int opcion;

    lista *catalogo=nuevaLista();
    lista *carrito=nuevaLista();
    do {
    menu(&opcion);
    switch(opcion)
    {
    case 1:
        llenarInventario(nombre,30,&precio,&cantidad,catalogo);
        break;
    case 2:
         llenarCarrito(catalogo);
        break;
    case 3:
        break;
    case 4:
        break;

    }
    }while(opcion!=5);

    return 0;
}
