#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz() {
   filas = columnas = 0;
}

Matriz::Matriz(int f, int c) {
   filas = f;
   columnas = c;
   datos = new int[filas * columnas];
}

Matriz::Matriz(const Matriz& m) {
   int f = m.GetFilas();
   int c = m.GetColumnas();
   filas = f;
   columnas = c;
   datos = new int[f * c];
   for (int i = 0; i < f * c; i++) {
      datos[i] = m.datos[i];
   }
}

Matriz::~Matriz() {
   delete[] datos;
   this->columnas = this->filas = 0;
}

Matriz& Matriz::operator=(const Matriz& m) {
   if (&m != this) {
      this->filas = m.filas;
      this->columnas = m.columnas;
      this->datos = new int[this->filas * this->columnas];
      for (int i = 0; i < this->filas * this->columnas; i++) {
         datos[i] = m.datos[i];
      }
   }
   return *this;
}

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
   return datos[f * columnas + c];
}

int Matriz::GetElementoPosicion(int p) const {
   return datos[p];
}

void Matriz::SetElementoPosicion(int f, int c, int v) {
   datos[f * columnas + c] = v;
}

void Matriz::SetElementoPosicion(int p, int v) {
   datos[p] = v;
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
   for (int i = 0; i < filas * columnas; ++i) {
      datos[i] = 0;
   }
}

ostream& operator<<(ostream &os, const Matriz &m) {
   os << m.GetFilas() << '\n';
   os << m.GetColumnas() << '\n';
   for (int i = 0; i < m.GetFilas() * m.GetColumnas(); i++)
      os << m.GetElementoPosicion(i) << ' ';
   return os;
}

istream& operator>>(istream &is, Matriz &m) {
   int f, c, tmp;
   is >> f >> c;
   m = Matriz(f, c);
   for (int i = 0; i < m.GetFilas() * m.GetColumnas(); i++) {
      is >> tmp;
      m.SetElementoPosicion(i, tmp);
   }
   return is;
}
