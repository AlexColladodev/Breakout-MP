#include "GestionJuego.h"

//Control del Movimiento izq // der
char Movimiento(){
    char dir = ' ';
    if(IsKeyDown(KEY_LEFT))
        dir = 'L';
    else if (IsKeyDown(KEY_RIGHT))
    {
        dir = 'R';
    } 
    return dir;
}

char Movimiento2(){
    char dir = ' ';
    if(IsKeyDown('A'))
        dir = 'L';
    else if (IsKeyDown('D'))
    {
        dir = 'R';
    } 
    return dir;
}

//Si colisiona contra el bloque este se elimina. Se debe comprobar todas las particulas del conjuntoParticulas
void controlColisiones(ConjuntoParticulas &unConjunto, Particula &unaParticula){
    for(int i = unConjunto.GetUtiles()-1; i >= 0; i--){
        if(unConjunto.obtieneParticula(i).colision(unaParticula)){
            unConjunto.borraParticula(i);
            i--;
            unaParticula.cambioSignoDY();
        }
    }
}

void controlColisionesBase(Particula &unaParticula, Particula &otraParticula){
        if(unaParticula.colision(otraParticula)){
            otraParticula.cambioSignoDY();
        }
    
}

bool ganarJuego(const ConjuntoParticulas &unConjunto){
    return unConjunto.GetUtiles() == 0;
}

