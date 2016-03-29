#include <fstream>
#include <iostream>
#include "punto.h"
using namespace std;

void Avanzar(std::istream& is){
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}

double Longitud(istream &is){
   double l = 0;
   Punto p1, p2;
   Avanzar(is);
   Leer(is,p1);
   Avanzar(is);
   while(Leer(is,p2)){
      l = l + Distancia(p1,p2);
      p1 = p2;
      Avanzar(is);
   }
   return l;
}

int main(int argc, char* argv[]){
  double longitud= 0;
  bool fin_entrada;
  if (argc==1) { // Si no hemos dado parámetros en la línea de órdenes
    longitud= Longitud(cin);
    fin_entrada=cin.eof();
  }
  else {
    ifstream f(argv[1]); // Como parámetro, el nombre del archivo
    if (!f) {
      cerr << "Error: no se abre " << argv[1] << endl;
      return 1;
    }
    longitud=Longitud(f);
    fin_entrada=f.eof();
  }

  if (!fin_entrada) {
     cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
     return 1;
  }
  cout << "Longitud: " << longitud << endl;
}
