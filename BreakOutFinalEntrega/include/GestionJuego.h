#ifndef _GESTONJUEGO_
#define _GESTONJUEGO_

#include "parametros.h"
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "raylib.h"

//Movimiento A --> Izquierda // D --> Derecha
char Movimiento();
char Movimiento2();

void controlColisiones(ConjuntoParticulas &unConjunto, Particula &unaParticula);

void controlColisionesBase(Particula &unaParticula, Particula &otraParticula);

bool ganarJuego(const ConjuntoParticulas &unConjunto);

#endif