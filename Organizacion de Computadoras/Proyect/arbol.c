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
    tLista listaHijos;
    tNodo nuevo;
    tPosicion puntero;
    tPosicion finDeHermanos;
    if(np==NULL)
        exit(ARB_POSICION_INVALIDA);
    hermanos = np->hijos;
    nuevo = (tNodo) malloc(sizeof(struct nodo));
    if ((nuevo == NULL)||(nuevo == 0))
        exit(ARB_ERROR_MEMORIA);
    crear_lista(&listaHijos);
    nuevo->elemento = e;
    nuevo->padre = np;
    nuevo->hijos = listaHijos;
    puntero= l_primera(hermanos);
    finDeHermanos=l_fin(hermanos);
    if(nh!=NULL){
       while(puntero!=finDeHermanos && l_recuperar(hermanos,puntero)!=nh)
                puntero=l_siguiente(hermanos,puntero);
        if(puntero==finDeHermanos)
            exit(ARB_POSICION_INVALIDA);
    }
    else
        puntero = l_ultima(hermanos);
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
    int corte;
    int longitudHijos;
    hijosDeN= n->hijos;
    if(n==a->raiz){
        longitudHijos = l_longitud(hijosDeN);
        if(longitudHijos>1)
            exit(ARB_OPERACION_INVALIDA);
        else
            if(longitudHijos==1)
                a->raiz=(tNodo)l_recuperar(hijosDeN,l_primera(hijosDeN));
    }
    else {
        PadreDeN = n->padre;
        HermanosDeN = PadreDeN->hijos;
        punteroHermanos = l_primera(HermanosDeN);
        punteroHijos = l_ultima(hijosDeN);
        finHermanosN = l_fin(HermanosDeN);
        corte=0;
        while(punteroHermanos!=finHermanosN && l_recuperar(HermanosDeN,punteroHermanos)!=n)
            punteroHermanos = l_siguiente(HermanosDeN, punteroHermanos);
        while(corte==0) {
            l_insertar(HermanosDeN, l_siguiente(HermanosDeN, punteroHermanos),l_recuperar(hijosDeN,punteroHijos));
            if(punteroHijos==l_primera(hijosDeN))
                corte=1;
            else
                punteroHijos=l_anterior(hijosDeN, punteroHijos);
        }
        l_eliminar(HermanosDeN, punteroHermanos, eliminar_nodo);
    }
    fEliminar(n->elemento);
    l_destruir(&hijosDeN,eliminar_nodo);
//    n->hijos=NULL;
    n->padre=NULL;
//    n->elemento=NULL;
    free(n);
//    n=NULL;
}

void preordenAux(tArbol a, tNodo n, void (*fEliminar)(tElemento)){
    tPosicion punteroHijosDeN;
    tPosicion findeHijosdeN;
    punteroHijosDeN= l_primera(n->hijos);
    findeHijosdeN=l_fin(n->hijos);
    while(punteroHijosDeN!=findeHijosdeN){
        preordenAux(a, l_recuperar(n->hijos, punteroHijosDeN), fEliminar);
        punteroHijosDeN=l_siguiente(n->hijos, punteroHijosDeN);
	}
	a_eliminar(a, n, fEliminar);
 }
/**
 Destruye el �rbol A, eliminando cada uno de sus nodos.
 Los elementos almacenados en el �rbol son eliminados mediante la funci�n fEliminar parametrizada.
**/
 void a_destruir(tArbol * a, void (*fEliminar)(tElemento)){
    preordenAux(*a,(*a)->raiz, fEliminar);
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
void preorder_cortar(tArbol a, tNodo n, tNodo d) {
    tPosicion puntero = l_primera(n->hijos);
    while (puntero != l_fin(n->hijos))
    {
        printf("aaa ");
        tNodo nuevo = (tNodo) malloc(sizeof(struct nodo));
    if ((nuevo == 0) || (nuevo == NULL))
        exit(ARB_ERROR_MEMORIA);
    crear_lista(&(nuevo->hijos));
    nuevo->elemento = l_recuperar(n->hijos, puntero);
    nuevo->padre = d;
        l_insertar(d->hijos, l_ultima(d->hijos), nuevo);
        printf("bbb ");
        preorder_cortar(a, l_recuperar(n->hijos, puntero), l_recuperar(d->hijos, l_ultima(d->hijos)));
        printf("ccc ");
        puntero = l_siguiente(n->hijos, puntero);
        printf("ddd ");
    }
    a_eliminar(a, n, eliminar_nodo);
}
void a_sub_arbol(tArbol a, tNodo n, tArbol * sa) {
    crear_arbol(sa);
    crear_raiz((*sa), a_recuperar(a, n));
    preorder_cortar(a, n, (*sa)->raiz);
}

// void a_sub_arbol(tArbol a, tNodo n, tArbol * sa){
//     tLista hermanosDeN;
//     tPosicion puntero;
//     tPosicion finDeHermanos;
//     int corte;
//     hermanosDeN=n->padre->hijos;
//     puntero= l_primera(hermanosDeN);
//     corte=0;
//     finDeHermanos = l_fin(hermanosDeN);
//     while(puntero!=finDeHermanos && corte==0){
//        if(l_recuperar(hermanosDeN,puntero)==n){
//            corte=1;
//            l_eliminar(hermanosDeN, puntero, eliminar_nodo);
//        }
//        puntero=l_siguiente(hermanosDeN, puntero);
//     }
//      SI NO ENCUENTRO A N EN LA LISTA DE HIJOS DEL PADRE DE N
//     if(puntero==finDeHermanos)
//        exit(ARB_POSICION_INVALIDA);
//     crear_arbol(sa);
//     n->padre=NULL;
//     crear_raiz(*(sa), n->elemento);
// }



