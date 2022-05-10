#ifndef GERENTE_H_INCLUDED
#define GERENTE_H_INCLUDED
#include"inventario.h"
#include "menu.h"
typedef struct colaPedidos{
    struct pedido*inicio;
    struct pedido*fin;
    int n;
}colaPedidos;

typedef struct pedido{
    char cliente[50];
    char direccion[50];
    double telefono;
    float total;
    lista*carrito;
    struct pedido *sig;
}pedido;

float calcularTotal(lista*carrito);

colaPedidos *nuevaCola();
pedido*crear_2(char cliente[],char direccion[],int n,double tefelono,float total,lista *carrito);
void imprimirCola(colaPedidos*cola);
void agregaDatoCola(char cliente[],char direccion[],int n,double telefono,float total,lista *carrito,colaPedidos*pendientes);
void llenarDatos(char cliente[],char direccion[],int n,double *telefono,lista *carrito,colaPedidos*cola);

#endif // GERENTE_H_INCLUDED
