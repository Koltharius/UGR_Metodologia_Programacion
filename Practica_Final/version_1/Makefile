SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CXXFLAGS = -Wall -g  -I$(INC)

# ************ All ***********************
all :conectaN

# ************ Compilación de módulos ************

$(OBJ)/matriz.o : $(SRC)/matriz.cpp $(INC)/matriz.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/matriz.o $(SRC)/matriz.cpp
$(OBJ)/tablero.o : $(SRC)/tablero.cpp $(INC)/tablero.h $(INC)/matriz.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/tablero.o $(SRC)/tablero.cpp
$(OBJ)/jugador.o : $(SRC)/jugador.cpp $(INC)/jugador.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/jugador.o $(SRC)/jugador.cpp
$(OBJ)/conectaN.o : $(SRC)/conectaN.cpp $(INC)/jugador.h $(INC)/tablero.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/conectaN.o $(SRC)/conectaN.cpp

conectaN: $(OBJ)/conectaN.o $(OBJ)/jugador.o $(OBJ)/matriz.o $(OBJ)/tablero.o
	$(CXX) -g -o $(BIN)/conectaN $(OBJ)/conectaN.o $(OBJ)/jugador.o $(OBJ)/matriz.o $(OBJ)/tablero.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/*
