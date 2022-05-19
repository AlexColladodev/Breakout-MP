#ifndef _CONJUNTOPARTICULAS_
#define _CONJUNTOPARTICULAS_

#include "Particula.h"

const int TAM_BLOQUE = 3;

class ConjuntoParticulas{
private:
    Particula *set ;
    int capacidad;
    int utiles;

    void reservaMemoria(int n);

    void liberaMemoria();

    void redimensionarMemoria(int n);

public:

	ConjuntoParticulas();

	ConjuntoParticulas(int n);

	~ConjuntoParticulas();

	int getCapacidad();

	int getUtiles();

    void agregaParticula(const Particula &unaParticula);

    void borraParticula(int posicion);

    Particula obtieneParticula(int posicion);

    void reemplazaParticula(int posicion, const Particula &unaParticula);

    void moverParticulas(int ancho, int alto);
}