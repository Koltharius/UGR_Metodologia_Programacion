#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_
#include "punto.h"

struct Rectangulo{
   Punto e_inf_izda;
   Punto e_sup_dcha;
};

bool Leer(std::istream& is, Rectangulo& r);

bool Escribir(std::ostream& os, const Rectangulo& r);

void InicializarRectangulo(Rectangulo& r, const Punto& p1, const Punto& p2);

Punto InferiorIzquierda(const Rectangulo& r);

Punto SuperiorDerecha(const Rectangulo& r);

double Area(const Rectangulo& r);

bool Interior(const Punto& p, const Rectangulo& r);

#endif
