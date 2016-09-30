#include "matriz_bit2.h"

bool Inicializar(MatrizBit &m, int fils, int cols) {
  bool exito = false;

  if (fils * cols <= m.MAX_ESPACIO && fils >= 0 && cols >= 0) {
    m.filas = fils;
    m.columnas = cols;

    for (int i = 0; i < (m.filas * m.columnas); ++i) {
      m.matriz[i] = false;
    }
    exito = true;
  }

  return exito;
}

int Filas(const MatrizBit &m) { return m.filas; }

int Columnas(const MatrizBit &m) { return m.columnas; }

bool Get(const MatrizBit &m, int f, int c) {
  return m.matriz[f * Columnas(m) + c];
}

void Set(MatrizBit &m, int f, int c, bool v) {
  if (f < m.filas && c <= m.columnas && f >= 0 && c >= 0) {
    m.matriz[f * Columnas(m) + c] = v;
  }
}
