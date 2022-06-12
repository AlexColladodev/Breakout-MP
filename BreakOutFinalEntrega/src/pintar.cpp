#include "pintar.h"

void pintarParticula(const Particula & p, Color c) {
    DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}

void pintarBase(const Particula &p, Color c ){
    DrawRectangle(p.GetX() - 75, p.GetY(), 150, p.GetRadio(), c);
}

void pintarConjuntoParticulas(const ConjuntoParticulas &unConjunto, Color c){
    int utiles = unConjunto.GetUtiles();

    for(int i = 0; i < utiles; i++){
        pintarParticula(unConjunto.obtieneParticula(i), c);
    }
}
