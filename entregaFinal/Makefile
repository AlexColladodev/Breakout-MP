HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
SRC = $(HOME)/src
OBJ = $(HOME)/obj



# Compilación

all : $(BIN)/pruebaConjunto  clean

# Objetos

$(OBJ)/pruebaConjunto.o : $(SRC)/pruebaConjunto.cpp
	g++ -c -o $(OBJ)/pruebaConjuntoFinal.o $(SRC)/pruebaConjuntoFinal.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/ConjuntoParticulas.o : $(SRC)/ConjuntoParticulas.cpp 
	g++ -c -o $(OBJ)/ConjuntoParticulas.o $(SRC)/ConjuntoParticulas.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/Particula.o : $(SRC)/Particula.cpp
	g++ -c -o $(OBJ)/Particula.o $(SRC)/Particula.cpp -I$(INCLUDE) -std=c++14

	
# Ejecutable

$(BIN)/pruebaConjunto : $(OBJ)/pruebaConjunto.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/Particula.o 
	g++ -o $(BIN)/pruebaConjuntoFinal $(OBJ)/pruebaConjuntoFinal.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/Particula.o 


# Limpieza de archivos

clean :
	@echo "Limpiando objetos"
	-rm $(OBJ)/*.o

mr.proper : clean
	@echo "Limpiando ejecutables"
	-rm $(BIN)/*
