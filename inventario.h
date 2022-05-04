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

lista *nuevaLista();

inventario*crear(char nombre2[],int n,float precio,int cantidad);

void agregaDatoFinal(lista *listado,char nombre[],int n,float precio,int cantidad);

int vacia(lista *ListaF);
void llenarCarrito(lista *ListaF);
void llenarInventario(char nombre[],int n,float*precio,int*cantidad,lista*ListaF);


#endif // INVENTARIO_H_INCLUDED
