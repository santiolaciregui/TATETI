#include <stdlib.h>
#include "lista.h"
#include "arbol.h"
#include "ia.h"
#include "partida.h"

// Prototipos de funciones auxiliares.
static void ejecutar_min_max(tBusquedaAdversaria b);
static void crear_sucesores_min_max(tArbol a, tNodo n, int es_max, int alpha, int beta, int jugador_max, int jugador_min);
static int valor_utilidad(tEstado e, int jugador_max);
static tLista estados_sucesores(tEstado e, int ficha_jugador);
static void diferencia_estados(tEstado anterior, tEstado nuevo, int * x, int * y);
static tEstado clonar_estado(tEstado e);

void noEliminaEstado(void *e){    }

void eliminarEstado(void *e){
    tEstado estado= (tEstado) e;
    free(estado);
}

int max(int num1, int num2) {
   int result;
   if (num1 > num2)
      result = num1;
   else
      result = num2;
   return result;
}


int min(int num1, int num2) {
   int result;
   if (num1 > num2)
      result = num2;
   else
      result = num1;
   return result;
}
void crear_busqueda_adversaria(tBusquedaAdversaria * b, tPartida p){
    int i, j;
    tEstado estado;

    (*b) = (tBusquedaAdversaria) malloc(sizeof(struct busqueda_adversaria));
    if ((*b) == NULL) exit(IA_ERROR_MEMORIA);

    estado = (tEstado) malloc(sizeof(struct estado));
    if (estado == NULL) exit(IA_ERROR_MEMORIA);

    // Se clona el estado del tablero de la partida, al estado inicial de la b�squeda adversaria.
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            estado->grilla[i][j] = p->tablero->grilla[i][j];
        }
    }
	// Se asume que el estado de la partida es PART_EN_JUEGO por lo que, la utilidad del estado
	// inicialmente es IA_NO_TERMINO
    estado->utilidad = IA_NO_TERMINO;

    // Inicializa los valores que representar�n a los jugadores MAX y MIN respectivamente.
    (*b)->jugador_max = p->turno_de;
    (*b)->jugador_min = (p->turno_de == PART_JUGADOR_1) ? PART_JUGADOR_2 : PART_JUGADOR_1;

    // Inicializa un �rbol para la b�squeda adversaria inicialmente vac�o.
    crear_arbol(&((*b)->arbol_busqueda));

    // Inicializa la ra�z del �rbol de b�squeda con el estado del tablero T.
    crear_raiz((*b)->arbol_busqueda, estado);

    // Ejecuta algoritmo Min-Max con podas Alpha-Beta.
    ejecutar_min_max((*b));
}
/**
 Computa y retorna el pr�ximo movimiento a realizar por el jugador MAX.
 Para esto, se tiene en cuenta el �rbol creado por el algoritmo de b�squeda adversaria Min-max con podas Alpha-Beta.
 Siempre que sea posible, se indicar� un movimiento que permita que MAX gane la partida.
 Si no existe un movimiento ganador para MAX, se indicar� un movimiento que permita que MAX empate la partida.
 En caso contrario, se indicar� un movimiento que lleva a MAX a perder la partida.
**/
void proximo_movimiento(tBusquedaAdversaria b, int * x, int * y){
    tArbol arbol;
    tNodo raiz;
    tLista hijosRaiz;
    tPosicion pos;
    tPosicion posFin;

    arbol=b->arbol_busqueda;
    raiz=a_raiz(arbol);
    hijosRaiz= a_hijos(arbol, raiz);
    pos=l_primera(hijosRaiz);
    posFin= l_fin(hijosRaiz);

    while(pos!=posFin){

    }


}

/**
>>>>>  A IMPLEMENTAR   <<<<<
**/
void destruir_busqueda_adversaria(tBusquedaAdversaria * b){
    (*b)->jugador_max=-1;
    (*b)->jugador_min=-1;
    a_destruir(&((*b)->arbol_busqueda), &eliminarEstado);
}

// ===============================================================================================================
// FUNCIONES Y PROCEDEMIENTOS AUXILIARES
// ===============================================================================================================

/**
Ordena la ejecuci�n del algoritmo Min-Max para la generaci�n del �rbol de b�squeda adversaria, considerando como
estado inicial el estado de la partida almacenado en el �rbol almacenado en B.
**/
static void ejecutar_min_max(tBusquedaAdversaria b){
    tArbol a = b->arbol_busqueda;
    tNodo r = a_raiz(a);
    int jugador_max = b->jugador_max;
    int jugador_min = b->jugador_min;

    crear_sucesores_min_max(a, r, 1, IA_INFINITO_NEG, IA_INFINITO_POS, jugador_max, jugador_min);
}

