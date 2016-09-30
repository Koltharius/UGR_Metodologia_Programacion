#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include<iostream>
using namespace std;

class Matriz {
private:
   int *datos;
   int filas, columnas;

public:
   Matriz();
   Matriz(int f, int c);
   Matriz(const Matriz &m);
   ~Matriz();
   Matriz& operator=(const Matriz &m);
   int GetFilas() const;
   void SetFilas(int f);
   int GetColumnas() const;
   void SetColumnas(int c);
   int GetElementoPosicion(int f, int c) const;
   int GetElementoPosicion(int p) const;
   void SetElementoPosicion(int f, int c, int v);
   void SetElementoPosicion(int p, int v);
   int GetFichasTotales() const;
   void VaciarMatriz();
};

ostream& operator<<(ostream &os, const Matriz &m);
istream& operator>>(istream &is, Matriz &m);

#endif
