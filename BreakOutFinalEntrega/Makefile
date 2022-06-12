HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
SRC = $(HOME)/src
OBJ = $(HOME)/obj



# Compilación

all : $(BIN)/breakout  clean

# Objetos

$(OBJ)/pruebaConjuntoFinal.o : $(SRC)/pruebaConjuntoFinal.cpp
	g++ -c -o $(OBJ)/pruebaConjuntoFinal.o $(SRC)/pruebaConjuntoFinal.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/ConjuntoParticulas.o : $(SRC)/ConjuntoParticulas.cpp 
	g++ -c -o $(OBJ)/ConjuntoParticulas.o $(SRC)/ConjuntoParticulas.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/Particula.o : $(SRC)/Particula.cpp
	g++ -c -o $(OBJ)/Particula.o $(SRC)/Particula.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/GestionJuego.o : $(SRC)/GestionJuego.cpp
	g++ -c -o $(OBJ)/GestionJuego.o $(SRC)/GestionJuego.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/pintar.o : $(SRC)/pintar.cpp
	g++ -c -o $(OBJ)/pintar.o $(SRC)/pintar.cpp -I$(INCLUDE) -std=c++14 -lraylib

$(OBJ)/breakout.o : $(SRC)/breakout.cpp
	g++ -c -o $(OBJ)/breakout.o $(SRC)/breakout.cpp -I$(INCLUDE) -std=c++14 -lraylib

	
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
