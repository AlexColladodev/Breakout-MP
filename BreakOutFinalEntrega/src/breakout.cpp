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

    ConjuntoParticulas pared[N_FIL];
    ConjuntoParticulas bloques;
    int distanciaY = 5;
    int distanciaX = 5;

    int diferenciaDistanciaX = 1200 / N_FIL;

/*
    Particula p1, p2, p3, p4, p5, p6;
    bloques + p1 + p2 + p3+ p4 + p5 + p6;
*/
    for(int i = 0; i < N_FIL; i++){
        Particula p;
        bloques + p;
    }

    for(int i = 0; i < N_FIL; i++){
        pared[i] = bloques;
    }

    for(int i = 0; i < N_FIL; i++){
        for(int j = 0; j < COLUMNAS; j++){
            pared[i].reemplazaParticula(j, Particula(distanciaX, distanciaY, 0, 0, 15));
            distanciaX += diferenciaDistanciaX + 5;
        }
        distanciaX = 5;
        distanciaY += 25;
    }

    Particula base(screenWidth/2.0, screenHeight, 5.0, 0.0, 120); //La base donde rebotara, se debe mover
    Particula bola(screenWidth/2.0, screenWidth/2.0, 2.5, 2.5, 10.0);
    
    char dir;
    bool perdido = false;
    bool ganar = false;

    /*
    Crear un pared que contenga en cada una de sus posiciones un ConjuntoParticulas
    */


    while(!WindowShouldClose()){

        if(!perdido && !ganar){
            dir = Movimiento();

            base.moverGrid(dir, screenWidth, screenHeight);
            bola.mover(screenWidth, screenHeight);
            bola.rebotaBordes(screenWidth, screenHeight);
            controlColisionesBase(base, bola);

            BeginDrawing();

                ClearBackground(BLACK);
                pintarParticula(bola, RED);
                pintarBase(base, WHITE);

                for(int i = 0; i < N_FIL; i++){
                    controlColisiones(pared[i], bola);
                    switch(i){
                        case 0: pintarConjuntoParticulas(pared[i], PURPLE); break;
                        case 1: pintarConjuntoParticulas(pared[i], RED); break;
                        case 2: pintarConjuntoParticulas(pared[i], ORANGE); break;
                        case 3: pintarConjuntoParticulas(pared[i], YELLOW); break;
                        case 4: pintarConjuntoParticulas(pared[i], GREEN); break;
                        case 5: pintarConjuntoParticulas(pared[i], BLUE); break;
                    } 
                }

            EndDrawing();
        }

        //Si la bola llega a Y con la posicion 790, es decir que choca con el borde inferior entonces se pierde
        if(bola.GetY() == 790){
            perdido = true;

            BeginDrawing();
                DrawText("DERROTA", screenWidth/2 - 100, screenHeight/2, 40, RED);
            EndDrawing();
        }

        //Si todos los conjuntosParticulas tienen 0 particulas utiles entonces ya no quedan bloques de paredes y se gana
        if(ganarJuego(pared[0]) && ganarJuego(pared[1]) && ganarJuego(pared[2]) && ganarJuego(pared[3]) && ganarJuego(pared[4]) && ganarJuego(pared[5])){ 
            ganar = true;

            BeginDrawing();
                DrawText("VICTORIA", screenWidth/2 - 100, screenHeight/2, 40, RED);
            EndDrawing();
        }

    }

    CloseWindow();

    return 0;

}