#include "partida.h"
#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED

/**
Inicializa una nueva partida, indicando:
 - Modo de partida (Usuario vs. Usuario o Usuario vs. Agente IA).
 - Jugador que comienza la partida (Jugador 1, Jugador 2, o elecci�n al azar).
 - Nombre que representa al Jugador 1.
 - Nombre que representa al Jugador 2.
**/
void nueva_partida(tPartida * p, int modo_partida, int comienza, char * j1_nombre, char * j2_nombre){
    (*p)=malloc(sizeof(struct partida));
    (*p)->modo_partida=modo_partida;
    (*p)-> turno_de=comienza;
    tTablero tablero
    (*p)->tablero=malloc(sizeof(struct tablero);
}

/**
Actualiza, si corresponde, el estado de la partida considerando que el jugador al que le corresponde jugar, decide hacerlo en la posici�n indicada (X,Y).
En caso de que el movimiento a dicha posici�n sea posible, retorna PART_MOVIMIENTO_OK; en caso contrario, retorna PART_MOVIMIENTO_ERROR.
Las posiciones (X,Y) deben corresponderse al rango [0-2]; X representa el n�mero de fila, mientras Y el n�mero de columna.
**/
int nuevo_movimiento(tPartida p, int mov_x, int mov_y){
    if((p->tablero)->->tablero[mov_x][mov_y]!=0)
        exit(PART_MOVIMIENTO_ERROR);
}

/**
Finaliza la partida referenciada por P, liberando toda la memoria utilizada.
**/
void finalizar_partida(tPartida * p){}

#endif // PARTIDA_H_INCLUDED
