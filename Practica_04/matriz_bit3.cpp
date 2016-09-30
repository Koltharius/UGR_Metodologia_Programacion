#include "matriz_bit3.h"

const int MAX_POS = 16;

bool Inicializar(MatrizBit &m, int fils, int cols) {
  bool exito = false;
  if ((fils * cols) <= m.MAX_ESPACIO && fils >= 0 && cols >= 0) {
    m.filas_columnas = (fils << MAX_POS) | cols;

    for (int i = 0; i < (filas * columnas); i++) {
      m.matriz[i] = '0';
    }
    exito = true;
  }

  return exito;
}

int Filas(const MatrizBit &m) { return m.filas_columnas >> MAX_POS; }

int Columnas(const MatrizBit &m) { return m.filas_columnas & 0xFFFF; }

bool Get(const MatrizBit &m, int f, int c) {
  return m.matriz[Columnas(m) * f + c] == '1';
}

void Set(MatrizBit &m, int f, int c, bool v) {
  const int COLS = Columnas(m);
  const int FILS = Filas(m);

  if (f < FILS && c < COLS && f >= 0 && c >= 0) {
    m.matriz[COLS * f + c] = v ? '1' : '0';
  }
}
