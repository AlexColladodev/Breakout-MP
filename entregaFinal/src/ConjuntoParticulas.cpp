#include "ConjuntoParticulas.h"
#include <iostream>
#include<assert.h>
#include<cmath>

using namespace std;

/* ********* MÉTODOS PRIVADOS ********* */
// Se reserva, libera y redimensiona memoria
void ConjuntoParticulas::reservaMemoria(int n){
    liberaMemoria();

    // Reservo para una cantidad de N particulas
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
    
    Particula *copia;
    copia = new Particula[n];


    for (int i = 0; i < utiles; i++){
        copia[i] = set[i];
    }
    
    liberaMemoria();

    capacidad = n;

    set = copia; 

}

// NEW
void ConjuntoParticulas::Copiar(const ConjuntoParticulas &unConjunto){

    reservaMemoria(unConjunto.GetCapacidad());

    utiles = 0;

    for (int i = 0; i < unConjunto.GetUtiles(); i++){
        this->agregaParticula(unConjunto.obtieneParticula(i));
    }

}

/* ********* MÉTODOS PÚBLICOS ********* */

// **** Constructores y destructores

// Al crear el objeto directamente se hace en la definicion de la clase (constructor sin parámetros)
ConjuntoParticulas::ConjuntoParticulas(){
}

// Constructor con parámetros
ConjuntoParticulas::ConjuntoParticulas(int n){
	// La creacion de N particulas
    reservaMemoria(n);

    
    utiles = n;
    // Capacidad ya es alterada en reservaMemoria

    // Crear N particulas
    for (int i = 0; i < n; i++){
        Particula nueva;
    }
}


// Al eliminar todo el set eliminamos todas la memoria la cual hemos reservado
ConjuntoParticulas::~ConjuntoParticulas(){
    delete [] set;
}

// NEW
// Constructor de copia
ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &unConjunto){

    // Se reserva memoria en Copiar
    Copiar(unConjunto);

}

// **** Demás métodos públicos

// En mayúscula porque así aparece en pruebaConjunto.cpp
int ConjuntoParticulas::GetCapacidad() const{
	return capacidad;
}


int ConjuntoParticulas::GetUtiles() const{
	return utiles;
}


void ConjuntoParticulas::agregaParticula(const Particula &unaParticula){

    // Si no hay espacio suficiente se redimensiona.
    // Al ir siempre aniadiendo de una en una particula no hace falta mas comprobaciones que esta
    // Utiles siempre sera menor o igual que capacidad ya que es un atributo privado y no hay setters para modificarlos
    if (utiles == capacidad)
        redimensionaMemoria(capacidad+TAM_BLOQUE);
    

    set[utiles] = unaParticula;
    utiles++;
}


void ConjuntoParticulas::borraParticula(int posicion){

    if (posicion <= utiles){

    	// Haciendo desplazamientos hacia la izquierda se borra una particula
        for (int i = posicion; i < utiles - 1; i++){
            set[i] = set[i+1];
        }
        utiles--;
    }

    int nueva_capacidd = capacidad - TAM_BLOQUE;

    if ((capacidad - utiles) > TAM_BLOQUE)
        redimensionaMemoria(nueva_capacidd);
}


Particula ConjuntoParticulas::obtieneParticula(int posicion) const{
	// Debe ser una posicion valida assert
    assert(posicion >= 0 && posicion < utiles);

    return set[posicion];
    
}


void ConjuntoParticulas::reemplazaParticula(int posicion, const Particula &unaParticula){
	if(posicion >=0 && posicion < utiles)
		set[posicion] = unaParticula;
}


// Utilizar metodos de Particulas para mover
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
        std::cout << set[i].toString() << std::endl;
    }
    std::cout << "Utiles -> " << utiles << std::endl;
    std::cout << "Capacidad -> " << capacidad << std::endl;
}

// NEW
// Sobrecarga operator =
ConjuntoParticulas & ConjuntoParticulas::operator = (const ConjuntoParticulas &unConjunto){

    // Comprueba si se trata del mismo objeto
    if (&unConjunto != this)
        this->Copiar(unConjunto);

    return *this;

}

// NEW
// Sobrecarga operator <<
ostream & operator << (ostream & flujo, const ConjuntoParticulas &unConjunto){

    flujo << " Nro Particulas: " << unConjunto.GetUtiles() << " Capacidad: " << unConjunto.GetCapacidad() << std::endl;
    for (int i = 0; i < unConjunto.GetUtiles(); i++){
        flujo << "Part. " << i  << " => " << unConjunto.obtieneParticula(i) << std::endl;        
    }

    return flujo;
}


// NEW
// Sobrecarga operator []
// NOTA: SE DEBE AÑADIR MÉTODO CONST Y NO CONST POR LOS PROBLEMAS
// EXPLICADOS EN LAS DIAPOSITIVAS DE TEORIA
Particula & ConjuntoParticulas::operator [] (int i){

    assert (i >= 0);
    if (i > this->capacidad)
        // Se añade por encima del tope. Se debe ampliar.
        redimensionaMemoria(i + 1);

    return this->set[i];

}

const Particula & ConjuntoParticulas::operator[] (int i) const{

    assert (i >= 0 && i <= this->GetCapacidad());
        return this->set[i];

}


// NEW
// Sobrecarga operator +
/* PROBLEMA -> Solo se puede ir sumando particulas 1 a 1, sino error.
    Cambiado en pruebaConjuntoFinal.cpp para que en vez de cp1 + p2 + p3 se haga:
        cp1 + p2;
        cp1 + p3; */

ConjuntoParticulas & ConjuntoParticulas::operator + (const Particula &unaParticula){
    
    this->agregaParticula(unaParticula);

}

// NEW
// Sobrecarga operator == 
//Puede ser mejorado
bool ConjuntoParticulas::operator == (const ConjuntoParticulas &unConjunto){
    bool encontrado = false;
    bool salir = false;

    if(this->GetUtiles() == unConjunto.GetUtiles()){
        for (int i = 0; i < utiles && !salir; i++){//Si ya se comprueba que ambos utiles son lo mismo se puede poner esto como i < utiles
            encontrado = false;
            for(int j = 0; j < utiles && !encontrado; j++){
                if(this->obtieneParticula(i) == unConjunto.obtieneParticula(j)){
                    encontrado = true;
                    salir = false;
                }else{
                    encontrado = false;
                    salir = true;
                }
            }
        }
    }

    return encontrado;
}

// NEW distanciaPromedio
double ConjuntoParticulas::distanciaPromedio(Particula unaParticula) const{

    double distancia = 0;
    double Ax, Ay, Bx, By; //--> Son las X e Y de cada una de las particulas
    Bx = unaParticula.GetX();
    By = unaParticula.GetY();
    
    for(int i = 0; i < utiles; i++){
        Ax = set[i].GetX();
        Ay = set[i].GetY();

        /*
        Ax = obtieneParticula(i).GetX();
        Ay = obtieneParticula(i).GetY();
        */        

        distancia += sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2));
    }

    return distancia / utiles;
}

// NEW
// Sobrecarga del operador <
bool ConjuntoParticulas::operator < (const ConjuntoParticulas &unConjunto) const{

    Particula unaParticula(0,0,0,0,0); //Se crea una particula, los valores importantes son x e y, respectivamente (0,0)

    return this->distanciaPromedio(unaParticula) < unConjunto.distanciaPromedio(unaParticula);

}








