#include "circulo.h"
#include <cmath>
#include <iostream>
using namespace std;

Circulo LeerCirculo() {
  Circulo circulo;
  char c;
  cin >> circulo.radio >> c;
  circulo.centro = LeerPunto();
  return circulo;
}

void EscribirCirculo(Circulo c) {
  cout << c.radio << "-";
  EscribirPunto(c.centro);
}

bool Leer(istream &is, Circulo &c) {
  char f;
  double r;
  Punto p;
  bool leido = (is >> r >> f) && (f == '-') && Leer(is, p);

  if (leido) {
    InicializarCirculo(c, p, r);
  }

  return leido;
}

void InicializarCirculo(Circulo &c, Punto centro, double radio) {
  c.centro = centro;
  c.radio = radio;
}

Punto Centro(Circulo c) { return c.centro; }

double Radio(Circulo c) { return c.radio; }

double Area(Circulo c) { return (c.radio * c.radio) * M_PI; }

bool Interior(Punto p, Circulo c) { return Distancia(p, c.centro) < c.radio; }

double Distancia(Circulo c1, Circulo c2) {
  return Distancia(c1.centro, c2.centro) - c1.radio - c2.radio;
}
