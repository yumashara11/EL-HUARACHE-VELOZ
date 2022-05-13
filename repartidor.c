#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "gerente.h"
#include "repartidor.h"
#include"menu.h"
colaRepartidores *nuevaColaR()
{
    colaRepartidores *r;
    r = malloc(sizeof(colaRepartidores));
    r->inicio = r->fin = NULL;
    r->n=0;
    return r;
}
repartidor*crear_3(char nrepartidor[],int n,double id)
{
    repartidor*r;
    r = malloc(sizeof(repartidor));
    r->sig = NULL;
    r->id=id;
    strcpy(r->nrepartidor,nrepartidor);
    return r;
}

int colaVacia_R(colaRepartidores*repartidor)
{
    return repartidor->inicio==NULL;
}
void agregaDatoCola_R(char nrepartidor[],int n,double id,colaRepartidores*disponibles)
{
    repartidor*r=crear_3(nrepartidor,n,id);
    if(colaVacia_R(disponibles)){
        disponibles->inicio=disponibles->fin=r;
        disponibles->n=1;
        return;
    }
    disponibles->fin->sig=r;
    disponibles->fin=r;
    disponibles->n+=1;
    return;
}
void llenarRepartidores(char nrepartidor[],int n,double *id,colaRepartidores*repartidores)
{
    strcpy(nrepartidor,"Raymundo Jimenez");
    agregaDatoCola_R(nrepartidor,n,05,repartidores);

    strcpy(nrepartidor,"Santiago Carrillo");
    agregaDatoCola_R(nrepartidor,n,13,repartidores);

    strcpy(nrepartidor,"Jose Gonzalez");
    agregaDatoCola_R(nrepartidor,n,11,repartidores);

    strcpy(nrepartidor,"Patricio Espindola");
    agregaDatoCola_R(nrepartidor,n,69,repartidores);

    strcpy(nrepartidor,"Gabriel Gutierrez");
    agregaDatoCola_R(nrepartidor,n,420,repartidores);

    strcpy(nrepartidor,"Christopher Sanchez");
    agregaDatoCola_R(nrepartidor,n,01,repartidores);

}
void imprimirCola_R(colaRepartidores*cola)
{
    printf("*****REPARTIDORES DISPONBLES******\n");
    repartidor *r=cola;
    r = cola->inicio;
    while (r!=NULL) {
        printf("|+NOMBRE: %s\n",r->nrepartidor);
        printf("|+ID: %.0lf\n",r->id);
        r = r->sig;
    }
}
