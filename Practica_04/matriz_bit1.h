#ifndef _MATRIZ_BIT_1_
#define _MATRIZ_BIT_1_

struct MatrizBit {
  static const int MAX_FILAS = 10;
  static const int MAX_COLUMNAS = 10;
  int filas, columnas;
  bool matriz[MAX_FILAS][MAX_COLUMNAS];
};

#endif
