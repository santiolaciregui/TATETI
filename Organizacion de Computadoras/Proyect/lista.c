#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
/**
 Inicializa una lista vac�a.
 Una referencia a la lista creada es referenciada en *L.
**/
void crear_lista(tLista * l){
    (*l)=(struct celda*)malloc(sizeof(struct celda));
    (*l)->elemento=NULL;
    (*l)->siguiente=NULL;
}

/**
 Inserta el elemento E, en la posici�n P, en L.
 Con L = A,B,C,D y la posici�n P direccionando C, luego:
 L' = A,B,E,C,D
**/
void l_insertar(tLista l, tPosicion p, tElemento e){
    struct celda *nuevo=(struct celda*)malloc(sizeof(struct celda));
    nuevo->elemento=e;
    nuevo->siguiente=p->siguiente;
    p->siguiente=nuevo;
}

/**
 Elimina la celda P de L. El elemento almacenado en la posici�n P es eliminado mediante la funci�n fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento)){
    tPosicion aux;
    if(p->siguiente==NULL)
        exit(LST_POSICION_INVALIDA);
    fEliminar(p->siguiente->elemento);
    aux = p->siguiente;
    p->siguiente=p->siguiente->siguiente;
    aux->elemento=NULL;
    aux->siguiente=NULL;
    free(aux);
}

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la funci�n fEliminar parametrizada.
**/
void l_destruir(tLista * l, void (*fEliminar)(tElemento)){
    tPosicion aux;
    while((*l)->siguiente!=NULL){
        aux= (*l)->siguiente;
        fEliminar(aux->elemento);
        aux->elemento=NULL;
        (*l)->siguiente=aux->siguiente;
        aux->siguiente=NULL;
        free(aux);
    }
    free(l);
}

 /**
 Recupera y retorna el elemento en la posici�n P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
tElemento l_recuperar(tLista l, tPosicion p){
    if(p->siguiente==NULL)
        exit (LST_POSICION_INVALIDA);
    return p->siguiente->elemento;
}

/**
 Recupera y retorna la primera posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_primera(tLista l){
    return l;
}
/**
 Recupera y retorna la posici�n siguiente a P en L.
 Si P es fin(L), finaliza indicando LST_NO_EXISTE_SIGUIENTE.
**/
tPosicion l_siguiente(tLista l, tPosicion p){
    if (p->siguiente==NULL)
        exit(LST_NO_EXISTE_SIGUIENTE);
    return p->siguiente;
}

/**
 Recupera y retorna la posici�n anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
tPosicion l_anterior(tLista l, tPosicion p){
    tPosicion aux=l;
    if(p==l)
        exit(LST_NO_EXISTE_ANTERIOR);
    while(aux!=NULL && aux->siguiente!=p){
        aux=aux->siguiente;
    }
    return aux;
}
 /**
 Recupera y retorna la �ltima posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_ultima(tLista l){
    tPosicion aux = l;
    if(aux->siguiente!=NULL)
        while(aux->siguiente->siguiente!=NULL)
            aux=aux->siguiente;
    return aux;
}

 /**
 Recupera y retorna la posici�n fin de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_fin(tLista l){
    tPosicion aux = l;
    while(aux->siguiente!=NULL)
        aux=aux->siguiente;
    return aux;
}

/**
 Retorna la longitud actual de la lista.
**/
int l_longitud(tLista l) {
    int contador=0;
    tPosicion aux = l->siguiente;
    while(aux!=NULL) {
        contador++;
        aux=aux->siguiente;
    }
    return contador;
}

void generarElementos(tLista l)
{
    int *e;
    int i;
    srand(20);
    i= 0;
    printf("Elementos generados: ");
    while(i<10){
        e= (int*)malloc(sizeof(int));
        *e= rand()%30;
        printf("%i ", *e);
        l_insertar(l,l_primera(l), e);
        i++;
    }
    printf("\n");
}

void mostrarElementos(tLista l){
    tPosicion aux;
    int i;
    int *e;
    i=0;
    aux=l;
    printf("[ ");
    if(l->siguiente==NULL )
        printf("La lista l no posee elementos.");
    else
        while(aux->siguiente!=NULL){
            e= aux->siguiente->elemento;
            printf("%i ", *e);
            aux= aux->siguiente;
            i++;
        }
    printf(" ]");
}

