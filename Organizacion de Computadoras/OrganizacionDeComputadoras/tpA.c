#include <stdio.h>

void fechaValida(int dia, int mes, int anio){
    if(mes>=1 && mes<=12 && dia>=1){
        switch(mes){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(dia<=31)
                    printf("\n Fecha Correcta");
                else
                    printf("\n Fecha Incorrecta");
            case 2:
                if(dia<=28)
                    printf("\n Fecha Correcta");
                else
                    printf("\n Fecha Incorrecta");
            case 4:
            case 6:
            case 11:
                if(dia<=30)
                    printf("\n Fecha Correcta");
                else
                    printf("\n Fecha Incorrecta");
        }
    }
    else
        printf("\n Fecha Incorrecta");
}


void segundosAHora(long segs){
    int minutos = segs/60;
    int segundos = segs % 60;
    int horas = minutos/60;
    minutos= minutos % 60;
    printf("%i : %i :%i", horas, minutos, segundos);

}


void gradosCelciusAFahrenheit(float cel){
    cel=(cel*(1.8))+32;
    printf("%f", cel);
    }

void millasAkm(int millas){
    millas=millas/37.282;
    printf("%i", millas);
}

int cantidadDigitos(int n){
    int retorno;
    if(n<10)
        retorno=1;
    else
        retorno=1+cantidadDigitos(n/10);
    return retorno;
}

int cantidadApariciones(int n, int d){
    int retorno=0;
    if(n==0)
        retorno=0;
    else{
        if(n%10==d)
            retorno++;
        cantidadApariciones(n/10, d);
    }
    return retorno;
}



int esProlijo(int n){
    int retorno=0;
    if(n<10)
        retorno=1;
    else{
        int ult=n%10;
        int ante=(n/10)%10;
        if(ult>ante)
            retorno=1;
        esProlijo(ante);
    }
    return retorno;
}

int ascendente(int n){
    int retorno=0;
    if(n<10)
        retorno=1;
    else{
        int ult=n%10;
        int ante=(n/10)%10;
        if(ult>ante)
            retorno=1;
        esProlijo(ante);
    }
    return retorno;
}


void palindroma(char cadena [], int fin){
     int resul=1;
     fin--;
     for(int ini=0;ini<fin && resul==1;ini++){
        if(cadena[ini]!=cadena[fin]){
            resul=0;
        }
        fin--;
     }
     if(resul==1)
        printf("soy palindroma");
     if(resul==0)
        printf("no es palindroma");


}



