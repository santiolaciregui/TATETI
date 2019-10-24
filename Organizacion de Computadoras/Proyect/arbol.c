#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

void eliminar_nodo(void* e) {}

/**
Inicializa un �rbol vac�o.
Una referencia al �rbol creado es referenciado en *A.
**/
 void crear_arbol(tArbol * a){
    (*a)= (struct arbol*)malloc(sizeof(struct arbol));
    if((*a)==NULL)
        exit(ARB_ERROR_MEMORIA);
    (*a)->raiz=NULL;
}

/**
Crea la ra�z de A.
Si A no es vac�o, finaliza indicando ARB_OPERACION_INVALIDA.
**/
 void crear_raiz(tArbol a, tElemento e){
    if(a->raiz!=NULL)
        exit(ARB_OPERACION_INVALIDA);
    tNodo nodo= (tNodo)malloc(sizeof(struct nodo));
    if(nodo==NULL || nodo==0)
        exit(ARB_ERROR_MEMORIA);
    crear_lista(&(nodo->hijos));
    nodo->padre=NULL;
    nodo->elemento=e;
    a->raiz = nodo;
}

/**
 Inserta y retorna un nuevo nodo en A.
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo r�tulo es E.
 Si NH es NULL, el nuevo nodo se agrega como �ltimo hijo de NP.
 Si NH no corresponde a un nodo hijo de NP, finaliza indicando ARB_POSICION_INVALIDA.
 NP direcciona al nodo padre, maientras NH al nodo hermano derecho del nuevo nodo a insertar.
**/
 tNodo a_insertar(tArbol a, tNodo np, tNodo nh, tElemento e){
    tLista hermanos;
    tNodo nuevo;
    tPosicion puntero;
    tPosicion finDeHermanos;
    if(np==NULL)
        exit(ARB_POSICION_INVALIDA);
    hermanos = np->hijos;
    nuevo = (tNodo) malloc(sizeof(struct nodo));
    if ((nuevo == NULL)||(nuevo == 0))
        exit(ARB_ERROR_MEMORIA);
    crear_lista(&(nuevo->hijos));
    nuevo->elemento = e;
    nuevo->padre = np;
    puntero= l_primera(hermanos);
    finDeHermanos=l_fin(hermanos);
    if(nh!=NULL){
       while(puntero!=finDeHermanos && l_recuperar(hermanos,puntero)!=nh)
                puntero=l_siguiente(hermanos,puntero);
        if(puntero==finDeHermanos)
            exit(ARB_POSICION_INVALIDA);
    }
    else
        puntero = l_fin(hermanos);
    l_insertar(hermanos,puntero,nuevo);
    return nuevo;
 }

/**
 Elimina el nodo N de A.
 El elemento almacenado en el �rbol es eliminado mediante la funci�n fEliminar parametrizada.
 Si N es la ra�z de A, y tiene un s�lo hijo, este pasa a ser la nueva ra�z del �rbol.
 Si N es la ra�z de A, y a su vez tiene m�s de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la ra�z de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posici�n que ocupa N en la lista de hijos de su padre.
**/
  void a_eliminar(tArbol a, tNodo n, void (*fEliminar)(tElemento)) {
    tLista hijosDeN;
    tNodo PadreDeN;
    tLista HermanosDeN;
    tPosicion punteroHermanos;
    tPosicion punteroHijos;
    tPosicion finHermanosN;
    tPosicion finHijosdeN;
    int longitudHijos;
    hijosDeN= n->hijos;
    if(n==a->raiz){
        longitudHijos = l_longitud(hijosDeN);
        if(longitudHijos>1)
            exit(ARB_OPERACION_INVALIDA);
        else
            if(longitudHijos==1){
                a->raiz=(tNodo)l_recuperar(hijosDeN,l_primera(hijosDeN));
                a->raiz->padre=NULL;
            }
    }
    else {
        PadreDeN = n->padre;
        HermanosDeN = PadreDeN->hijos;
        punteroHermanos = l_primera(HermanosDeN);
        finHermanosN = l_fin(HermanosDeN);
        punteroHijos = l_primera(hijosDeN);
        finHijosdeN=l_fin(hijosDeN);
        while(punteroHermanos!=finHermanosN && l_recuperar(HermanosDeN,punteroHermanos)!=n)
            punteroHermanos = l_siguiente(HermanosDeN, punteroHermanos);
        if(punteroHermanos==finHermanosN)
            exit(ARB_POSICION_INVALIDA);
        while(punteroHijos!=finHijosdeN) {
            tNodo nuevoHijo = l_recuperar(hijosDeN,punteroHijos);
            nuevoHijo->padre = PadreDeN;
            l_insertar(HermanosDeN, punteroHermanos,nuevoHijo);
            punteroHijos=l_siguiente(hijosDeN, punteroHijos);
            punteroHermanos = l_siguiente(HermanosDeN, punteroHermanos);
        }
        l_eliminar(HermanosDeN, punteroHermanos, eliminar_nodo);
    }
    fEliminar(n->elemento);
    l_destruir(&hijosDeN,eliminar_nodo);
    n->hijos=NULL;
    n->padre=NULL;
    n->elemento=NULL;
    free(n);
    n=NULL;
}

/**
 Destruye el �rbol A, eliminando cada uno de sus nodos.
 Los elementos almacenados en el �rbol son eliminados mediante la funci�n fEliminar parametrizada.
**/
void posOrdenAux(tArbol a, tNodo n, void (*fEliminar)(tElemento)){
    tPosicion punteroHijosDeN = l_primera(n->hijos);
    while(punteroHijosDeN!=l_fin(n->hijos))
        posOrdenAux(a, l_recuperar(n->hijos, punteroHijosDeN), fEliminar);
	a_eliminar(a, n, fEliminar);
 }
 void a_destruir(tArbol * a, void (*fEliminar)(tElemento)){
    posOrdenAux(*a,(*a)->raiz, fEliminar);
    (*a)->raiz = NULL;
    free(*a);
    (*a) = NULL;
 }

/**
Recupera y retorna el elemento del nodo N.
*/
 tElemento a_recuperar(tArbol a, tNodo n){
     if(n==NULL)
        exit(ARB_OPERACION_INVALIDA);
    return n->elemento;
 }

/**
Recupera y retorna el nodo correspondiente a la ra�z de A.
**/
tNodo a_raiz(tArbol a){
    return a->raiz;
}

/**
 Obtiene y retorna una lista con los nodos hijos de N en A.
**/
tLista a_hijos(tArbol a, tNodo n){
    return n->hijos;
}

/**
 Inicializa un nuevo �rbol en *SA.
 El nuevo �rbol en *SA se compone de los nodos del sub�rbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
 void a_sub_arbol(tArbol a, tNodo n, tArbol * sa){
     tLista hermanosDeN;
     tPosicion puntero;
     tPosicion finDeHermanos;
     crear_arbol(sa);
     crear_raiz(*sa, n->elemento);
     (*sa)->raiz->hijos=n->hijos;
     if(n!=a->raiz){
         hermanosDeN=n->padre->hijos;
         puntero= l_primera(hermanosDeN);
         finDeHermanos = l_fin(hermanosDeN);
         while(puntero!=finDeHermanos && l_recuperar(hermanosDeN,puntero)!=n)
            puntero=l_siguiente(hermanosDeN, puntero);
         // SI NO ENCUENTRO A N EN LA LISTA DE HIJOS DEL PADRE DE N
        if(puntero==finDeHermanos)
            exit(ARB_POSICION_INVALIDA);
        l_eliminar(hermanosDeN, puntero, eliminar_nodo);
        n->padre=NULL;
     }
 }
