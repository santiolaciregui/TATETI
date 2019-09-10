#include <stdio.h>
#include <stdlib.h>

void inicializarArreglo(int arreglo[], int cant){
    for(int i=0;i<cant;i++)
        arreglo[i]=rand()% 20;
}

void ordenarArreglo(int arreglo[], int cant){
     for(int i=0;i<cant-1;i++){
        for(int x=i;x<cant;x++){
            if(arreglo[i]>arreglo[x]){
                int aux=arreglo[i];
                arreglo[i]=arreglo[x];
                arreglo[x]=aux;
            }
        }
    }
}

int esAscendente(int arreglo[], int cant){
    int resul=1;
    for(int i=0;i<cant-1 && resul!=0;i++){
        if(arreglo[i]>arreglo[i+1]){
            resul=0;
        }
    }
    return resul;
}

int* intercalar(int arreglo[],int long1, int long2, int arreglo2[]){
    int pA1=0;
    int pA2=0;
    int *nuevo=malloc(24*sizeof(int));
    int pnuevo=0;
    while(pA1<long1 && pA2<long2){
        if(arreglo[pA1]<arreglo2[pA2]){
            nuevo[pnuevo]=arreglo[pA1];
            pA1++;
        }
        else{
            if(arreglo[pA1]>arreglo2[pA2]){
                nuevo[pnuevo]=arreglo2[pA2];
                pA2++;
            }
            else{
                nuevo[pnuevo]= arreglo[pA1];
                pA1++;
                pA2++;
            }
        }
        pnuevo++;
    }
    while(pA1<long1){
        nuevo[pnuevo]=arreglo[pA1];
        pnuevo++;
        pA1++;
    }
    while(pA2<long2){
        nuevo[pnuevo]=arreglo[pA2];
        pnuevo++;
        pA2++;
    }
    return nuevo;
}


void reemplazar(int *arr, int a, int n, int size){
    for(int i=0;i<size;i++){
        if(arr[i]==a){
            arr[i]=n;
        }
        arr++;
    }
}

void ej10(){
 }


int main(void){

    ej10();


    /*
    int arr[5]={1,2,3,4,5};
    reemplazar(arr, 3,0,5);
    for(int i=0;i<5;i++)
        printf("%i",arr[i]);
    */


//
//    int a[10];
//    int b[12];
//    ordenarArreglo(a,10);
//    ordenarArreglo(b,12);
//    int *p= intercalar(a,10,12,b);
//    int longtotal=22;
//    for(int i=0;i<longtotal;i++)
//        printf("%i  \n", *(p+i));

    /*
    printf("ingrese long del arreglo: ");
    int longitud;
    scanf("%i", &longitud);
    int arreglo[longitud];
    printf("ingrese cantidad de casilleros a inicializar: ");
    int cant;
    scanf("%i", &cant);
    inicializarArreglo(arreglo, cant);
    for(int i=0; i<longitud;i++){
        printf("%i \n", arreglo[i]);
    }

    int ordenar;
    printf("ingrese cant a ordenar: ");
    scanf("%i", &ordenar);
    printf("\n");
    ordenarArreglo(arreglo, ordenar);
    for(int i=0; i<longitud;i++){
        printf("%i \n", arreglo[i]);
    }
    int m=esAscendente(arreglo, longitud);
    if(m==0)
        printf("no es ascendente");
    else
        printf("es ascendente");
    */
}

