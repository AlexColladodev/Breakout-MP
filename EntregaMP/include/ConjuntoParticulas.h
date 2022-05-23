#ifndef _CONJUNTOPARTICULAS_
#define _CONJUNTOPARTICULAS_

#include "Particula.h"

const int TAM_BLOQUE = 3;

class ConjuntoParticulas{
private:
    Particula *set = 0; // --> Mejor inicializarlo directamente al construir un objeto, sino salta error
    int capacidad = 0;
    int utiles = 0;

    void reservaMemoria(int n);

    void liberaMemoria();

    void redimensionaMemoria(int n);

public:

    ConjuntoParticulas();

    ConjuntoParticulas(int n);

    ~ConjuntoParticulas();

    int GetCapacidad () const;

    int GetUtiles() const;

    void agregaParticula(const Particula &unaParticula);

    void borraParticula(int posicion);

    Particula obtieneParticula(int posicion);

    void reemplazaParticula(int posicion, const Particula &unaParticula);

    void moverParticulas(int ancho, int alto);

    void rebotar(int ancho, int alto);

    void mostrarInfo();
};

#endif