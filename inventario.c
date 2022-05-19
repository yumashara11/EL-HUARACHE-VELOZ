#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "inventario.h"
#include "menu.h"
lista *nuevaLista(void)
{
    lista *p;
    p = malloc(sizeof(lista));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

inventario*crear(char nombre2[],int n,float precio,int cantidad)
{
    inventario*p;
    p = malloc(sizeof(inventario));
    p->ant = NULL;
    p->sig = NULL;
    p->precio=precio;
    p->cantidad=cantidad;
    strcpy(p->nombre,nombre2);
    return p;
}

inventario *modificar(lista*ListaF_2,int cantidad,char nombre[], int n)
{
     inventario *p;
    if (vacia(ListaF_2))
        return NULL;
    if (ListaF_2->inicio == ListaF_2->fin) {

        ListaF_2->inicio->cantidad-=cantidad;
        return p;
    }
    p = ListaF_2->inicio;
    while (p!=NULL && strcmp(nombre,p->nombre) != 0) {
        p = p->sig;
    }
    if (p==NULL) {
        return NULL;
    }
    p->cantidad=p->cantidad-cantidad;

return p;
}

inventario*modificar_2(lista*ListaF_2,int cantidad, char nombre[],int n)
{
    inventario *p;

    if (vacia(ListaF_2))
        return NULL;
    if (ListaF_2->inicio == ListaF_2->fin) {

        ListaF_2->inicio->cantidad+=cantidad;
        return p;
    }
    p = ListaF_2->inicio;
    while (p!=NULL && strcmp(nombre,p->nombre) != 0) {
        p = p->sig;
    }
    if (p==NULL) {
        return NULL;
    }
    p->cantidad=p->cantidad+cantidad;

return p;
}

int vacia(lista *ListaF)
{
    return ListaF->inicio == NULL;
}

void agregaDatoFinal(lista *listado,char nombre2[],int n,float precio,int cantidad)
{
    inventario *p = crear(nombre2,n,precio,cantidad);
    if (vacia(listado)) {
        listado->inicio = listado->fin = p;
        listado->n=1;
        return;
    }
    p->ant = listado->fin;

    listado->fin->sig = p;

    listado->fin = p;
    listado->n += 1;
    return;
}

void llenarCarrito(lista *ListaF,lista*carrito)
{
    inventario *p;
    //p=inventario
    char siguiente;
    int op,cantidad;
    /*se utiliza la misma logica que la funcion confirmarCarrito()
    solo que aquí solo se van agregando los productos que desee el usuario
    al final del carrito y se va modificando el inventario de la tienda con la funcion
    modificar()*/
    if (vacia(ListaF)) {
        printf("Lista vacia\n");
        return;
    }
    p = ListaF->inicio;
    imprimeLista_1(p);
    preguntas_usuario(&op,1);
    if(op==1)
    {
        preguntas_usuario(&cantidad,2);
        agregaDatoFinal(carrito,p->nombre,30,p->precio,cantidad);
        p=modificar(ListaF,cantidad,p->nombre,30);
    }
    preguntas_usuario(&op,3);
        if(op==1)
            return;
    while(p!=NULL)
    {
        navegacion(&siguiente);

        if(siguiente == 's')
        {
            if (p==ListaF->fin){
                    p=ListaF->inicio;
                    imprimeLista_1(p);
            }else {
                p=p->sig;
                imprimeLista_1(p);
                }
            preguntas_usuario(&op,1);
            if(op==1)
            {
                preguntas_usuario(&cantidad,2);
                agregaDatoFinal(carrito,p->nombre,30,p->precio,cantidad);
                p=modificar(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,3);
            if(op==1)
                return;
        }else if(siguiente=='a')
            {
            if (p==ListaF->inicio){
                p=ListaF->fin;
                imprimeLista_1(p);
            }else{
                p=p->ant;
                imprimeLista_1(p);
                }
            preguntas_usuario(&op,1);
            if(op==1)
            {
                preguntas_usuario(&cantidad,2);
                agregaDatoFinal(carrito,p->nombre,30,p->precio,cantidad);
                p=modificar(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,3);
            if(op==1)
                return;
        }else if(siguiente=='i')
            {
            p = ListaF->inicio;
            imprimeLista_1(p);
            preguntas_usuario(&op,1);
            if(op==1)
            {
                preguntas_usuario(&cantidad,2);
                agregaDatoFinal(carrito,p->nombre,30,p->precio,cantidad);
                p=modificar(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,3);
            if(op==1)
                return;
        }else if(siguiente=='f')
            {
            p=ListaF->fin;
            imprimeLista_1(p);
            preguntas_usuario(&op,1);
            if(op==1)
            {
                preguntas_usuario(&cantidad,2);
                agregaDatoFinal(carrito,p->nombre,30,p->precio,cantidad);
                p=modificar(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,3);
            if(op==1)
                return;
            }
    }
    return;
}
void llenarInventario(lista*ListaF)
{
     /*variables para hacer uso de los if*/
     int op;
     int op2;
     /*variables que guardarán los datos de los productos
     del inventario*/
     int cantidad;
     char producto[30];
     float precio;
    do
    {
        printf("---------------------------------------\n");
        printf("desea modificar el inventario? 1[SI] 0[NO]: ");
        scanf("%d",&op);
        if(op==1)
        {
            printf("el producto ya esta en inventario? 1[SI] 0[NO]: ");
            scanf("%d",&op2);
            if(op2==0)
            {
            //se le piden los datos al usuario (almacenista)
            printf("ingrese el nombre del producto: ");
            fflush(stdin);
            fgets(producto,30,stdin);
            printf("ingrese el precio del producto: $");
            scanf("%f",&precio);
            printf("ingrese la cantidad del producto: ");
            scanf("%d",&cantidad);
            //se agregan dichos datos al final del inventario.
            agregaDatoFinal(ListaF,producto,30,precio,cantidad);
            }else//este else sirve por si se quiere añadir mas cantidad a un producto ya existente
                {
                printf("cual es el nombre del producto?: ");
                fflush(stdin);
                fgets(producto,30,stdin);
                printf("cuantos productos desea agregar?: ");
                scanf("%d",&op2);
                //la siguiente funcion sirve para modificar la lista
                //mediante la busca del producto por su nombre
                modificar_2(ListaF,op2,producto,30);
                }
        }
    }while(op!=0);

}

void imprimeCarrito(lista *carrito)
{
     inventario *p;
    if (vacia(carrito)) {
        printf("Lista vacia\n");
        return;
    }
    p = carrito->inicio;
    while(p!=NULL){
        imprimeLista_1(p);
        p=p->sig;
    }
    return;
}

void imprimeLista_1(inventario*p)
{
        printf("\n---------------------------------\n");
        printf("PRODUCTO: %s",p->nombre);
        printf("PRECIO UNITARIO: [$%.2f]\n",p->precio);
        printf("DISPONIBILIDAD: [%d]",p->cantidad);
        printf("\n---------------------------------\n");
    return;
}

void confirmarCarrito(lista*ListaF,lista*carrito)
{
    /*se recorre la lista por medio de los caracteres (s,a,f,i)
    y se le pregunta al cliente si desea eliminar cierta cantidad
    de un producto de su carrito*/
    inventario *p;
    inventario *z;
    //p=carrito
    //z=inventario

    char siguiente;
    int op,cantidad;

    printf("*****ESTE ES TU CARRITO*****\n");
    if (vacia(carrito)) {
        printf("Lista vacia\n");
        return;
    }
    //se empieza del primer producto del carrito
    p = carrito->inicio;
    imprimeLista_1(p);
    //preguntas que se hacen al usuario, diferenciadas
    //por un numero entero
    preguntas_usuario(&op,4);
    if(op==1)
    {
        preguntas_usuario(&cantidad,5);
        //funcion para modificar el carrito (eliminar el producto)
        p=modificar(carrito,cantidad,p->nombre,30);
        //funcion para modificar el inventario (añadir el producto que
        //anteriormente elimine del carrito)
        z=modificar_2(ListaF,cantidad,p->nombre,30);
    }
    preguntas_usuario(&op,6);
    if(op==1)
        return;
    //despues de que se mostró el primer producto del carrito
    //se empieza a recorrer el carrito completo
    //utilizando la misma logica que en la funcion navegarInventario()
    while(p!=NULL)
    {
        navegacion(&siguiente);
        if(siguiente == 's')
        {
            if (p==carrito->fin){
                p=carrito->inicio;
                imprimeLista_1(p);
            }else {
                p=p->sig;
                imprimeLista_1(p);
                }
            preguntas_usuario(&op,4);
            if(op==1)
            {
                preguntas_usuario(&cantidad,5);
                //se modifican las listas dependiendo de lo que decida el usuario
                //si decide quitar productos de su carrito
                //se deben agregar esos mismos productos al inventario de la tienda
                p=modificar(carrito,cantidad,p->nombre,30);
                z=modificar_2(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,6);
            if(op==1)
                return;
        }else if(siguiente=='a')
            {
            if (p==carrito->inicio){
                p=carrito->fin;
                imprimeLista_1(p);
            }else{
                p=p->ant;
                imprimeLista_1(p);
                }
            preguntas_usuario(&op,4);
            if(op==1)
            {
                preguntas_usuario(&cantidad,5);
                //se modifican las listas
                p=modificar(carrito,cantidad,p->nombre,30);
                z=modificar_2(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,6);
            if(op==1)
                return;
            }else if(siguiente=='i')
            {
            p = carrito->inicio;
            imprimeLista_1(p);
            preguntas_usuario(&op,4);
            if(op==1)
            {
            preguntas_usuario(&cantidad,5);
            //se modifican las listas
            p=modificar(carrito,cantidad,p->nombre,30);
            z=modificar_2(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,6);
            if(op==1)
            return;
            }else if(siguiente=='f')
            {
            p=carrito->fin;
            imprimeLista_1(p);
            preguntas_usuario(&op,4);
            if(op==1)
            {
            preguntas_usuario(&cantidad,5);
            //se modifican las listas
            p=modificar(carrito,cantidad,p->nombre,30);
            z=modificar_2(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,6);
            if(op==1)
                return;

        }
    }

}
void navegarInventario(lista*carrito)
{
    inventario *p;//variable auxiliar
    char siguiente;//variable para navegar dentro de la lista (anterior,siguiente,inicio,final,salir)
    /*se comprueba si el inventario está vacio*/
    if (vacia(carrito)) {
        printf("Lista vacia\n");
        return;
    }
    /*se empieza a recorrer el inventario desde el primer producto
    de la lista*/
    p = carrito->inicio;
    imprimeLista_1(p);//se imprime mi primer producto del inventario
    while(p!=NULL)//despues de imprimir el primer producto se empieza a recorrer todo el inventario
    {

        /*se usan if-else anidados para saber que hacer dependiendo lo que queira
        el usuario*/

        printf("SALIR[e]-");
        navegacion(&siguiente);
        if(siguiente == 's')//siguiente producto
        {
            if (p==carrito->fin)//en este if se comprueba si se encuentra en el ULTIMO producto del inventario
            {
                /*de ser asi, el SIGUIENTE PRODUCTO del ULTIMO producto del inventario
                es el primer producto del inventario*/
                p=carrito->inicio;
                imprimeLista_1(p);
            }else{//si no se encuentra en el ULTIMO simplemente imprime el siguiente producto
                p=p->sig;
                imprimeLista_1(p);
                }
        }else if(siguiente=='a')//producto anterior
            {
                if (p==carrito->inicio)//en este if se comprueba si se encuentra en el PRIMER producto del inventario
                {
                    /*de ser así, el PRODUCTO ANTERIOR del primer producto es el ULTIMO
                    producto del inventario*/
                    p=carrito->fin;
                    imprimeLista_1(p);
                }else{//en cualquier otro caso imprime el producto anterior
                        p=p->ant;
                        imprimeLista_1(p);
                    }
            }else if(siguiente=='i')//inicio de la lista
            {
                //se imprime el primer producto del inventario
                p = carrito->inicio;
                imprimeLista_1(p);
            }else if(siguiente=='f')//final de la lista
            {
                //se imprime el ultimo producto del inventario
                p=carrito->fin;
                imprimeLista_1(p);
            }else if(siguiente=='e')//salir
            {
                return;
            }

}
}


