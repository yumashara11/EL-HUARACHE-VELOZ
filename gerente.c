#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "gerente.h"
#include "menu.h"
/*se usa el mismo metodo de listas para crear la cola de repartidores,
la unica diferencia es que para eliminar un repartidor de la cola, se tiene que
eliminar del principio de la cola*/
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
void llenarDatos(lista *carrito,colaPedidos*cola)
{
    /*esta funcione le pide sus datos al usuario y calcula el total
    de su carrito $$$*/
    float precioTotal=0;
    char cliente[50],direccion[50];
    double telefono;
    printf("********DATOS DEL CLIENTE*******\n");
    printf("ingrese su nombre: ");
    fflush(stdin);
    fgets(cliente,50,stdin);
    printf("ingrese su direccion: ");
    fflush(stdin);
    fgets(direccion,50,stdin);
    printf("ingrese su numero de telefono: ");
    fflush(stdin);
    scanf("%lf",&telefono);
    //funcion para calcular el precio total del carrito
    precioTotal=calcularTotal(carrito);
    //funcion para agregar los datos del cliente, el precio total y el carrito
    //a una cola de pedidos...
    agregaDatoCola(cliente,direccion,50,telefono,precioTotal,carrito,cola);
    printf("\n\n\t!!TU PEDIDO FUE REALIZADO CON EXITO!!\n");
    printf("SERA ENVIADO A LA BREVEDAD :), GRACIAS POR SU PREFERENCIA.\n");
    printf("\tATTE: TIENDA 'EL HUARACHE VELOZ'\n\n");
    return;
}
float calcularTotal(lista*carrito)
{
    inventario *p;
    float precioTotal=0;
    //compruebo si solo tengo un producto en mi carrito
    if (carrito->inicio == carrito->fin) {
        //el precio total es igual al precio unitario por la cantidad del producto
        precioTotal=(carrito->inicio->precio)*(carrito->inicio->cantidad);
        return precioTotal;
    }
    //en caso contrario empezamos a recorrer el carrito
    p = carrito->inicio;
    while (p!=NULL) {
        //el precio total es igual a la suma total del precio unitario por la cantidad de productos
        precioTotal=precioTotal+(p->precio*p->cantidad);
        p = p->sig;
    }
    return precioTotal;//retorno el precio total
}

void imprimirCola(colaPedidos*cola)
{
    if (colaVacia(cola)){
        printf("Cola Vacia\n");
        return;
    }

    pedido *p;
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
    return;
}
