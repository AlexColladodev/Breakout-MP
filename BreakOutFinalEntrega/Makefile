HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
SRCJUEGO = $(HOME)/srcJuego
OBJ = $(HOME)/obj
SRCTEST = $(HOME)/srcTests



# Compilación

all : $(BIN)/breakout  clean

# Objetos

$(OBJ)/pruebaConjuntoFinal.o : $(SRCTEST)/pruebaConjuntoFinal.cpp
	g++ -c -o $(OBJ)/pruebaConjuntoFinal.o $(SRCTEST)/pruebaConjuntoFinal.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/ConjuntoParticulas.o : $(SRCJUEGO)/ConjuntoParticulas.cpp 
	g++ -c -o $(OBJ)/ConjuntoParticulas.o $(SRCJUEGO)/ConjuntoParticulas.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/Particula.o : $(SRCJUEGO)/Particula.cpp
	g++ -c -o $(OBJ)/Particula.o $(SRCJUEGO)/Particula.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/GestionJuego.o : $(SRCJUEGO)/GestionJuego.cpp
	g++ -c -o $(OBJ)/GestionJuego.o $(SRCJUEGO)/GestionJuego.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/pintar.o : $(SRCJUEGO)/pintar.cpp
	g++ -c -o $(OBJ)/pintar.o $(SRCJUEGO)/pintar.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/breakout.o : $(SRCJUEGO)/breakout.cpp
	g++ -c -o $(OBJ)/breakout.o $(SRCJUEGO)/breakout.cpp -I$(INCLUDE) -std=c++14 -lraylib

	
# Ejecutable

$(BIN)/pruebaConjuntoFinal : $(OBJ)/pruebaConjuntoFinal.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/Particula.o 
	g++ -o $(BIN)/pruebaConjuntoFinal $(OBJ)/pruebaConjuntoFinal.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/Particula.o

$(BIN)/breakout : $(OBJ)/breakout.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/Particula.o $(OBJ)/GestionJuego.o $(OBJ)/pintar.o
	g++ -o $(BIN)/breakout $(OBJ)/breakout.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/Particula.o $(OBJ)/GestionJuego.o $(OBJ)/pintar.o -lraylib

# Limpieza de archivos

clean :
	@echo "Limpiando objetos"
	-rm $(OBJ)/*.o

mr.proper : clean
	@echo "Limpiando ejecutables"
	-rm $(BIN)/*
