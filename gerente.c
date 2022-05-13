#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"gerente.h"
#include"inventario.h"
#include"menu.h"
colaPedidos *nuevaCola()
{
    colaPedidos *p;
    p = malloc(sizeof(colaPedidos));
    p->inicio = p->fin = NULL;
    p->n=0;
    return p;
}
pedido*crear_2(char cliente[],char direccion[],int n,double telefono,float total,lista *carrito)
{
    pedido*p;
    p = malloc(sizeof(pedido));
    p->sig = NULL;
    p->telefono=telefono;
    p->total=total;
    strcpy(p->cliente,cliente);
    strcpy(p->direccion,direccion);
    p->carrito=carrito;
    return p;
}
int colaVacia(colaPedidos*pedidos)
{
    return pedidos->inicio==NULL;
}
void agregaDatoCola(char cliente[],char direccion[],int n,double telefono,float total,lista *carrito,colaPedidos*pendientes)
{
    pedido*p=crear_2(cliente,direccion,n,telefono,total,carrito);
    if(colaVacia(pendientes)){
        pendientes->inicio=pendientes->fin=p;
        pendientes->n=1;
        return;
    }
    pendientes->fin->sig=p;
    pendientes->fin=p;
    pendientes->n+=1;
    return;

}
void llenarDatos(char cliente[],char direccion[],int n,double *telefono,lista *carrito,colaPedidos*cola)
{
    float precioTotal;

    printf("********DATOS DEL CLIENTE*******\n");
    printf("ingrese su nombre: ");
    fflush(stdin);
    fgets(cliente,n,stdin);
    printf("ingrese su direccion: ");
    fflush(stdin);
    fgets(direccion,n,stdin);
    printf("ingrese su numero de telefono: ");
    fflush(stdin);
    scanf("%lf",telefono);
    precioTotal=calcularTotal(carrito);
    agregaDatoCola(cliente,direccion,n,*telefono,precioTotal,carrito,cola);
    printf("\n\t!!TU PEDIDO FUE REALIZADO CON EXITO!!\n");
    printf("SERA ENVIADO A LA BREVEDAD :), GRACAIS POR SU PREFERENCIA.\n");
    printf("\tATTE: TIENDA 'EL HUARACHE VELOZ'\n");
}
float calcularTotal(lista*carrito)
{
    inventario *p;
    float precioTotal=0;
    if (carrito->inicio == carrito->fin) {
        precioTotal=carrito->inicio->precio*carrito->inicio->cantidad;
        return precioTotal;
    }
    p = carrito->inicio;
    while (p!=NULL) {
        precioTotal=precioTotal+(p->precio*p->cantidad);
        p = p->sig;
    }
    return precioTotal;
}

void imprimirCola(colaPedidos*cola)
{
    pedido *p=cola;
    p = cola->inicio;
    printf("********COLA DE PEDIDOS********\n");
    int k=1;
    while (p!=NULL) {
        printf("[%d]\n",k);
        printf("|+NOMBRE: %s\n",p->cliente);
        printf("|+DIRECCION: %s\n",p->direccion);
        printf("|+TELEFONO: %.0lf\n",p->telefono);
        printf("|+TOTAL: $%.2f\n",p->total);
        printf("------------------------------\n");
        k++;
        p = p->sig;
    }
}
