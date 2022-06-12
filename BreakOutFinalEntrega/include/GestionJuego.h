#ifndef _GESTONJUEGO_
#define _GESTONJUEGO_

#include "parametros.h"
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "raylib.h"

//Movimiento A --> Izquierda // D --> Derecha
char Movimiento();

void controlColisiones(ConjuntoParticulas &unConjunto, const Particula &unaParticula);

void controlColisionesBase(Particula &unaParticula, Particula &otraParticula);

bool finJuegoPerder(const Particula &unaParticula, const ConjuntoParticulas &unConjunto);

bool finJuegoGanar(const ConjuntoParticulas &unConjunto);

#endif