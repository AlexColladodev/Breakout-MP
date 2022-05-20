#include "ConjuntoParticulas.h"
#include <iostream>

using namespace std;

// Métodos privados para reservar, liberar y redimensionar memoria
void ConjuntoParticulas::reservaMemoria(int n){
	
    liberaMemoria();

    //Reservo para una cantidad de N particulas
    set = new Particula[n];
    capacidad = n;
}


void ConjuntoParticulas::liberaMemoria(){

    // Solo si el array contiene partículas
    if (set != 0){
        delete [] set;
        set = 0;
    }
}

void ConjuntoParticulas::redimensionaMemoria(int n){
	
   Particula *copia;
   copia = new Particula[n];


   for (int i = 0; i < utiles; i++){
       copia[i] = set[i];
    }
    
   liberaMemoria();

   capacidad = n;

   set = copia; 

}

//Fin metodos privados


ConjuntoParticulas::ConjuntoParticulas(){

    utiles = 0;
    capacidad = 0;

}


ConjuntoParticulas::ConjuntoParticulas(int n){
	
    // La creacion de N particulas
    reservaMemoria(n);

    //Asigna N a capacidad y utiles --> Instruccion incorrecta?
    utiles = 0;
    capacidad = n;


    //Crear N particulas
    for (int i = 0; i < n; i++){
        Particula nueva;
        this->agregaParticula(nueva);
    }
}


//Al eliminar todo el set eliminamos todas la memoria la cual hemos reservado
ConjuntoParticulas::~ConjuntoParticulas(){
    liberaMemoria();
}


int ConjuntoParticulas::getCapacidad(){
	return capacidad;
}


int ConjuntoParticulas::getUtiles(){
	return utiles;
}


void ConjuntoParticulas::agregaParticula(const Particula &unaParticula){

    // Si no hay espacio suficiente se redimensiona
    if (utiles == capacidad){
        redimensionaMemoria(capacidad+TAM_BLOQUE);
    }

    set[utiles] = unaParticula;
    utiles++;
}


void ConjuntoParticulas::borraParticula(int posicion){

    if (posicion > utiles){

    	//Haciendo desplazamientos hacia la izquierda se borra una particula
        for (int i = 0; i < utiles; i++){
            set[i] = set[i+1];
        }
    }

    int nueva_capacidd = capacidad - TAM_BLOQUE;

    if ((capacidad - utiles) > TAM_BLOQUE)
        redimensionaMemoria(nueva_capacidd);
}


Particula ConjuntoParticulas::obtieneParticula(int posicion){
	//Debe ser una posicion valida
    if(posicion >= 0 && posicion < utiles){
    	return set[posicion];
    }
}


void ConjuntoParticulas::reemplazaParticula(int posicion, const Particula &unaParticula){
	if(posicion >=0 && posicion < utiles)
		set[posicion] = unaParticula;
}


//Utilizar metodos de Particulas para mover
void ConjuntoParticulas::moverParticulas(int ancho, int alto){

	for(int i = 0; i < utiles; i++){
		set[i].mover(ancho, alto);
	}
}


void ConjuntoParticulas::rebotar(int ancho, int alto){

	for(int j = 0; j < utiles; j++){
		set[j].rebotaBordes(ancho, alto);
	}
}


void ConjuntoParticulas::mostrarInfo(){
    for (int i = 0; i < utiles; i++){
        cout << set[i].toString() << endl;
    }
}