int main()
{
    tLista lista = NULL;

    int x;

    printf("Elija una opcion:\n");
    printf("1: Crear lista de enteros\n");
    printf("5: Salir\n");
    printf("\n");
    printf("OPCION: ");
    scanf("%i",&x);

     while(x > 0 && x < 9) {
        if(x == 1) {
            crear_lista(&lista);
            printf("\n");
            printf("LISTA CREADA\n" );
            printf("\n");
            printf("Elija una opcion:\n");
            printf("1: Crear lista de enteros\n");
            printf("2: Insertar entero al final\n");
            printf("3: Insertar entero al inicio\n");
            printf("4: Imprimir la lista por pantalla\n");
            printf("5: Salir y destruir\n");
            printf("\n");
            printf("OPCION: ");
        }
        if(x == 2) {
            printf("\n");
            printf("Ingrese el entero que desee agregar:");
            int * entero;
            int auxEntero;
            scanf("%i",&auxEntero);
            entero = (int*)malloc(sizeof(int));
            *entero = auxEntero;
            l_insertar(lista,l_fin(lista),entero);
            printf("\n");
            printf("ELEMENTO INSERTADO AL FINAL.");
            printf("\n");
            printf("\n");
            printf("Elija una opcion:\n");
            printf("1: Crear lista de enteros\n");
            printf("2: Insertar entero al final\n");
            printf("3: Insertar entero al inicio\n");
            printf("4: Imprimir la lista por pantalla\n");
            printf("5: Salir y destruir\n");
            printf("6: Eliminar el ultimo entero\n");
            printf("7: Eliminar el primer entero\n");
            printf("8: Longitud de la lista\n");
            printf("\n");
            printf("OPCION: ");

        }
        if(x == 3) {
            printf("\n");
            printf("Ingrese el entero que desee agregar:");
            int * entero;
            int auxEntero;
            scanf("%i",&auxEntero);
            entero = (int*)malloc(sizeof(int));
            *entero = auxEntero;
            l_insertar(lista,l_primera(lista),entero);
            printf("\n");
            printf("ELEMENTO INSERTADO AL PRINCIPIO.");
            printf("\n");
            printf("\n");
            printf("Elija una opcion:\n");
            printf("1: Crear lista de enteros\n");
            printf("2: Insertar entero al final\n");
            printf("3: Insertar entero al inicio\n");
            printf("4: Imprimir la lista por pantalla\n");
            printf("5: Salir y destruir\n");
            printf("6: Eliminar el ultimo entero\n");
            printf("7: Eliminar el primer entero\n");
            printf("8: Longitud de la lista\n");
            printf("\n");
            printf("OPCION: ");

        }
        if (x == 4){
            printf("\n");
            printf("La lista es: ");
            tPosicion aux;
            int i;
            int *e;
            i = 0;
            aux = lista;
            printf("[ ");

            if(lista -> siguiente == NULL)
                printf("La lista no posee elementos. \n");
            else {
                while(aux -> siguiente != NULL) {
                    e = aux -> siguiente -> elemento;
                    printf("%i ", *e);
                    aux = aux -> siguiente;
                    i++;
                }
            }
            printf("]");
            printf("\n");
            printf("\n");
            printf("Elija una opcion:\n");
            printf("1: Crear lista de enteros\n");
            printf("2: Insertar entero al final\n");
            printf("3: Insertar entero al inicio\n");
            printf("4: Imprimir la lista por pantalla\n");
            printf("5: Salir y destruir\n");
            printf("6: Eliminar el ultimo entero\n");
            printf("7: Eliminar el primer entero\n");
            printf("8: Longitud de la lista\n");
            printf("\n");
            printf("OPCION: ");
        }
        if(x == 5) {
           l_destruir(&lista,free);
           printf("LISTA DESTRUIDA");
           printf("\n");
           printf("\n");
        }
        if(x == 6) {
            l_eliminar(lista,l_ultima(lista),free);
            printf("\n");
            printf("ULTIMO ELEMENTO ELIMINADO.");
            printf("\n");
            printf("\n");
            printf("Elija una opcion:\n");
            printf("1: Crear lista de enteros\n");
            printf("2: Insertar entero al final\n");
            printf("3: Insertar entero al inicio\n");
            printf("4: Imprimir la lista por pantalla\n");
            printf("5: Salir y destruir\n");
            printf("6: Eliminar el ultimo entero\n");
            printf("7: Eliminar el primer entero\n");
            printf("8: Longitud de la lista\n");
            printf("\n");
            printf("OPCION: ");
        }
        if(x == 7) {
            l_eliminar(lista,l_primera(lista),free);
            printf("\n");
            printf("PRIMER ELEMENTO ELIMINADO.");
            printf("\n");
            printf("\n");
            printf("Elija una opcion:\n");
            printf("1: Crear lista de enteros\n");
            printf("2: Insertar entero al final\n");
            printf("3: Insertar entero al inicio\n");
            printf("4: Imprimir la lista por pantalla\n");
            printf("5: Salir y destruir\n");
            printf("6: Eliminar el ultimo entero\n");
            printf("7: Eliminar el primer entero\n");
            printf("8: Longitud de la lista\n");

            printf("\n");
            printf("OPCION: ");
        }
        if(x==8){
            printf("La longitud de la lista es: ");
            printf("%i", l_longitud(lista));
            printf("\n");
            printf("\n");
            printf("Elija una opcion:\n");
            printf("1: Crear lista de enteros\n");
            printf("2: Insertar entero al final\n");
            printf("3: Insertar entero al inicio\n");
            printf("4: Imprimir la lista por pantalla\n");
            printf("5: Salir y destruir\n");
            printf("6: Eliminar el ultimo entero\n");
            printf("7: Eliminar el primer entero\n");
            printf("8: Longitud de la lista\n");

            printf("\n");
            printf("OPCION: ");
        }
        scanf("%i",&x);
    }
}



