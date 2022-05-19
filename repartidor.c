#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "repartidor.h"

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
    repartidor*r=crear_3(nrepartidor,n,id);//se crea la estructura(repartidor) con los datos a llenar
    /*se comprueba si la cola está vacía, si lo está agrega el repartidor al inicio de la cola*/
    if(colaVacia_R(disponibles)){
        /*al principio siempre entrará una sola vez a este 'if' porque cuando se crea la cola, se crea vacia*/
        disponibles->inicio=disponibles->fin=r;
        disponibles->n=1;
        return;
    }
    /*despues de añadir el primer repartidor a la cola,
    ahora (que la cola ya no está vacía) realiza el siguiente codigo
    donde los repartidores se agregan al final de la cola*/
    /*cabe recalcar que aqui son solo los ENLACES entre los nodos
    de la cola, la estructura repartidor ya fue creada anteriormente,
    aquí solo se realizan los ENLACES correspondientes para añadir
    ese repartidor a la cola*/
    disponibles->fin->sig=r;
    disponibles->fin=r;
    disponibles->n+=1;

    return;
}
void llenarRepartidores(colaRepartidores*repartidores)
{
    int n=20;
    /*se hace el llamado a la funcion agregaDatoCola_R() para
    llenar mi cola de epartidores disponibles*/
    agregaDatoCola_R("Raymundo Jimenez",n,05,repartidores);
    agregaDatoCola_R("Santiago Carrillo",n,13,repartidores);
    agregaDatoCola_R("Jose Gonzalez",n,11,repartidores);
    agregaDatoCola_R("Patricio Espindola",n,69,repartidores);
    agregaDatoCola_R("Gabriel Gutierrez",n,420,repartidores);
    agregaDatoCola_R("Christopher Sanchez",n,01,repartidores);

}
void imprimirCola_R(colaRepartidores*cola)
{
    printf("*****REPARTIDORES DISPONBLES******\n");
    repartidor *r;
    r = cola->inicio;
    while (r!=NULL) {
        printf("|+NOMBRE: %s\n",r->nrepartidor);
        printf("|+ID: %.0lf\n",r->id);
        r = r->sig;
    }
}
