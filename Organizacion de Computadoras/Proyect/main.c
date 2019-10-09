#include "lista.h"
#include "arbol.h"
#include <stdlib.h>
#include <stdio.h>
void fEliminarEnteros (tElemento e){
    int * elemento = (int *) e;
    *elemento = -1;
    free(elemento);
}

tLista sumarPrimerElementoConUltimo(tLista lis1, tLista lis2){
        tLista nueva=NULL;
        crear_lista(&nueva);
        while(l_longitud(lis1)>0 && l_longitud(lis2)>0){
            tPosicion plis1=l_primera(lis1);
            tPosicion plis2=l_ultima(lis2);
            int elemento1=(int) plis1->elemento;
            int elemento2=(int) plis2->elemento;
            l_insertar(nueva, l_primera(nueva),(int) elemento1+elemento2);
            l_eliminar(lis1,plis1,&fEliminarEnteros);
            l_eliminar(lis2, plis2, &fEliminarEnteros);
        }
        return nueva;
    }
void mostrarlista(tLista lista){
    printf("\n");
            printf("La lista es: ");
            tPosicion aux;
            int i;
            int *e;
            i = 0;
            aux = lista;
            printf("[ ");

            if(lista -> siguiente == NULL)
                printf("La lista no posee elementos. ");
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
}

int main(){
    tArbol arbol=NULL;
    crear_arbol(&arbol);
    crear_raiz(arbol, 1);
    printf("hahhaha");
    tNodo aux=a_insertar(arbol, arbol->raiz, NULL, 2);
    printf("sasassa");

    a_insertar(arbol,arbol->raiz, NULL, 3);
    tNodo aux1=a_insertar(arbol, aux, NULL, 5 );
    a_insertar(arbol, aux, aux1, 6 );

//    int x;
//    printf("Elija una opcion:\n");
//    printf("1: Crear lista de enteros\n");
//    printf("14: Salir\n");
//    printf("\n");
//    printf("OPCION: ");
//    scanf("%i",&x);
//    while(x > 0 && x< 17) {
//        if(x == 1) {
//            crear_lista(&lista);
//            printf("\n");
//            printf("LISTA CREADA\n" );
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 2) {
//            printf("\n");
//            printf("Ingrese el entero que desee agregar: ");
//            int * entero;
//            int auxEntero;
//            scanf("%i",&auxEntero);
//            entero = (int*)malloc(sizeof(int));
//            *entero = auxEntero;
//            l_insertar(lista,l_primera(lista),entero);
//            printf("\n");
//            printf("ELEMENTO INSERTADO AL PRINCIPIO.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 3) {
//            printf("\n");
//            printf("Ingrese el entero que desee agregar: ");
//            int * entero;
//            int auxEntero;
//            scanf("%i",&auxEntero);
//            entero = (int*)malloc(sizeof(int));
//            *entero = auxEntero;
//            l_insertar(lista,l_fin(lista),entero);
//            printf("\n");
//            printf("ELEMENTO INSERTADO AL FINAL.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 4) {
//            printf("\n");
//            printf("Ingrese el entero que desee agregar: ");
//            int * entero;
//            int auxEntero;
//            scanf("%i",&auxEntero);
//            entero = (int*)malloc(sizeof(int));
//            *entero = auxEntero;
//            l_insertar(lista,l_siguiente(lista,l_primera(lista)),entero);
//            printf("\n");
//            printf("ELEMENTO INSERTADO EN SEGUNDO LUGAR.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 5) {
//            printf("\n");
//            printf("Ingrese el entero que desee agregar: ");
//            int * entero;
//            int auxEntero;
//            scanf("%i",&auxEntero);
//            entero = (int*)malloc(sizeof(int));
//            *entero = auxEntero;
//            l_insertar(lista,l_anterior(lista,l_fin(lista)),entero);
//            printf("\n");
//            printf("ELEMENTO INSERTADO EN EL ANTEULTIMO LUGAR.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 6) {
//            l_eliminar(lista,l_primera(lista),&fEliminarEnteros);
//            printf("\n");
//            printf("PRIMER ELEMENTO ELIMINADO.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 7) {
//            l_eliminar(lista,l_ultima(lista),&fEliminarEnteros);
//            printf("\n");
//            printf("ULTIMO ELEMENTO ELIMINADO.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 8) {
//            int *e;
//            e=l_recuperar(lista,l_primera(lista));
//            printf("\n");
//            printf("EL PRIMER ELEMENTO ES: ");
//            printf("%i", *e);
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 9) {
//            int *e;
//            e=l_recuperar(lista,l_ultima(lista));
//            printf("\n");
//            printf("EL ULTIMO ELEMENTO ES: ");
//            printf("%i", *e);
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 10) {
//            l_eliminar(lista,l_siguiente(lista,l_primera(lista)),&fEliminarEnteros);
//            printf("\n");
//            printf("SEGUNDO ELEMENTO ELIMINADO.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 11) {
//            l_eliminar(lista,l_anterior(lista,l_ultima(lista)),&fEliminarEnteros);
//            printf("\n");
//            printf("ANTEULTIMO ELEMENTO ELIMINADO.");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x==12){
//            printf("La longitud de la lista es: ");
//            printf("%i", l_longitud(lista));
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//         if (x == 13){
//            printf("\n");
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
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 14) {
//           if(lista!=NULL) {
//               l_destruir(&lista,&fEliminarEnteros);
//               printf("LISTA DESTRUIDA");
//               printf("\n");
//           }
//           exit(0);
//        }
//        if(x == 15){
//            int *e;
//            int i;
//            srand(20);
//            i= 0;
//            while(i<10){
//                e= (int*)malloc(sizeof(int));
//                *e= rand()%30;
//                l_insertar(lista,l_ultima(lista), e);
//                i++;
//            }
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//        if(x == 16){
//            invertir_lista(lista);
//            printf("LISTA INVERTIDA");
//            printf("\n");
//            printf("\n");
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
//            printf("\n");
//            printf("\n");
//            printf("\n");
//            printf("----------------------------------\n");
//            printf("Elija una opcion:\n");
//            printf("1: Crear lista de enteros\n");
//            printf("2: Insertar entero al inicio\n");
//            printf("3: Insertar entero al final\n");
//            printf("4: Insertar entero despues del inicio\n");
//            printf("5: Insertar entero antes del final\n");
//            printf("6: Eliminar el primer entero\n");
//            printf("7: Eliminar el ultimo entero\n");
//            printf("8: Recuperar entero del inicio\n");
//            printf("9: Recuperar entero del final\n");
//            printf("10: Eliminar entero siguiente del inicio\n");
//            printf("11: Eliminar entero anterior del final\n");
//            printf("12: Longitud de la lista\n");
//            printf("13: Imprimir la lista por pantalla\n");
//            printf("14: Salir y destruir\n");
//            printf("15: Agregar 10 elementos aleatorios\n");
//            printf("16: Invertir lista\n");
//            printf("\n");
//            printf("OPCION: ");
//        }
//    scanf("%i",&x);
//     }
}




