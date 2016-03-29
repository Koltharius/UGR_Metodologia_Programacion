#include <iostream>
#include <cmath>
#include "punto.h"

using namespace std;

Punto LeerPunto(){
   Punto p;
   char c;
   cin >> c >> p.x >> c >> p.y >> c;
   return p;
}

void EscribirPunto (Punto p){
   cout << "(" << p.x << "," << p.y << ")";
}

bool Leer(istream& is, Punto& p){
   is.ignore();
   is >> p.x;
   is.ignore();
   is >> p.y;
   is.ignore();
   return is;
}

bool Escribir(ostream& os, const Punto& p){
   os << "(" << p.x << "," << p.y << ")";
   return os.fail();
}

void InicializarPunto (Punto &p, double cx, double cy){
   p.x = cx;
   p.y = cy;
}

double GetX (Punto p){
   return p.x;
}

double GetY (Punto p){
   return p.y;
}

double Distancia (Punto p1, Punto p2){
   double a, b;
   a = (p2.x * p2.x) - (p1.x * p1.x);
   b = (p2.y * p2.y) - (p1.y * p1.y);
   return sqrt(a + b);
}

Punto PuntoMedio (Punto p1, Punto p2){
   Punto punto_medio;
   punto_medio.x = (p1.x + p2.x) / 2;
   punto_medio.y = (p1.y + p2.y) / 2;

   return punto_medio;
}
