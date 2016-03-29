#ifndef _CIRCULO_H_
#define _CIRCULO_H_

#include "punto.h"

struct Circulo{
   Punto centro;
   double radio;
};

Circulo LeerCirculo();

void EscribirCirculo(Circulo c);

bool Leer(std::istream& is, Circulo& c);

bool Escribir(std::ostream& os, const Circulo& c);

void InicializarCirculo (Circulo& c, Punto centro, double radio);

Punto Centro (Circulo c);

double Radio (Circulo c);

double Area (Circulo c);

bool Interior (Punto p, Circulo c);

double Distancia (Circulo c1, Circulo c2);

#endif
