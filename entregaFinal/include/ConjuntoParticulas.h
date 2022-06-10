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

    ConjuntoParticulas(const ConjuntoParticulas &cp);

    int GetCapacidad() const;

    int GetUtiles() const;

    void agregaParticula(const Particula &unaParticula);

    void borraParticula(int posicion);

    Particula obtieneParticula(int posicion) const;

    void reemplazaParticula(int posicion, const Particula &unaParticula);

    void moverParticulas(int ancho, int alto);

    void rebotar(int ancho, int alto);

    void mostrarInfo();

    //Cabeceras de Parte 2 Proyecto

    void Copiar(const ConjuntoParticulas &unConjunto);

    Particula &operator [](int i);

    const int &operator [](int i) const;

    bool operator ==(const ConjuntoParticulas &unConjunto);

    friend std::ostream & operator << (std::ostream & flujo, const ConjuntoParticulas &unConjunto);

    ConjuntoParticulas &operator = (const ConjuntoParticulas &unConjunto);

    ConjuntoParticulas &operator + (const Particula &unaParticula) const;

    double distanciaPromedio(Particula unaParticula) const;

    double distanciaPromedio() const; //Necesario este metodo para hacer el operador < con (0,0)

    bool operator < (const ConjuntoParticulas &unConjunto) const;
};

#endif