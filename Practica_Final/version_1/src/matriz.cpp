#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz() {
   for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < 20; ++j) {
         datos[i][j] = 0;
      }
   }

   filas = columnas = 0;
}

//Matriz::Matriz(int f, int c) {
//   for (int i = 0; i < 20; ++i) {
//      for (j = 0; j < 20; ++j) {
//         datos[i][j] = 0;
//      }
//   }
//
//   filas = f;
//   columnas = c;
//}

int Matriz::GetFilas() const {
   return filas;
}

void Matriz::SetFilas(int f) {
   filas = f;
}

int Matriz::GetColumnas() const {
   return columnas;
}

void Matriz::SetColumnas(int c) {
   columnas = c;
}

int Matriz::GetElementoPosicion(int f, int c) const {
   return datos[f][c];
}

void Matriz::SetElementoPosicion(int f, int c, int v) {
   datos[f][c] = v;
}

int Matriz::GetFichasTotales() const {
   int fichas = 0;
   for (int f = 0; f < GetFilas(); ++f) {
      for (int c = 0; c < GetColumnas(); ++c) {
         if (GetElementoPosicion(f, c) != 0) {
            fichas++;
         }
      }
   }

   return fichas;
}

void Matriz::VaciarMatriz() {
   for (int f = 0; f < 20; ++f) {
      for (int c = 0; c < 20; ++c) {
         datos[f][c] = 0;
      }
   }
}
