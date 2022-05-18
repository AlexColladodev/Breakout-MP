#include "ConjuntoParticulas.h"
#include <iostream>


//Metodos privados para reservar, liberar y redimensionar memoria
void ConjuntoParticulas::reservaMemoria(int n){
    liberaMemoria();

    //Reservo para una cantidad de N particulas
    set = new Particula[n];
    capacidad = n;
}


void ConjuntoParticulas::liberaMemoria(){
    if (set != 0){
        delete [] set;
        set = 0;
    }
}


void ConjuntoParticulas::redimensionaMemoria(int n){
   Particula *new;
    new = new Particula[n];


    for (int i = 0; i < utiles; i++){
        new[i] = set[i];
    }
    liberarMem();

    capacidad = n;

    set = new; 

}


ConjuntoParticulas::ConjuntoParticulas(){

    utiles = 0;
    capacidad = 0;
    set = 0;

}


ConjuntoParticulas::ConjuntoParticulas(int n){
	//La creacion de N particulas
    reservaMemoria(n);

    //Asigna N a capacidad y utiles
    utiles = n;
    capacidad = n;


    //Crear N particulas
    for (int i = 0; i < n; i++){
        Particula nueva;
    }
}


//Al eliminar todo el set eliminamos todas la memoria la cual hemos reservado
ConjuntoParticulas::~ConjuntoParticulas(){
    delete [] set;
}

int ConjuntoParticulas::getCapacidad(){
	return capacidad;
}

int ConjuntoParticulas::getUtiles(){
	return utiles;
}

void ConjuntoParticulas::AgregaParticula(const Particula &unaParticula){

    // Si no hay espacio suficiente se redimensiona
    if (utiles == capacidad){
        redimensiona(capacidad+TAM_BLOQUE);
    }
    set[utiles] = p;
    utiles++;
}



