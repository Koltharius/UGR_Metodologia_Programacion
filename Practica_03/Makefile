SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

ocultar = ocultar
revelar = revelar

all : $(ocultar) $(revelar)

# ************************ Generación de documentación ****************************************************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************************* Compilación de módulos ********************************************************
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/codificar.o : $(SRC)/codificar.cpp $(INC)/codificar.h
	$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp $(INC)/imagenES.h $(INC)/codificar.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/ocultar.o $(SRC)/ocultar.cpp

$(ocultar) : $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/$(ocultar) $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o

$(OBJ)/revelar.o : $(SRC)/revelar.cpp $(INC)/imagenES.h $(INC)/codificar.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/revelar.o $(SRC)/revelar.cpp

$(revelar) : $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/$(revelar) $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o

# ***************************** Limpieza ******************************************************************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
