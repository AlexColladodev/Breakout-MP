#include "pintar.h"

void pintarParticula(const Particula & p, Color c) {
    DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}

void pintarBloques(const Particula & p, Color c){
    DrawRectangle(p.GetX(), p.GetY(), 200, p.GetRadio(), c);
}

void pintarBase(const Particula & p, Color c) {
    //DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
    DrawRectangle(p.GetX(), p.GetY()+60, 200, p.GetRadio(), c);
}

void pintarConjuntoParticulas(const ConjuntoParticulas &unConjunto, Color c){
    int utiles = unConjunto.GetUtiles();

    for(int i = 0; i < utiles; i++){
        DrawRectangle(unConjunto.obtieneParticula(i).GetX(), unConjunto.obtieneParticula(i).GetY(), 200, unConjunto.obtieneParticula(i).GetRadio(), c);
    }
}
