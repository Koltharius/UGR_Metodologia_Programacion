#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>

struct Punto {
  double x, y;
};

Punto LeerPunto();

void EscribirPunto(const Punto p);

bool Leer(std::istream &is, Punto &p);

bool Escribir(std::ostream &os, const Punto &p);

void InicializarPunto(Punto &p, double cx, double cy);

double GetX(const Punto p);

double GetY(const Punto p);

double Distancia(const Punto &p1, const Punto &p2);

Punto PuntoMedio(const Punto &p1, const Punto &p2);

#endif
