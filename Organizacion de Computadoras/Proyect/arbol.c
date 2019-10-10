#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

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
    struct nodo *nodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(nodo==NULL || nodo==0)
        exit(ARB_ERROR_MEMORIA);
    tLista listaHijos=malloc(sizeof(tLista));
    crear_lista(&listaHijos);
    nodo->padre=NULL;
    nodo->elemento=e;
    nodo->hijos=listaHijos;
}

/**
 Inserta y retorna un nuevo nodo en A.
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo r�tulo es E.
 Si NH es NULL, el nuevo nodo se agrega como �ltimo hijo de NP.
 Si NH no corresponde a un nodo hijo de NP, finaliza indicando ARB_POSICION_INVALIDA.
 NP direcciona al nodo padre, maientras NH al nodo hermano derecho del nuevo nodo a insertar.
**/
 tNodo a_insertar(tArbol a, tNodo np, tNodo nh, tElemento e){
    tLista hermanos = &(np->hijos);
    tNodo nuevo = (tNodo) malloc(sizeof(struct nodo));
    if ((nuevo == NULL)||(nuevo == 0))
        exit(ARB_ERROR_MEMORIA);
    tLista listaHijos;
    crear_lista(&listaHijos);
    nuevo->elemento = e;
    nuevo->padre = np;
    nuevo->hijos = listaHijos;
    tPosicion puntero= l_primera(&hermanos);
    if(nh!=NULL)
       while(puntero!=NULL && l_recuperar(&hermanos,&puntero)!=nh)
                puntero=puntero->siguiente;
    if(puntero==l_fin(&hermanos))
        exit(ARB_POSICION_INVALIDA);
    l_insertar(&hermanos,&puntero,nuevo);
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
    if(n==a->raiz)
        if(n->hijos->siguiente!=NULL)
            if(n->hijos->siguiente->siguiente==NULL)
                a->raiz=n->hijos->siguiente;
            else
                exit(ARB_OPERACION_INVALIDA);
        else
            fEliminar(n);
    else {
        tNodo PadreDeN = n->padre;
        tLista HermanosDeN = PadreDeN->hijos;
        tPosicion punteroHermanos = HermanosDeN->siguiente;
        while(punteroHermanos!=NULL) {
            if(punteroHermanos->elemento==n) {
                tLista HijosDeN = n->hijos;
                tPosicion PunteroHijos = HijosDeN->siguiente;
                while(PunteroHijos!=NULL) {
                    tPosicion punteroAux = punteroHermanos->siguiente->siguiente;
                    punteroHermanos->siguiente = PunteroHijos;
                    punteroHermanos =PunteroHijos->siguiente;
                    PunteroHijos->siguiente = punteroAux;
                }
            }
        }

    }
}

/**
 Destruye el �rbol A, eliminando cada uno de sus nodos.
 Los elementos almacenados en el �rbol son eliminados mediante la funci�n fEliminar parametrizada.
**/
 void a_destruir(tArbol * a, void (*fEliminar)(tElemento));

/**
Recupera y retorna el elemento del nodo N.
*/
 tElemento a_recuperar(tArbol a, tNodo n){
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
// void a_sub_arbol(tArbol a, tNodo n, tArbol * sa){
//     tLista hijosPadreDeN=n->padre->hijos;
//     tPosicion puntero= l_primera(hijosPadreDeN);
//     int corte=0;
//     while(puntero!=NULL && corte==0){
//        if(puntero->elemento==n){
//            corte=1;
//            l_eliminar(hijosPadreDeN, puntero, &fEliminar(tElemento));
//        }
//        puntero=l_siguiente(hijosPadreDeN, puntero);
//     }
//     // SI NO ENCUENTRO A N EN LA LISTA DE HIJOS DEL PADRE DE N
//     if(puntero==NULL)
//        exit(ARB_POSICION_INVALIDA);
//     n->padre=NULL;
//     (*sa)->raiz=n;
// }
