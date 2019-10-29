#include "lista.h"
#include "arbol.h"
#include "partida.h"
#include <stdlib.h>
#include <stdio.h>

#define PART_JUGADOR_1                      100
#define PART_JUGADOR_2                      101
#define PART_JUGADOR_RANDOM                 102

#define PART_MODO_USUARIO_VS_USUARIO        103
#define PART_MODO_USUARIO_VS_AGENTE_IA      104
#define PART_MODO_AGENTE_IA_VS_AGENTE_IA    105

#define PART_MOVIMIENTO_OK                  106
#define PART_MOVIMIENTO_ERROR               107
#define PART_SIN_MOVIMIENTO                 108
#define PART_GANA_JUGADOR_1                 109
#define PART_GANA_JUGADOR_2                 110
#define PART_EN_JUEGO                       111
#define PART_EMPATE                         112

#define PART_ERROR_MEMORIA                  113

void mostrarMatriz(tPartida p) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(p->tablero->grilla[i][j] + " ");
        }
        printf(" ");
    }
}

int main(){
    tPartida p;
    int modoPartida;
    int comienza;
    int x;
    int y;
    char nombreJ1[51];
    char nombreJ2[51];
    printf("Como quiere jugar la partida? 103=Usuario vs Usuario o 104=Usuario vs Computadora: ");
    scanf("%i", &modoPartida);
    if(modoPartida!= PART_MODO_USUARIO_VS_USUARIO && modoPartida!= PART_MODO_USUARIO_VS_AGENTE_IA){
        printf("Modo incorrecto. Elija alguno de los mencionados anteriormente: ");
        scanf("%i", &modoPartida);
    }

    printf("Quien va a iniciar jugando la partida? 100=Jugador1, 101=Jugador2 o 102=Al azar: ");
    scanf("%i", &comienza);
    if(comienza!=PART_JUGADOR_1 && comienza!=PART_JUGADOR_2 && comienza!= PART_JUGADOR_RANDOM){
        printf("Eleccion incorrecta. Elija alguno de los mencionados anteriormente: ");
        scanf("%i", &comienza);
    }

    printf("Como se llamara el Jugador 1: ");
    scanf("%s",nombreJ1);
    printf("Como se llamara el Jugador 2: ");
    scanf("%s",nombreJ2);
    nueva_partida(&p,modoPartida,comienza,nombreJ1,nombreJ2);
    printf("%s", p->nombre_jugador_1);
    while(p->estado==PART_EN_JUEGO){
        printf("Donde desea jugar?: ");
        scanf("%i : %i", &x, &y);
        if(x<1 || x>3 || y<1 || y>3)
            printf("Movimiento Incorrecto. Vuelva a elegir de forma correcta donde jugar(por ej, 1:3): ");
        else
            nuevo_movimiento(p, x, y);
            mostrarMatriz(p);
    }



return 0;
}




















