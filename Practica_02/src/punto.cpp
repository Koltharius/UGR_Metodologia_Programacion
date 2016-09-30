#include "punto.h"
#include <cmath>
#include <iostream>

using namespace std;

Punto LeerPunto() {
  Punto p;
  char c;
  cin >> c >> p.x >> c >> p.y >> c;
  return p;
}

void EscribirPunto(Punto p) { cout << "(" << p.x << "," << p.y << ")"; }

bool Leer(istream &is, Punto &p) {
  char c;
  double x, y;
  bool leido = (is >> c) && (c == '(') && (is >> x) && (is >> c) &&
               (c == ',') && (is >> y) && (is >> c) && (c == ')');

  return leido;
}

bool Escribir(ostream &os, const Punto &p) {
  os << "(" << p.x << "," << p.y << ")";
  return os.fail();
}

void InicializarPunto(Punto &p, double cx, double cy) {
  p.x = cx;
  p.y = cy;
}

double GetX(const Punto &p) { return p.x; }

double GetY(const Punto &p) { return p.y; }

double Distancia(const Punto &p1, const Punto &p2) {
  double d1, d2;
  d1 = p1.x - p2.x;
  d2 = p1.y - p2.y;
  return sqrt(d1 * d1 + d2 * d2);
}

Punto PuntoMedio(const Punto &p1, const Punto &p2) {
  Punto punto_medio;
  punto_medio.x = (p1.x + p2.x) / 2;
  punto_medio.y = (p1.y + p2.y) / 2;

  return punto_medio;
}
