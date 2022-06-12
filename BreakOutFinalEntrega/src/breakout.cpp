#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "pintar.h"
#include "raylib.h"
#include "GestionJuego.h"
#include <assert.h>
#include <string.h>

using namespace std;

int main(int argc, char **argv){
    InitWindow(screenWidth, screenHeight, "BreakOut");
    SetTargetFPS(60);

    Particula base(screenWidth/2.0, screenHeight-20.0, 5.0, 0.0, 30.5); //La base donde rebotara, se debe mover
    Particula bola(screenWidth/2.0, screenWidth/2.0, 2.5, 2.5, 10.0);
    char dir;

    ConjuntoParticulas bloques(6);

    /*
    Crear un array que contenga en cada una de sus posiciones un ConjuntoParticulas
    */


    while(!WindowShouldClose()){
        dir = Movimiento();

        base.moverGrid(dir, screenWidth, screenHeight);
        bola.mover(screenWidth, screenHeight);
        bola.rebotaBordes(screenWidth, screenHeight);
        controlColisionesBase(base, bola);
        controlColisiones(bloques, bola);

        BeginDrawing();

            ClearBackground(RAYWHITE);
            pintarParticula(bola, RED);
            pintarBase(base, BLACK);
            pintarConjuntoParticulas(bloques, GREEN);

        EndDrawing();

    }

    CloseWindow();

    return 0;

}