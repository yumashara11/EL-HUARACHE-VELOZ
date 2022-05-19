#ifndef TRANSITO_H_INCLUDED
#define TRANSITO_H_INCLUDED
#include "repartidor.h"
#include "gerente.h"
typedef struct transito{
        repartidor *ocupados;
        pedido *cliente;
        struct transito*sig,*ant;
}transito;

typedef struct listaTransito{
    struct transito *inicio,*fin;
    int n;
}listaTransito;

int vaciaT(listaTransito *ListaF);

transito* buscarRepartidor(listaTransito*ListaF);
transito*crear_4(repartidor*ocupados,pedido*cliente);
void agregaDatoFinalT(repartidor*ocupados,pedido*cliente,listaTransito*ListaF);
listaTransito *nuevaListaT();
void asignarPedido(colaPedidos*datos,colaRepartidores*repartidores,listaTransito*listaF);
pedido*borrar_1(colaPedidos*cliente);
repartidor*borrar_2(colaRepartidores*repartidores);
void imprimirRepartidores(listaTransito *ListaF);
transito*identificador(listaTransito*repartidores,double id);
listaTransito *reordenamiento(listaTransito *ListaF,transito *r);
void imprimirRepartidores_1(pedido*p,repartidor*r);
void confirmarEntrega(listaTransito*ListaF,colaRepartidores*cola,transito*r);
#endif // TRANSITO_H_INCLUDED
