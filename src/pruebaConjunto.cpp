
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include <iostream>


using namespace std;

const float ANCHO = 800.0;
const float ALTO = 800.0;

void start(){
    cout << "************* INICIO *************" << endl;
}

void end(){
    cout << "*************  FIN   *************" << endl;
}

void test1(string s) {
    
    cout << s << endl;
    start();
    cout << "Prueba Constructores " << endl;
    ConjuntoParticulas cp1;
    ConjuntoParticulas cp2(10);
    end();
}

void test2(string s) {
    cout << s << endl;
    start();
    ConjuntoParticulas cp1(5);

    cout << "Conjunto Inicial con 5 particulas" << endl;
    cp1.mostrarInfo();
    
    
    Particula nueva(5.0, 5.0, 0.0, 0.0, 5);
    int n = cp1.getUtiles();
    for (int i = -1; i <= n + 1; i++)
        cp1.reemplazaParticula(i, nueva);
    
    cout << "----- Después de reemplazar particulas ---- " << endl;
    cp1.mostrarInfo();
    end();
}

void test3(string s) {
    cout << s << endl;
    start();
    ConjuntoParticulas cp1;

    cout << " ---- Conjunto Inicial ----" << endl;
    cp1.mostrarInfo();
    int n = 12;
    cout << " ---- Agrego 12 particulas ----" << endl;    
    for (int i = 0; i < n; i++) {
        Particula nueva;
        cp1.agregaParticula(nueva);
    }

    cout << " ---- Conjunto Final -----" << endl;
    cp1.mostrarInfo();
    end();
}

void test4(string s) {
    cout << s << endl;
    start();
    ConjuntoParticulas cp1(11);


    cout << " ---- Conjunto Inicial con 11 particulas al azar ----" << endl;
    cp1.mostrarInfo();

    int n = cp1.getUtiles();
    cout << " ---- Elimino todas las particulas en orden aleatorio ----" << endl;
    for (int i = 0; i < n; i++) {
        int nro = cp1.getUtiles();
        if (nro > 0)
            cp1.borraParticula(random() % nro);
    }
    cout << " ---- Conjunto Final -----" << endl;
    cp1.mostrarInfo();
    end();
}

void test5(string s) {
    cout << s << endl;
    start();
    int N = 10;
    // creación de objetos
    //---------------------------------------------------------
    ConjuntoParticulas nube(N);
    cout << " ---- Conjunto inicial con 10 particulas -----" << endl;
    cout << " ---- Agrego/Borro particulas al azar -----" << endl;
    for (int i = 0; i < 100; i++) {
        if ((random() % 10) > 5)
            for (int j = 0; j < 7; j++) {
                Particula nueva;
                nube.agregaParticula(nueva);
            } else {
            for (int j = 0; j < 7; j++) {
                int nro = nube.getUtiles();
                if (nro > 0)
                    nube.borraParticula((random() % nro));
            }
        }
        nube.moverParticulas(ANCHO, ALTO);
        nube.rebotar(ANCHO, ALTO);

    }
    end();
}

int main(int argc, char* argv[]) {

    
    
    int opc = 0;
    if (argc > 1)
         opc = atoi(argv[1]);
    else
        cout << "USO: test <nro>   donde nro indica el test a ejecutar" << endl;

    switch (opc){
        case 1:{test1("\n************* TEST 1 ************* "); break; } 
        case 2:{test2("\n************* TEST 2 ************* "); break; } 
        case 3:{test3("\n************* TEST 3 ************* "); break; } 
        case 4:{test4("\n************* TEST 4 ************* "); break; } 
        case 5:{test5("\n************* TEST 5 ************* "); break; 
        case 6:{test1("\n************* TEST 1 ************* ");
                test2("\n************* TEST 2 ************* ");
                test3("\n************* TEST 3 ************* ");
                test4("\n************* TEST 4 ************* ");
                test5("\n************* TEST 5 ************* ");break;
        }
        }
        default: {cout << "Nro. de test incorrecto " << endl; break;}
    }

    return 0;
}