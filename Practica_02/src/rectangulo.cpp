#include <iostream>
#include "punto.h"
#include "rectangulo.h"
using namespace std;

bool Leer(std::istream& is, Rectangulo& r){
   is.ignore();
   is >> r.e_inf_izda.x;
   is.ignore();
   is >> r.e_inf_izda.y;
   is.ignore();
   is >> r.e_sup_dcha.x;
   is.ignore();
   is >> r.e_sup_dcha.y;
   return is;
}

bool Escribir(ostream& os, const Rectangulo& r){
   os << "(" << r.e_inf_izda.x << "," << r.e_inf_izda.y << ") (" << r.e_sup_dcha.x << "," << r.e_sup_dcha.y << ")";
   return os.fail();
}

void InicializarRectangulo(Rectangulo& r, const Punto& p1, const Punto& p2){
   if(p1.x < p2.x){
      r.e_inf_izda.x = p1.x;
      r.e_sup_dcha.x = p2.x;
   }
   else{
      r.e_inf_izda.x = p2.x;
      r.e_sup_dcha.x = p1.x;
   }

   if(p1.y < p2.y){
      r.e_inf_izda.y = p1.y;
      r.e_sup_dcha.y = p2.y;
   }
   else{
      r.e_inf_izda.y = p2.y;
      r.e_sup_dcha.y = p1.y;
   }
}

Punto InferiorIzquierda(const Rectangulo& r){
   return r.e_inf_izda;
}

Punto SuperiorDerecha(const Rectangulo& r){
   return r.e_sup_dcha;
}

double Area(const Rectangulo& r){
   return (r.e_sup_dcha.x - r.e_inf_izda.x) * (r.e_sup_dcha.y - r.e_inf_izda.y);
}

bool Interior(const Punto& p, const Rectangulo& r){
   return ((p.x <= r.e_sup_dcha.x && p.x >= r.e_inf_izda.x) && (p.y <= r.e_sup_dcha.y && p.y >= r.e_inf_izda.y));
}
