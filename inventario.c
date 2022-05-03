#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "inventario.h"

lista *nuevaLista()
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
void imprimeLista(lista *ListaF)
{
    inventario *p;
    if (vacia(ListaF)) {
        printf("Lista vacia\n");
        return;
    }
    p = ListaF->inicio;
    while (p!=NULL) {
        printf("PRODUCTO: %s",p->nombre);
        printf("PRECIO UNITARIO: [$%.2f]\n",p->precio);
        printf("DISPONIBILIDAD: [%d]",p->cantidad);
        printf("\n-----------------------------\n");
        p = p->sig;
    }
    printf("\n");
    return;
}
void llenarInventario(char nombre[],int n,float*precio,int*cantidad,lista*ListaF)
{
     for (int k=0;k<3;k++)
        {
            printf("ingrese el nombre del producto\n");
            fflush(stdin);
            fgets(nombre,30,stdin);
            printf("ingrese el precio del producto\n");
            scanf("%f",precio);
            printf("ingrese la cantidad del producto\n");
            scanf("%d",cantidad);
            agregaDatoFinal(ListaF,nombre,30,*precio,*cantidad);
        }
}
