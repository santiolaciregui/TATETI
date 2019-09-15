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
    (*nuevo).elemento=e;
    (*nuevo).siguiente=(*p).siguiente;
    (*p).siguiente=nuevo;
}

/**
 Elimina la celda P de L. El elemento almacenado en la posici�n P es eliminado mediante la funci�n fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento)){
}

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la funci�n fEliminar parametrizada.
**/
void l_destruir(tLista * l, void (*fEliminar)(tElemento));

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
    tPosicion aux = l->siguiente;
    return l->siguiente;
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
    if(p==l->siguiente)
        exit(LST_NO_EXISTE_ANTERIOR);
    return p;
}
 /**
 Recupera y retorna la �ltima posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_ultima(tLista l){
    tPosicion aux = (*l).siguiente;
    while((*aux).siguiente!=NULL)
        aux=(*aux).siguiente;
    return aux;
}

 /**
 Recupera y retorna la posici�n fin de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_fin(tLista l){
    tPosicion aux = (*l).siguiente;
    while(aux!=NULL)
        aux=(*aux).siguiente;
    return aux;
}

/**
 Retorna la longitud actual de la lista.
**/
int l_longitud(tLista l) {
    int contador=0;
    tPosicion aux = (*l).siguiente;
    while(aux!=NULL) {
        contador++;
        aux=(*aux).siguiente;
    }
    return contador;
}

int main(){
    tLista l;
    crear_lista(&l);
    tElemento e=(tElemento) 100;
    l_insertar(l, &(*l), e);
    printf("%i \n", l_primera(l)->elemento);
    printf("%i", l_longitud(l));
    printf("ee");

}


