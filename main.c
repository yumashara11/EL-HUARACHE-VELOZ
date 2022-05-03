#include <stdio.h>
#include <stdlib.h>
#include"inventario.h"

int main()
{
    char nombre[30];
    float precio;
    int cantidad;
    lista *catalogo=nuevaLista();
    llenarInventario(nombre,30,&precio,&cantidad,catalogo);
    imprimeLista(catalogo);
    return 0;
}

