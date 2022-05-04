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
void llenarCarrito(lista *ListaF)
{
    inventario *p;
    char siguiente;
    if (vacia(ListaF)) {
        printf("Lista vacia\n");
        return;
    }
    p = ListaF->inicio;
    printf("PRODUCTO: %s",p->nombre);
    printf("PRECIO UNITARIO: [$%.2f]\n",p->precio);
    printf("DISPONIBILIDAD: [%d]",p->cantidad);
    printf("\n-----------------------------\n");

    while(p->sig!=NULL || p->ant!=NULL){
        printf("**siguiente producto [s]****anterior producto [a]**");

        scanf("%c",&siguiente);
        if(p==NULL){
            return;
            }
        if(siguiente == 's')
        {
            p=p->sig;
            printf("----------------------------\n");
            printf("PRODUCTO: %s",p->nombre);
            printf("PRECIO UNITARIO: [$%.2f]\n",p->precio);
            printf("DISPONIBILIDAD: [%d]",p->cantidad);
            printf("\n-----------------------------\n");
        }else if(siguiente=='a')
        {
            p=p->ant;
            printf("----------------------------\n");
            printf("PRODUCTO: %s",p->nombre);
            printf("PRECIO UNITARIO: [$%.2f]\n",p->precio);
            printf("DISPONIBILIDAD: [%d]",p->cantidad);
            printf("\n-----------------------------\n");
        }
    }
    return;
}
void llenarInventario(char nombre[],int n,float*precio,int*cantidad,lista*ListaF)
{
     int op;
     int op2;
     char producto[30];
     do{
        printf("desea modificar el inventario? 1[SI] 0[NO]\n");
        scanf("%d",&op);
            if(op==1)
            {
                printf("el producto ya esta en inventario? 1[SI] 0[NO]\n");
                scanf("%d",&op2);
                if(op2==0){
                printf("ingrese el nombre del producto\n");
                fflush(stdin);
                fgets(nombre,30,stdin);
                printf("ingrese el precio del producto\n");
                scanf("%f",precio);
                printf("ingrese la cantidad del producto\n");
                scanf("%d",cantidad);
                agregaDatoFinal(ListaF,nombre,30,*precio,*cantidad);
                }
                else if(op2==1){
                    printf("cual es el nombre del producto?\n");
                    fflush(stdin);
                    fgets(producto,30,stdin);
                    
                }
            }
    }while(op!=0);

}
