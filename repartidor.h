#ifndef REPARTIDOR_H_INCLUDED
#define REPARTIDOR_H_INCLUDED

typedef struct repartidor{
    char nrepartidor[20];
    double id;
    struct repartidor *sig;
}repartidor;

typedef struct colaRepartidores{
    struct repartidor*inicio;
    struct repartidor*fin;
    int n;
}colaRepartidores;

int colaVacia_R(colaRepartidores*repartidor);
colaRepartidores *nuevaColaR(void);
repartidor*crear_3(char nrepartidor[],int n,double id);
void agregaDatoCola_R(char nrepartidor[],int n,double id,colaRepartidores*disponibles);
void llenarRepartidores(colaRepartidores*repartidores);
void imprimirCola_R(colaRepartidores*cola);


#endif // REPARTIDOR_H_INCLUDED