//void fEliminarEnteros (tElemento e){
//    int * elemento = (int *) e;
//    *elemento = -1;
//    free(elemento);
//}
//
//tLista sumarPrimerElementoConUltimo(tLista lis1, tLista lis2){
//        tLista nueva=NULL;
//        crear_lista(&nueva);
//        while(l_longitud(lis1)>0 && l_longitud(lis2)>0){
//            tPosicion plis1=l_primera(lis1);
//            tPosicion plis2=l_ultima(lis2);
//            int elemento1=(int) plis1->elemento;
//            int elemento2=(int) plis2->elemento;
//            l_insertar(nueva, l_primera(nueva),(int*)(elemento1+elemento2));
//            l_eliminar(lis1,plis1,&fEliminarEnteros);
//            l_eliminar(lis2, plis2, &fEliminarEnteros);
//        }
//        return nueva;
//    }
//void mostrarlista(tLista lista){
//    printf("\n");
//            printf("La lista es: ");
//            tPosicion aux;
//            int i;
//            int *e;
//            i = 0;
//            aux = lista;
//            printf("[ ");
//
//            if(lista -> siguiente == NULL)
//                printf("La lista no posee elementos. ");
//            else {
//                while(aux -> siguiente != NULL) {
//                    e = aux -> siguiente -> elemento;
//                    printf("%i ", *e);
//                    aux = aux -> siguiente;
//                    i++;
//                }
//            }
//            printf("]");
//            printf("\n");
//}
//
//void preorden(tArbol a, tNodo root){
//    tPosicion punteroHijosDeN= l_primera(root->hijos);
//    tPosicion findeHijosdeN=l_fin(root->hijos);
//    printf("%i ",*((int*)root->elemento));
//    while(punteroHijosDeN!=findeHijosdeN){
//        punteroHijosDeN=l_siguiente(root->hijos, punteroHijosDeN);
//        preorden(a, punteroHijosDeN->elemento);
//    }
//}
//
//int main(){
////  -------------------------- TESTER ARBOL -------------------------
////  -------------------------- TESTER ARBOL -------------------------
////  -------------------------- TESTER ARBOL -------------------------
//
//    tArbol arbol;
//    crear_arbol(&arbol);
//    int r1=1;
//    int r2= 2;
//    int r3= 3;
//    int r4= 4;
//    int r5= 5;
//    crear_raiz(arbol, &r1);
//    printf("RAIZ CREADA CON ELEMENTO>%i\n",r1);
//    tNodo aux=a_insertar(arbol,arbol->raiz, NULL, &r2);
//    printf("INSERTAR1 ELEMENTO>%i\n",r2);
//    tNodo aux1=a_insertar(arbol,aux, NULL, &r3);
//    printf("INSERTAR2 ELEMENTO>%i\n",r3);
//    a_insertar(arbol,aux, aux1, &r4);
//    printf("INSERTAR3 ELEMENTO>%i\n",r4);
//    a_insertar(arbol, aux, NULL, &r5 );
//    printf("INSERTAR4 ELEMENTO>%i\n",r5);
//    printf("IMPRESION EN PREORDEN: ");
//    preorden(arbol, arbol->raiz);
//    printf("\n");
////
////    printf("Eliminar %i\n",r3);
////    a_eliminar(arbol,aux1,&fEliminarEnteros);
////    printf("IMPRESION EN PREORDEN: ");
////    preorden(arbol, arbol->raiz);
////    printf("Eliminar %i\n",r2);
////    a_eliminar(arbol,aux,&fEliminarEnteros);
////    printf("IMPRESION EN PREORDEN: ");
////    preorden(arbol, arbol->raiz);
////    a_eliminar(arbol,arbol->raiz,&fEliminarEnteros);
//
//    printf("DESTRUIR ARBOL \n");
//    a_destruir(&arbol,&fEliminarEnteros);
//    printf("ARBOL DESTRUIDO \n");
//
////    printf("SUBARBOL A PARTIR DE 2 \n");
////    tArbol sa;
////    a_sub_arbol(arbol,aux,&sa);
////    printf("IMPRESION EN PREORDEN: ");
////    preorden(sa, sa->raiz);
////
////
//
////  -------------------------- TESTER LISTA -------------------------
////  -------------------------- TESTER LISTA -------------------------
////  -------------------------- TESTER LISTA -------------------------
//
//
////    int x;
////    printf("Elija una opcion:\n");
////    printf("1: Crear lista de enteros\n");
////    printf("14: Salir\n");
////    printf("\n");
////    printf("OPCION: ");
////    scanf("%i",&x);
////    while(x > 0 && x< 17) {
////        if(x == 1) {
////            crear_lista(&lista);
////            printf("\n");
////            printf("LISTA CREADA\n" );
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 2) {
////            printf("\n");
////            printf("Ingrese el entero que desee agregar: ");
////            int * entero;
////            int auxEntero;
////            scanf("%i",&auxEntero);
////            entero = (int*)malloc(sizeof(int));
////            *entero = auxEntero;
////            l_insertar(lista,l_primera(lista),entero);
////            printf("\n");
////            printf("ELEMENTO INSERTADO AL PRINCIPIO.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 3) {
////            printf("\n");
////            printf("Ingrese el entero que desee agregar: ");
////            int * entero;
////            int auxEntero;
////            scanf("%i",&auxEntero);
////            entero = (int*)malloc(sizeof(int));
////            *entero = auxEntero;
////            l_insertar(lista,l_fin(lista),entero);
////            printf("\n");
////            printf("ELEMENTO INSERTADO AL FINAL.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 4) {
////            printf("\n");
////            printf("Ingrese el entero que desee agregar: ");
////            int * entero;
////            int auxEntero;
////            scanf("%i",&auxEntero);
////            entero = (int*)malloc(sizeof(int));
////            *entero = auxEntero;
////            l_insertar(lista,l_siguiente(lista,l_primera(lista)),entero);
////            printf("\n");
////            printf("ELEMENTO INSERTADO EN SEGUNDO LUGAR.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 5) {
////            printf("\n");
////            printf("Ingrese el entero que desee agregar: ");
////            int * entero;
////            int auxEntero;
////            scanf("%i",&auxEntero);
////            entero = (int*)malloc(sizeof(int));
////            *entero = auxEntero;
////            l_insertar(lista,l_anterior(lista,l_fin(lista)),entero);
////            printf("\n");
////            printf("ELEMENTO INSERTADO EN EL ANTEULTIMO LUGAR.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 6) {
////            l_eliminar(lista,l_primera(lista),&fEliminarEnteros);
////            printf("\n");
////            printf("PRIMER ELEMENTO ELIMINADO.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 7) {
////            l_eliminar(lista,l_ultima(lista),&fEliminarEnteros);
////            printf("\n");
////            printf("ULTIMO ELEMENTO ELIMINADO.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 8) {
////            int *e;
////            e=l_recuperar(lista,l_primera(lista));
////            printf("\n");
////            printf("EL PRIMER ELEMENTO ES: ");
////            printf("%i", *e);
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 9) {
////            int *e;
////            e=l_recuperar(lista,l_ultima(lista));
////            printf("\n");
////            printf("EL ULTIMO ELEMENTO ES: ");
////            printf("%i", *e);
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 10) {
////            l_eliminar(lista,l_siguiente(lista,l_primera(lista)),&fEliminarEnteros);
////            printf("\n");
////            printf("SEGUNDO ELEMENTO ELIMINADO.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 11) {
////            l_eliminar(lista,l_anterior(lista,l_ultima(lista)),&fEliminarEnteros);
////            printf("\n");
////            printf("ANTEULTIMO ELEMENTO ELIMINADO.");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x==12){
////            printf("La longitud de la lista es: ");
////            printf("%i", l_longitud(lista));
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////         if (x == 13){
////            printf("\n");
////            printf("La lista es: ");
////            tPosicion aux;
////            int i;
////            int *e;
////            i = 0;
////            aux = lista;
////            printf("[ ");
////
////            if(lista -> siguiente == NULL)
////                printf("La lista no posee elementos. ");
////            else {
////                while(aux -> siguiente != NULL) {
////                    e = aux -> siguiente -> elemento;
////                    printf("%i ", *e);
////                    aux = aux -> siguiente;
////                    i++;
////                }
////            }
////            printf("]");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 14) {
////           if(lista!=NULL) {
////               l_destruir(&lista,&fEliminarEnteros);
////               printf("LISTA DESTRUIDA");
////               printf("\n");
////           }
////           exit(0);
////        }
////        if(x == 15){
////            int *e;
////            int i;
////            srand(20);
////            i= 0;
////            while(i<10){
////                e= (int*)malloc(sizeof(int));
////                *e= rand()%30;
////                l_insertar(lista,l_ultima(lista), e);
////                i++;
////            }
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////        if(x == 16){
////            invertir_lista(lista);
////            printf("LISTA INVERTIDA");
////            printf("\n");
////            printf("\n");
////            printf("La lista es: ");
////            tPosicion aux;
////            int i;
////            int *e;
////            i = 0;
////            aux = lista;
////            printf("[ ");
////
////            if(lista -> siguiente == NULL)
////                printf("La lista no posee elementos. ");
////            else {
////                while(aux -> siguiente != NULL) {
////                    e = aux -> siguiente -> elemento;
////                    printf("%i ", *e);
////                    aux = aux -> siguiente;
////                    i++;
////                }
////            }
////            printf("]");
////            printf("\n");
////            printf("\n");
////            printf("\n");
////            printf("\n");
////            printf("----------------------------------\n");
////            printf("Elija una opcion:\n");
////            printf("1: Crear lista de enteros\n");
////            printf("2: Insertar entero al inicio\n");
////            printf("3: Insertar entero al final\n");
////            printf("4: Insertar entero despues del inicio\n");
////            printf("5: Insertar entero antes del final\n");
////            printf("6: Eliminar el primer entero\n");
////            printf("7: Eliminar el ultimo entero\n");
////            printf("8: Recuperar entero del inicio\n");
////            printf("9: Recuperar entero del final\n");
////            printf("10: Eliminar entero siguiente del inicio\n");
////            printf("11: Eliminar entero anterior del final\n");
////            printf("12: Longitud de la lista\n");
////            printf("13: Imprimir la lista por pantalla\n");
////            printf("14: Salir y destruir\n");
////            printf("15: Agregar 10 elementos aleatorios\n");
////            printf("16: Invertir lista\n");
////            printf("\n");
////            printf("OPCION: ");
////        }
////    scanf("%i",&x);
////     }
//}




