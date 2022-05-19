#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

typedef struct inventario{
    char nombre[30];
    float precio;
    int cantidad;
    struct inventario *sig;
    struct inventario *ant;
}inventario;

typedef struct lista{
    struct inventario *inicio;
    struct inventario *fin;
    int n;
}lista;

lista *nuevaLista(void);
inventario*crear(char nombre2[],int n,float precio,int cantidad);
inventario *modificar(lista*ListaF_2,int cantidad,char nombre[],int n);
inventario*modificar_2(lista*ListaF_2,int cantidad, char nombre[],int n);

int vacia(lista *ListaF);

void agregaDatoFinal(lista *listado,char nombre[],int n,float precio,int cantidad);
void llenarCarrito(lista *ListaF,lista*carrito);
void llenarInventario(lista*ListaF);
void imprimeCarrito(lista *carrito);
void confirmarCarrito(lista*ListaF,lista*carrito);
void imprimeLista_1(inventario*p);
void navegarInventario(lista*carrito);
#endif // INVENTARIO_H_INCLUDED
