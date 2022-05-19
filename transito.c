#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "transito.h"
/*se utiliza la misma logica que en inventario.c para crear una lista
doblemente ligada*/
listaTransito *nuevaListaT()
{
    //se crea la lista
    listaTransito *p;
    p = malloc(sizeof(listaTransito));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}
transito*crear_4(repartidor*ocupados,pedido*cliente)
{
    //se llena la estructura transito con los datos recibidos
    transito*p;
    p = malloc(sizeof(transito));
    p->ant = NULL;
    p->sig = NULL;
    p->ocupados=ocupados;
    p->cliente=cliente;
    return p;
}
int vaciaT(listaTransito *ListaF)
{
    return ListaF->inicio == NULL;
}
void agregaDatoFinalT(repartidor*ocupados,pedido*cliente,listaTransito*ListaF)
{
    /*se agregan los datos de una estructura transito
    a la lista de repartidores en transito*/
    transito*p = crear_4(ocupados,cliente);
    if (vaciaT(ListaF)) {
        ListaF->inicio = ListaF->fin = p;
        ListaF->n=1;
        return;
    }
    p->ant = ListaF->fin;
    ListaF->fin->sig = p;
    ListaF->fin = p;
    ListaF->n += 1;
    return;
}
void asignarPedido(colaPedidos*datos,colaRepartidores*repartidores,listaTransito*ListaF)
{

    /*en esta funcion se asigna automaticamente el primer pedido de la cola de pedidos
    al primer repartidor DISPONIBLE de la cola de repartidores*/
    if (colaVacia(datos)){
        printf("NO HAY PEDIDOS PENDIENTES PARA ASIGNAR!!\n\n");
        return;
    }
    pedido*p;
    repartidor *r;
    printf("\n\tEL PEDIDO FUE ASIGNADO CON EXITO A:\n");
    printf("\t\t%s\n",repartidores->inicio->nrepartidor);
    //se borra el repartidor de la cola de repartidores DISPONIBLES
    r=borrar_2(repartidores);
    //se borra el pedido de la cola de pedidos pendientes
    p=borrar_1(datos);
    //ambos datos se agregan a una lista de repartidores en TRANSITO
    agregaDatoFinalT(r,p,ListaF);
    return;
}
repartidor*borrar_2(colaRepartidores*repartidores)
{
    if (colaVacia_R(repartidores)){
        return NULL;
    }
    /*ENLACES correspondientes para eliminar el primer
    repartidor de la cola*/
    repartidor *p;
    p=repartidores->inicio;
    repartidores->inicio = p->sig;
    p->sig=NULL;
    return p;
}
pedido*borrar_1(colaPedidos*datos)
{
    if (colaVacia(datos)){
        return NULL;
    }
    /*ENLACES correspondientes para eliminar al primer
    pedido de la cola de pedidos*/
    pedido *p;
    p = datos->inicio;
    datos->inicio= datos->inicio->sig;
    p->sig=NULL;
    return p;
}
void imprimirRepartidores(listaTransito *ListaF)
{
    transito *r;
    int op;
    if (vaciaT(ListaF)){
        printf("Lista Vacia\n");
        return;
    }
    r=ListaF->inicio;
    while (r!=NULL)
    {
        imprimirRepartidores_1(r->cliente,r->ocupados);
        r=r->sig;
    }

    return;
}
void imprimirRepartidores_1(pedido*p,repartidor*r)
{
    printf("-----------------------------\n");
    printf("****DATOS DEL REPARTIDOR****\n");
    printf("|+REPARTIDOR ASIGNADO: %s\n",r->nrepartidor);
    printf("|+ID: %.00lf\n\n",r->id);
    printf("****DATOS DEL PEDIDO****\n");
    printf("|+CLIENTE: %s\n",p->cliente);
    printf("|+DIRECCION: %s\n",p->direccion);
    printf("|+NUMERO: %.00lf\n",p->telefono);
    printf("|+TOTAL: $%.2f\n",p->total);
    printf("-----------------------------\n");
}
transito* buscarRepartidor(listaTransito*ListaF)
{
    /*funcion para buscar a un repartidor dentro de la lista
    de repartidores en TRANSITO mediante su ID y recursividad*/
    transito*r;
    double id;
    int op;
    printf("\n*****REPARTIDOR*****\n");
    printf("INGRESAR SU ID: ");
    scanf("%lf",&id);
    //r es igual al repartidor ya encontrado por su ID
    r=identificador(ListaF,id);
    if (r==NULL)
    {
        if (vaciaT(ListaF)){
            printf("No hay repartidores en transito\n");
            return NULL;
        }else {
            //en caso que el ID haya sido un ID equivocado
            //se llama de nuevo a la misma funcion
            //y asi sucesivamente hasta que se ingrese un ID correcto
            buscarRepartidor(ListaF);
            return;
            }
    }else {//si ya encontró al repartidor lo saluda con un HOLA!
            printf("HOLA! %s\n",r->ocupados->nrepartidor);
            }
    return r;//retorno la estructura completa que contiene al repartidor en transito
}
transito *identificador(listaTransito*repartidores,double id)
{
    /*funcion que retorna la estructura especifica del repartidor
    encontrado por su id*/
    transito *p;
    //se comprueba si la lista está vacia
    if (vaciaT(repartidores))
        return NULL;
    //en caso contrario se necesita recorrer la lista hasta que p sea NULL
    //o hasta que haya encontrado el ID dentro de la lista de repartidores en transito
    p = repartidores->inicio;
    while (p!=NULL && id!=p->ocupados->id) {
        p = p->sig;
    }
    //si ya recorió la lista se comprueba si p == NULL, es decir que recorió la lista completa
    //y no encontró el ID
    if (p==NULL) {
        printf("ID invalido, intente de nuevo :(\n");
        return NULL;
    }
    //en caso contrario quiere decir que encontró el ID dentro de la lista
    //y me retorna la estructura completa con todos los datos de ese repartidor en especifico
    return p;
}
void confirmarEntrega(listaTransito*ListaF,colaRepartidores*cola,transito*r)
{
   /*funcion que sirve para confirmar la entrega y modificar la cola de repartidores
   DISPONIBLES y la lista de repartidores en TRANSITO*/
   transito*p,*a,*z;
   int op;
    if (r==NULL)//se comprueba si mi repartidor no existe
    {
        printf("No hay repartidores en transito\n");
        return;
    }
    //se pregunta si se entregó el pedido
    printf("has entregado el pedido con exito? 1[SI] - 0[NO]: ");
    scanf("%d",&op);
    if (op==1)
    {
        /*si se entregó el producto se hacen los ENLACES correspondientes
        para quitar al repartidor de la lista de repartidores en TRANSITO y AGREGARLO de nuevo
        al final de la cola de repartidores DISPONIBLES*/
        if (ListaF->inicio == ListaF->fin) {
            if (ListaF->inicio == r) {
                p = ListaF->inicio;
                ListaF->inicio = ListaF->fin = NULL;
                ListaF->n = 0;
                agregaDatoCola_R(r->ocupados->nrepartidor,30,r->ocupados->id,cola);
            }
        return;
    }
    p = ListaF->inicio;//se empieza a recorrrer la lista hasta que encuentre al repartidor ya anteriormente identificado
    while (p!=NULL && p != r) {
        p = p->sig;
    }
    if (p==NULL) {
        return;
    }
    if (p == ListaF->inicio) {//se comprueba si el repartidor está al inicio de la lista
        /*se realizan los ENLACES correspondietes para quitar a ese repartidor
        de la lista de repartidores en TRANSITO*/
        ListaF->inicio = ListaF->inicio->sig;
        ListaF->inicio->ant = NULL;
        p->sig = NULL;
        //se agrega a ese repartidor de nuevo al final de la cola de repartidores
        agregaDatoCola_R(r->ocupados->nrepartidor,30,r->ocupados->id,cola);
        return;

    }
    if (p==ListaF->fin) {//se comprueba si está al final de la lista
        /*se realizan los ENLACES para quitarlo de la lista y se agrega al final de la cola*/
        ListaF->fin = ListaF->fin->ant;
        ListaF->fin->sig = NULL;
        p->ant = NULL;
        agregaDatoCola_R(r->ocupados->nrepartidor,30,r->ocupados->id,cola);
        return;
    }
/*en el caso que no esté ni al inicio ni al final de la lista quiere decir que está en medio
por lo que se hacen los enlaces correpondientes para quitarlo de la lista y luego
se agrega al final de la cola de repartidores DISPONIBLES*/

a = p->ant;
z = p->sig;
a->sig = z;
z->ant = a;
p->ant = NULL;
p->sig = NULL;
agregaDatoCola_R(r->ocupados->nrepartidor,30,r->ocupados->id,cola);
return;
    }
return;

}
