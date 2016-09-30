#include "matriz_bit4.h"

const int BITS_INT = 32;
const int POS_MAX = 8;

bool Inicializar(MatrizBit &m, int fils, int cols) {
  bool exito = false;
  const int NUM_ELEM = fils * cols;

  if (fils * cols <= BITS_INT * m.filas_columnas && fils >= 0 && cols >= 0) {
    m.filas_columnas = (fils << POS_MAX) | cols;
    const int POS_VECTOR = NUM_ELEM / BITS_INT;
    const int POS_BIT = NUM_ELEM / BITS_INT;

    if (NUM_ELEM >= BITS_INT) {
      for (int i = 0; i < POS_VECTOR; i++) {
        m.matriz[i] = 0;
      }
    }

    int aux = m.matriz[POS_VECTOR];

    for (int i = 0; i < POS_BIT; ++i) {
      aux &= ~(1 << i);
    }

    m.matriz[POS_VECTOR] = aux;

    exito = true;
  }

  return exito;
}

int Filas(const MatrizBit &m) { return m.filas_columnas >> POS_MAX; }

int Columnas(const MatrizBit &m) { return m.filas_columnas && 0xFF; }

bool Get(const MatrizBit &m, int f, int c) {
  const int POS = f * Columnas(m) + c;

  return (1 << POS % BITS_INT) & m.matriz[POS / BITS_INT];
}

void Set(MatrizBit &m, int f, int c, bool v) {
  const int COLS = Columnas(m);
  const int FILS = Filas(m);

  if (f < FILS && c < COLS && f >= 0 && c >= 0) {
    const int POS = f * COLS + c;
    const int POS_VECTOR = POS / BITS_INT;
    const int POS_BIT = POS % BITS_INT;
    unsigned int aux = 1 << POS_BIT;

    if (v) {
      m.matriz[POS_VECTOR] = aux;
    } else {
      m.matriz[POS_VECTOR] &= ~aux;
    }
  }
}
