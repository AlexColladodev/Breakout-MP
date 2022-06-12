#ifndef _PINTAR_
#define _PINTAR_

#include "ConjuntoParticulas.h"
#include "Particula.h"
#include "raylib.h"

void pintarParticula(const Particula &unaParticula, Color c);
void pintarConjuntoParticulas(const ConjuntoParticulas &unConjunto, Color c);
void pintarBase(const Particula &p, Color c );

#endif
