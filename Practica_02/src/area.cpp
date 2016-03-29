#include <iostream>
#include "circulo.h"
using namespace std;

int main() {
   Circulo circulo;
   cout << "Introduzca el circulo al que le vamos a calcular el area: ";
   circulo = LeerCirculo();
   cout << "El area del circulo introducido es " << Area(circulo) << endl;
   return 0;
}
