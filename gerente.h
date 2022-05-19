#ifndef GERENTE_H_INCLUDED
#define GERENTE_H_INCLUDED
#include "inventario.h"
typedef struct pedido{
    char cliente[50];
    char direccion[50];
    double telefono;
    float total;
    lista*carrito;
    struct pedido *sig;
}pedido;

typedef struct colaPedidos{
    struct pedido*inicio;
    struct pedido*fin;
    int n;
}colaPedidos;

float calcularTotal(lista*carrito);

int colaVacia(colaPedidos*pedidos);
colaPedidos *nuevaCola();
pedido*crear_2(char cliente[],char direccion[],int n,double tefelono,float total,lista *carrito);
void imprimirCola(colaPedidos*cola);
void agregaDatoCola(char cliente[],char direccion[],int n,double telefono,float total,lista *carrito,colaPedidos*pendientes);
void llenarDatos(lista *carrito,colaPedidos*cola);

#endif // GERENTE_H_INCLUDED
