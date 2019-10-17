#include "partida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Inicializa una nueva partida, indicando:
 - Modo de partida (Usuario vs. Usuario o Usuario vs. Agente IA).
 - Jugador que comienza la partida (Jugador 1, Jugador 2, o elecci�n al azar).
 - Nombre que representa al Jugador 1.
 - Nombre que representa al Jugador 2.
**/
void nueva_partida(tPartida * p, int modo_partida, int comienza, char * j1_nombre, char * j2_nombre){
    tTablero tablero;
    (*p)=malloc(sizeof(struct partida));
    (*p)->modo_partida=modo_partida;
    (*p)->turno_de=comienza;
    (*p)->tablero=malloc(sizeof(struct tablero));
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            (*p)->tablero->grilla[i][j]=PART_SIN_MOVIMIENTO;
        }
    }
    strcpy((*p)->nombre_jugador_1, j1_nombre);
    strcpy((*p)->nombre_jugador_2, j2_nombre);
    (*p)->estado=PART_EN_JUEGO;
}

/**
Actualiza, si corresponde, el estado de la partida considerando que el jugador al que le corresponde jugar, decide hacerlo en la posici�n indicada (X,Y).
En caso de que el movimiento a dicha posici�n sea posible, retorna PART_MOVIMIENTO_OK; en caso contrario, retorna PART_MOVIMIENTO_ERROR.
Las posiciones (X,Y) deben corresponderse al rango [0-2]; X representa el n�mero de fila, mientras Y el n�mero de columna.
**/
int nuevo_movimiento(tPartida p, int mov_x, int mov_y){
    int toReturn;
    if((p->tablero)->grilla[mov_x][mov_y]!=PART_SIN_MOVIMIENTO)
        toReturn=PART_MOVIMIENTO_ERROR;
    else{
        (p->tablero)->grilla[mov_x][mov_y]=p->turno_de;
        toReturn=PART_MOVIMIENTO_OK;
    }
    return toReturn;
}

/**
Finaliza la partida referenciada por P, liberando toda la memoria utilizada.
**/
void finalizar_partida(tPartida * p){

}

