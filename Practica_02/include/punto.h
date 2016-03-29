#ifndef _PUNTO_H_
#define _PUNTO_H_

struct Punto {
    double x,y;
};

Punto LeerPunto();

void EscribirPunto (Punto p);

bool Leer(std::istream& is, Punto& p);

bool Escribir(std::ostream& os, const Punto& p);

void InicializarPunto (Punto &p, double cx, double cy);

double GetX (Punto p);

double GetY (Punto p);

double Distancia (Punto p1, Punto p2);

Punto PuntoMedio (Punto p1, Punto p2);

#endif
