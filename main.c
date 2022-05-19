#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include "menu.h"
#include "gerente.h"
#include "repartidor.h"
#include "transito.h"
/*tienda el huarache veloz fue creada con programacion estructudarada,
haciendo uso de listas (simples y doblemente ligadas), colas, funciones recursivas
y unos cuantos if-else anidados que nunca fallan...*/
int main()
{
    //se declaran las variables para el control de los switch
    int opcion,opcion_2;
    //se crean casi todas las listas y colas que se utilizan en el programa(excepto una)
    lista *catalogo=nuevaLista();//lista del inventario de la tienda
    colaRepartidores*repartidores=nuevaColaR();//cola de repartidores disponibles
    colaPedidos *datos=nuevaCola();//cola de pedidos pendientes
    listaTransito *listaRT = nuevaListaT();//lista de repartidores en transito (con pedido asignado)


    /* llenarRepartidores() es una funcion que llena la cola de repartidores,
    es decir, cada que se inicia el programa la cola se llena con dicha funcion*/
    llenarRepartidores(repartidores);

    transito*r;//se crea una variabe auxiliar para el apartado de "repartidor" dentro del menú principal

    /*mediante un do while se muestra el menú principal:
    [1]almacenista
    [2]cliente
    [3]gerente
    [4]repartidor
    [5]salir*/
        do{
        /*cada que entramos o regresamos al menú principal se crea la lista "carrito"
        que contendrá el carrito del cliente, para poder crear diferentes pedidos
        de clientes diferentes*/
        lista *carrito=nuevaLista();//lista del carrito del cliente
        menu(&opcion_2);//se muestra el menu y sigue el switch...
        switch(opcion_2)
        {
        case 1://almacenista

            do{
                menu_almacenista(&opcion);
                switch(opcion)
                {
                case 1:/*la funcion navegar inventario()
                    funciona para navegar dentro del inventario de la tienda*/
                navegarInventario(catalogo);
                break;
                case 2:/*la funcion llenarInventario() sirve
                    para ir llenando la tienda de productos...*/
                llenarInventario(catalogo);
                break;
                }

             }while(opcion!=3);
        break;
        case 2://cliente

            do{

                menu_cliente(&opcion);
                switch(opcion)
                {
                case 1:/*llenarCarrito() funciona para recorrer los productos de la tienda
                    y al mismo tiempop ir eligiendo o añadiendo productos al carrito*/
                llenarCarrito(catalogo,carrito);
                break;
                case 2:/*confirmarCarrito()sirve para editar el carrito del cliente
                    es decir, para poder eliminar productos del mismo*/
                confirmarCarrito(catalogo,carrito);
                break;
                case 3:/*imprimeCarrito() funciona par imprimir mi lista carrito completa*/
                imprimeCarrito(carrito);
                break;
                case 4:/*llenarDatos()sirve para ingresar nuestros Datos y mandarlos
                    junto con el carrito a una cola de pedidos...*/
                llenarDatos(carrito,datos);
                break;
                }
              }while(opcion!=5);

        break;
    case 3://gerente
        do{
            menu_gerente(&opcion);
            switch(opcion)
            {
            case 1:/*imprimirCola() imprime la cola de pedidos pendientes*/
                imprimirCola(datos);
                break;
            case 2:/*imprimirCola_R()imprime mi cola de repartidores DISPONIBLES*/
                imprimirCola_R(repartidores);
                break;
            case 3:/*imprimirRepartidores() imprime mi lista de
                repartidores en TRANSITO (con el pedido asignado)*/
                imprimirRepartidores(listaRT);
                break;
            case 4:/*asignarPedido() asigna el primer pedido de la cola de pedidos al primer
                repartidor DISPONIBLE de la cola de repartidores*/
               asignarPedido(datos,repartidores,listaRT);
                break;
            }

            }while(opcion!=5);
        break;
    case 4://repartidor
        do{

            menu_repartidor(&opcion);

            switch(opcion){
            case 1:/*buscarRepartidor() busca el repartidor dentro de la lista de repartidores
                en TRANSITO mediante su ID y recursividad, lo guarda en la variable auxiliar r*/
                r=buscarRepartidor(listaRT);
                /*imprimirRepatidores_1 imprime unicamente el repartidor que ya BUSQUÉ en
                la funcion anterior*/
                imprimirRepartidores_1(r->cliente,r->ocupados);
                break;
            case 2:/*repite la funcion recursiva buscarRepartidor()*/
                r=buscarRepartidor(listaRT);
                /*confirmarEntrega() sirve para confirmar si el pedido ya fue entregado,
                en dado caso que SI, se debe actualizar tanto la cola de repartidores DISPONIBLES
                como la lista de repartidores en TRANSITO*/
                confirmarEntrega(listaRT,repartidores,r);
            }

        }while(opcion!=3);
        break;

    }
    }while(opcion_2!=5);
    imprimirCorazon();
    return 0;
}
