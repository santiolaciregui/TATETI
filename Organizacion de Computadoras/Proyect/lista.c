#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void crear_lista(tLista * l){
    (*l)=(struct celda*)malloc(sizeof(struct celda));
    (*l)->elemento=NULL;
    (*l)->siguiente=NULL;
}

void l_insertar(tLista l, tPosicion p, tElemento e){
    struct celda *nuevo=(struct celda*)malloc(sizeof(struct celda));
    (*nuevo).elemento=e;
    (*nuevo).siguiente=(*p).siguiente;
    (*p).siguiente=nuevo;
}


int main(){
    tLista *l;
    crear_lista(&l);
    int eme=10;
    l_insertar(&l, &l.siguiente, eme);
}