/**
>>>>>  A IMPLEMENTAR   <<<<<
Implementa la estrategia del algoritmo Min-Max con podas Alpha-Beta, a partir del estado almacenado en N.
- A referencia al �rbol de b�squeda adversaria.
- N referencia al nodo a partir del cual se construye el sub�rbol de b�squeda adversaria.
- ES_MAX indica si N representa un nodo MAX en el �rbol de b�squeda adversaria.
- ALPHA y BETA indican sendos valores correspondientes a los nodos ancestros a N en el �rbol de b�squeda A.
- JUGADOR_MAX y JUGADOR_MIN indican las fichas con las que juegan los respectivos jugadores.
**/
static void crear_sucesores_min_max(tArbol a, tNodo n, int es_max, int alpha, int beta, int jugador_max, int jugador_min){
    tEstado estado;
    int mejor_valor_sucesores;
    int valorSucesor;
    int seguir;
    int utilidad_n;
    tLista sucesores;
    tNodo hijoSucesor;
    tPosicion pos, posFin;

    seguir=1;
    valorSucesor=0;
    estado=(tEstado)a_recuperar(a, n);
    utilidad_n = valor_utilidad(estado, jugador_max);

    if(utilidad_n==IA_NO_TERMINO){
        if(es_max==1){
            mejor_valor_sucesores=IA_INFINITO_NEG;
            sucesores= estados_sucesores(estado,jugador_max);
            pos=l_primera(sucesores);
            posFin=l_fin(sucesores);
            while(pos!=posFin && seguir){
                hijoSucesor=a_insertar(a, n, NULL, l_recuperar(sucesores, pos));
                l_eliminar(sucesores, pos,&noEliminaEstado);
                crear_sucesores_min_max(a, hijoSucesor, 0, alpha, beta, jugador_max, jugador_min);
                mejor_valor_sucesores= max(mejor_valor_sucesores, valorSucesor);
                alpha= max(alpha, mejor_valor_sucesores);
                if(beta<=alpha)
                    seguir=0;
            }
        }else{
            mejor_valor_sucesores= IA_INFINITO_POS;
            sucesores= estados_sucesores(estado,jugador_min);
            pos=l_primera(sucesores);
            posFin=l_fin(sucesores);
            while(pos!=posFin && seguir){
                hijoSucesor=a_insertar(a, n, NULL, l_recuperar(sucesores, pos));
                l_eliminar(sucesores, pos,&noEliminaEstado);
                crear_sucesores_min_max(a, hijoSucesor, 1, alpha, beta, jugador_max, jugador_min);
                mejor_valor_sucesores= min(mejor_valor_sucesores, valorSucesor);
                beta= min(alpha, mejor_valor_sucesores);
                if(beta<=alpha)
                    seguir=0;
            }
        }
        utilidad_n = mejor_valor_sucesores;
    }
    estado->utilidad = utilidad_n;
}

tPosicion posicionAleatoria(tLista lista){
    tPosicion toReturn;

    toReturn=NULL;
    int numero= rand()%3;
    if(numero==0)
        toReturn=l_primera(lista);
        else
            if(numero==1)
                toReturn=l_ultima(lista);
            else
                if(numero==2)
                    toReturn=l_fin(lista);
    return toReturn;
}
/**
>>>>>  A IMPLEMENTAR   <<<<<
Computa el valor de utilidad correspondiente al estado E, y la ficha correspondiente al JUGADOR_MAX, retornado:
- IA_GANA_MAX si el estado E refleja una jugada en el que el JUGADOR_MAX gan� la partida.
- IA_EMPATA_MAX si el estado E refleja una jugada en el que el JUGADOR_MAX empat� la partida.
- IA_PIERDE_MAX si el estado E refleja una jugada en el que el JUGADOR_MAX perdi� la partida.
- IA_NO_TERMINO en caso contrario.
**/
static int valor_utilidad(tEstado e, int jugador_max){
    return 0;
}

/**
>>>>>  A IMPLEMENTAR   <<<<<
Computa y retorna una lista con aquellos estados que representan estados sucesores al estado E.
Un estado sucesor corresponde a la clonaci�n del estado E, junto con la incorporaci�n de un nuevo movimiento
realizado por el jugador cuya ficha es FICHA_JUGADOR por sobre una posici�n que se encuentra libre en el estado E.
La lista de estados sucesores se debe ordenar de forma aleatoria, de forma tal que una doble invocaci�n de la funci�n
estados_sucesores(estado, ficha) retornar�a dos listas L1 y L2 tal que:
- L1 y L2 tienen exactamente los mismos estados sucesores de ESTADO a partir de jugar FICHA.
- El orden de los estado en L1 posiblemente sea diferente al orden de los estados en L2.
**/


static tLista estados_sucesores(tEstado e, int ficha_jugador){
    tLista lista;
    int i,j;
    tEstado clone;

    crear_lista(&lista);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(e->grilla[i][j]==PART_SIN_MOVIMIENTO){
                clone=clonar_estado(e);
                clone->grilla[i][j]=ficha_jugador;
                l_insertar(lista, posicionAleatoria(lista), clone);
            }
        }
    }
    return lista;
}

/**
>>>>>  A IMPLEMENTAR   <<<<<
Inicializa y retorna un nuevo estado que resulta de la clonaci�n del estado E.
Para esto copia en el estado a retornar los valores actuales de la grilla del estado E, como su valor
de utilidad.
**/
static tEstado clonar_estado(tEstado e){
    tEstado nuevo=malloc(sizeof(struct estado));
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
         nuevo->grilla[i][j]=e->grilla[i][j];
    nuevo->utilidad=e->utilidad;
    return nuevo;
}

/**
Computa la diferencia existente entre dos estados.
Se asume que entre ambos existe s�lo una posici�n en el que la ficha del estado anterior y nuevo difiere.
La posici�n en la que los estados difiere, es retornada en los par�metros *X e *Y.
**/
static void diferencia_estados(tEstado anterior, tEstado nuevo, int * x, int * y){
    int i,j, hallado = 0;
    for(i=0; i<3 && !hallado; i++){
        for(j=0; j<3 && !hallado; j++){
            if (anterior->grilla[i][j] != nuevo->grilla[i][j]){
                *x = i;
                *y = j;
                hallado = 1;
            }
        }
    }
}



