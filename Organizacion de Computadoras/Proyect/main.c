#include "lista.h"
#include "arbol.h"
#include "partida.h"
#include "ia.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
Muestra como es el estado actual de la grilla del tablero
**/
void mostrarMatriz(tPartida p) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(p->tablero->grilla[i][j]==PART_SIN_MOVIMIENTO){
                printf("\t_");
            }
            else
                if(p->tablero->grilla[i][j]==PART_JUGADOR_1)
                    printf("\tO");
                else
                    if(p->tablero->grilla[i][j]==PART_JUGADOR_2)
                        printf("\tX");

        }
        printf("\n\n\n");
    }
}

void USUARIO_vs_USUARIO(tPartida p){
    int x;
    int y;
    mostrarMatriz(p);
    printf("\n");
    while(p->estado==PART_EN_JUEGO){
        printf("Turno de " );
        if(p->turno_de==PART_JUGADOR_1)
            printf("%s \n",p->nombre_jugador_1);
        else
            if(p->turno_de==PART_JUGADOR_2)
                printf("%s \n",p->nombre_jugador_2);

        printf("Donde desea jugar? [Introduzca la posicion de este modo-> 1,2]: ");
        scanf("%i,%i", &x, &y);

        while(x<1 || x>3 || y<1 || y>3) {
            printf("Movimiento Incorrecto. \nVuelva a elegir de forma correcta donde jugar(por ej, 1,3): ");
            scanf("%i,%i", &x, &y);
        }

        while(nuevo_movimiento(p, (x-1), (y-1))==PART_MOVIMIENTO_ERROR){
            printf("\n Movimiento Incorrecto. Esa posicion esta ocupada. \nVuelva a jugar: ");
            scanf("%i,%i", &x, &y);
        }

        mostrarMatriz(p);
    }

     if(p->estado!=PART_EN_JUEGO){
            if(p->estado==PART_EMPATE)
                printf("Empataron");
            else{
                printf("Gano ");
                if(p->estado==PART_GANA_JUGADOR_1)
                    printf("%s \n",p->nombre_jugador_1);
                else
                    printf("%s \n",p->nombre_jugador_2);
            }
        finalizar_partida(&p);
        printf("\nGRACIAS POR JUGAR");
    }
}
void USUARIO_vs_IA(tPartida p){
    int x;
    int y;
    mostrarMatriz(p);
    printf("\n");
    while(p->estado==PART_EN_JUEGO){
        if(p->turno_de==PART_JUGADOR_1){
            printf("Turno de %s\n",p->nombre_jugador_1);
            printf("Donde desea jugar? [Introduzca la posicion de este modo-> 1,2]: ");
            scanf("%i,%i", &x, &y);
            while(x<1 || x>3 || y<1 || y>3) {
                printf("Movimiento Incorrecto. \nVuelva a elegir de forma correcta donde jugar(por ej, 1,3): ");
                scanf("%i,%i", &x, &y);
            }
            while(nuevo_movimiento(p, (x-1), (y-1))==PART_MOVIMIENTO_ERROR){
                printf("\n Movimiento Incorrecto. Esa posicion esta ocupada. \nVuelva a jugar: ");
                scanf("%i,%i", &x, &y);
            }
        }
        else{
            if(p->turno_de==PART_JUGADOR_2){
                printf("Turno de Computadora \n");
                printf("La IA(Computadora) hizo su movimiento en ");
                tBusquedaAdversaria ia=NULL;
                crear_busqueda_adversaria(&ia, p);
                proximo_movimiento(ia,&x,&y);
                nuevo_movimiento(p,x,y);
                printf("%i, %i \n", x+1,y+1);
                destruir_busqueda_adversaria(&ia);
            }
        }
        mostrarMatriz(p);
    }
    if(p->estado!=PART_EN_JUEGO){
        if(p->estado==PART_EMPATE)
            printf("Empataron");
        else{
            printf("Gano ");
            if(p->estado==PART_GANA_JUGADOR_1)
                printf("%s \n",p->nombre_jugador_1);
            else
                printf("%s \n",p->nombre_jugador_2);
        }
        finalizar_partida(&p);
        printf("\nGRACIAS POR JUGAR");
    }
}

int main(){
    tPartida p;
    int modoPartida;
    int comienza;
    char nombreJ1[51];
    char nombreJ2[51];

        printf("Como quiere jugar la partida? \n1= Usuario vs Usuario o 2= Usuario vs Computadora: ");
        scanf("%i", &modoPartida);
        modoPartida+=102;
        while(modoPartida!= PART_MODO_USUARIO_VS_USUARIO && modoPartida!= PART_MODO_USUARIO_VS_AGENTE_IA){
            printf("Modo incorrecto. \nElija alguno de los mencionados anteriormente: ");
            scanf("%i", &modoPartida);
            modoPartida+=102;
        }
        printf("\n");
        // Si el modo a jugar es Usuario vs Usuario
        if(modoPartida==PART_MODO_USUARIO_VS_USUARIO){
            printf("Quien va a iniciar jugando la partida? \n1= Jugador1, 2= Jugador2 o 3=Al azar: ");
            scanf("%i", &comienza);
            comienza+=99;
            while(comienza!=PART_JUGADOR_1 && comienza!=PART_JUGADOR_2 && comienza!= PART_JUGADOR_RANDOM){
                printf("Eleccion incorrecta. \nElija alguno de los mencionados anteriormente: ");
                scanf("%i", &comienza);
                comienza+=99;
            }

            printf("\nNombre del Jugador 1: ");
            scanf("%s",nombreJ1);
            printf("\nNombre del Jugador 2: ");
            scanf("%s",nombreJ2);
            nueva_partida(&p,modoPartida,comienza,nombreJ1,nombreJ2);
            USUARIO_vs_USUARIO(p);

        }
        else{
            // Si el modo a jugar es Usuario vs Inteligencia Artificial
            if(modoPartida==PART_MODO_USUARIO_VS_AGENTE_IA){
                printf("Quien va a iniciar jugando la partida? \n1=Jugador1, 2=Jugador2(Computadora) o 3=Al azar: ");
                scanf("%i", &comienza);
                comienza+=99;
                while(comienza!=PART_JUGADOR_1 && comienza!=PART_JUGADOR_2 && comienza!= PART_JUGADOR_RANDOM){
                    printf("Eleccion incorrecta. \nElija alguno de los mencionados anteriormente: ");
                    scanf("%i", &comienza);
                    comienza+=99;
                }
                printf("\nNombre del Jugador 1: ");
                scanf("%s",nombreJ1);
                strcpy(nombreJ2, "Computadora");
                nueva_partida(&p,modoPartida,comienza,nombreJ1,nombreJ2);
                USUARIO_vs_IA(p);
            }
        }
    return 0;
}
