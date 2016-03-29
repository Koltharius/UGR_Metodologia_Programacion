AR = ar
CXX = g++
CXXFLAGS = -Wall -g -I $(INC)
LDFGLAGS = -L./lib
LDLIBS = -lformas

INC = include
SRC = src
OBJ = obj
LIB = lib
BIN = bin

all : central area longitud delimitar

$(OBJ)/punto.o : $(INC)/punto.h $(SRC)/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp

$(OBJ)/circulo.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/circulo.cpp
		$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp

$(OBJ)/central.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp

$(OBJ)/area.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/area.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp

$(OBJ)/longitud.o : $(INC)/punto.h $(SRC)/longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/longitud.o $(SRC)/longitud.cpp

$(OBJ)/rectangulo.o : $(INC)/punto.h $(INC)/rectangulo.h $(SRC)/rectangulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/rectangulo.o $(SRC)/rectangulo.cpp

$(OBJ)/delimitar.o : $(INC)/rectangulo.h $(SRC)/delimitar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/delimitar.o $(SRC)/delimitar.cpp

$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o

central : $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/central $(OBJ)/central.o $(LDFGLAGS) $(LDLIBS)
area : $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/area $(OBJ)/area.o $(LDFGLAGS) $(LDLIBS)
longitud : $(OBJ)/longitud.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/longitud $(OBJ)/longitud.o $(LDFGLAGS) $(LDLIBS)
delimitar : $(OBJ)/delimitar.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/delimitar $(OBJ)/delimitar.o $(LDFGLAGS) $(LDLIBS)

clean :
	@echo Limpiando objetos...
	-rm $(OBJ)/*.o $(LIB)/*.a

mrproper : clean
	-rm $(BIN)/*
