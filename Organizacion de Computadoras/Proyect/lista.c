#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void fEliminarEnteros (tElemento e);

/**
 Inicializa una lista vac�a.
 Una referencia a la lista creada es referenciada en *L.
**/
void crear_lista(tLista * l){
    (*l)=malloc(sizeof(tLista));
    if((*l)==NULL)
        exit(LST_ERROR_MEMORIA);
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
    if(nuevo==NULL)
        exit(LST_ERROR_MEMORIA);
    nuevo->elemento=e;
    nuevo->siguiente=p->siguiente;
    p->siguiente=nuevo;
}

/**
 Elimina la celda P de L. El elemento almacenado en la posici�n P es eliminado mediante la funci�n fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento)){
    tPosicion aEliminar;

    // SI NO ES EL FIN
    if(p->siguiente==NULL)
        exit(LST_POSICION_INVALIDA);


    aEliminar = p->siguiente;
    fEliminar(aEliminar->elemento);

    p->siguiente=p->siguiente->siguiente;
    aEliminar->elemento=NULL;
    aEliminar->siguiente=NULL;
    free(aEliminar);
}

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la funci�n fEliminar parametrizada.
**/
void l_destruir(tLista * l, void (*fEliminar)(tElemento)){
    tPosicion header, posSiguiente;
    header = (*l);
    while(header->siguiente!=NULL){
        posSiguiente= header->siguiente;
        fEliminar(posSiguiente->elemento);
        posSiguiente->elemento=NULL;
        header->siguiente=posSiguiente->siguiente;
        posSiguiente->siguiente=NULL;
        free(posSiguiente);
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

void invertir_lista(tLista l){
    tPosicion head=l->siguiente;
    tPosicion actual=head;
    tPosicion anterior=NULL;
    tPosicion siguiente=NULL;
    while(actual!=NULL){
        siguiente=actual->siguiente;
        actual->siguiente=anterior;
        anterior=actual;
        actual=siguiente;
    }
    head= anterior;
    l->siguiente=head;
}




