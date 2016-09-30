#include "matriz_operaciones.h"
#include <cstring>
#include <fstream>
#include <iosfwd>
#include <iostream>

using namespace std;

void EliminarBlancos(istream &is) {
  while (isspace(is.peek())) {
    is.ignore();
  }
}

bool Leer(std::istream &is, MatrizBit &m) {
  bool exito = true;
  int columnas = 0, filas = 0;

  EliminarBlancos(is);

  if (is.peek() == 'X' || is.peek() == '.') {
    const int MAX_POS = 1024;
    char valores[MAX_POS];
    char aux[MAX_POS];

    is.getline(valores, MAX_POS);
    columnas = strlen(valores);
    filas = 1;
    EliminarBlancos(is);

    while (is.getline(aux, MAX_POS)) {
      if (int(strlen(aux)) != columnas) {
        exito = false;
      }

      strcat(valores, aux);
      filas++;
      EliminarBlancos(is);
    }

    exito = is.eof() && Inicializar(m, filas, columnas);

    if (exito) {
      for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
          char c = valores[columnas * i + j];

          if (c == 'X' || c == '.') {
            Set(m, i, j, c == 'X');
          } else {
            return false;
          }
        }
      }
    }
  }

  else {
    is >> filas >> columnas;
    bool exito = is && Inicializar(m, filas, columnas);
    char v;

    if (exito) {
      for (int i = 0; i < filas && exito; ++i) {
        for (int j = 0; j < columnas && exito; ++j) {
          is >> v;
          if (v == '1' || v == '0') {
            Set(m, i, j, v == '1');
          } else {
            return false;
          }
        }
        exito = is;
      }
    }
  }
  return exito;
}

bool Escribir(std::ostream &os, const MatrizBit &m) {
  os << Filas(m) << ' ' << Columnas(m) << endl;
  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      bool v = Get(m, i, j);
      if (v) {
        os << '1';
      } else {
        os << '0';
      }
      os << ' ';
    }
    cout << endl;
  }
  return os;
}

bool Leer(const char nombre[], MatrizBit &m) {
  ifstream archivo(nombre);
  bool exito = false;
  if (archivo) {
    exito = Leer(archivo, m);
  }
  return exito;
}

bool Escribir(const char nombre[], const MatrizBit &m) {
  ofstream archivo(nombre);
  bool exito = false;
  if (archivo) {
    exito = Escribir(archivo, m);
  }
  return exito;
}

void And(MatrizBit &res, const MatrizBit &m1, const MatrizBit &m2) {
  if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))) {
    Inicializar(res, Filas(m1), Columnas(m1));
    for (int i = 0; i < Filas(m1); ++i) {
      for (int j = 0; i < Columnas(m1); ++j) {
        Set(res, i, j, (Get(m1, i, j) && Get(m2, i, j)));
      }
    }
  } else {
    cout << "Las matrices no tienen el mismo tamaño." << endl;
  }
}

void Or(MatrizBit &res, const MatrizBit &m1, const MatrizBit &m2) {
  if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))) {
    Inicializar(res, Filas(m1), Columnas(m1));
    for (int i = 0; i < Filas(m1); i++) {
      for (int j = 0; j < Columnas(m1); j++) {
        Set(res, i, j, (Get(m1, i, j) || Get(m2, i, j)));
      }
    }
  } else {
    cout << "Las matrices no tienen el mismo tamaño." << endl;
  }
}

void Not(MatrizBit &res, const MatrizBit &m) {
  Inicializar(res, Filas(m), Columnas(m));
  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      Set(res, i, j, !Get(m, i, j));
    }
  }
}

void Traspuesta(MatrizBit &res, const MatrizBit &m) {
  const int FILAS = Filas(m);
  const int COLUMNAS = Columnas(m);

  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      Set(res, j, i, Get(m, i, j));
    }
  }
}
