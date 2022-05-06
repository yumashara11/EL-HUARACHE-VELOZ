#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "inventario.h"
#include"menu.h"

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

        ListaF_2->inicio->cantidad-=cantidad;
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
    char siguiente;
    int op,cantidad;

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
            p=p->sig;
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
        }else if(siguiente=='a')
            {
            p=p->ant;
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
void llenarInventario(char nombre[],int n,float*precio,int*cantidad,lista*ListaF)
{
     int op;
     int op2;
     char producto[30];

    do
    {
        printf("desea modificar el inventario? 1[SI] 0[NO]\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("el producto ya esta en inventario? 1[SI] 0[NO]\n");
            scanf("%d",&op2);
            if(op2==0)
            {
            printf("ingrese el nombre del producto\n");
            fflush(stdin);
            fgets(nombre,30,stdin);
            printf("ingrese el precio del producto\n");
            scanf("%f",precio);
            printf("ingrese la cantidad del producto\n");
            scanf("%d",cantidad);
            agregaDatoFinal(ListaF,nombre,30,*precio,*cantidad);
            }else if(op2==1)
                {
                printf("cual es el nombre del producto?\n");
                fflush(stdin);
                fgets(producto,30,stdin);
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
    inventario *p;
    inventario *z;
    char siguiente;
    int op,cantidad;

    printf("*****ESTE ES TU CARRITO*****\n");
    if (vacia(carrito)) {
        printf("Lista vacia\n");
        return;
    }
    p = carrito->inicio;
    imprimeLista_1(p);
    preguntas_usuario(&op,4);
    if(op==1)
    {
        preguntas_usuario(&cantidad,5);
        p=modificar(carrito,cantidad,p->nombre,30);
        z=modificar_2(ListaF,cantidad,p->nombre,30);
    }
    preguntas_usuario(&op,6);
    if(op==1)
        return;

    while(p!=NULL)
    {
        navegacion(&siguiente);
        if(siguiente == 's')
        {
            p=p->sig;
            imprimeLista_1(p);
            preguntas_usuario(&op,4);
            if(op==1)
            {
                preguntas_usuario(&cantidad,5);
                p=modificar(carrito,cantidad,p->nombre,30);
                z=modificar_2(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,6);
            if(op==1)
                return;
        }else if(siguiente=='a')
            {
            p=p->ant;
            imprimeLista_1(p);
            preguntas_usuario(&op,4);
            if(op==1)
            {
                preguntas_usuario(&cantidad,5);
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
            p=modificar(carrito,cantidad,p->nombre,30);
            z=modificar_2(ListaF,cantidad,p->nombre,30);
            }
            preguntas_usuario(&op,6);
            if(op==1)
                return;

        }
    }

}
