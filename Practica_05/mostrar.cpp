#include <iostream>
#include <fstream> // ifstream
using namespace std;

// FIXME 5: añadir un nuevo campo
struct VecDin {
   int *datos;
   int n;
};

// FIXME 1: Redimensions v para que se quede con "nuevo" elementos
// FIXME 5: tener en cuenta un nuevo campo en v
void ReSize(VecDin& v,int nuevo){
   
}

// FIXME 2: Lee objetos int hasta final de flujo y devuelve VecDin con los datos (usa ReSize)
VecDin LeerVecDin(istream& flujo){

}

// FIXME 3: Muestra en un flujo de salida los datos enteros de un VecDin (ver main)

Mostrar

// FIXME 3: Libera la memoria reservada en un VecDin (ver main)

Liberar


// FIXME 4: Añade un dato al final del vector
// FIXME 6: Mejora de eficiencia con reservados
void Add(VecDin& v,int dato){

}

// FIXME 7: Ordena v con "Selección" implementado recursivo
void SeleccionRecursivo(int *v, int n){

}

// FIXME 7: Usa SeleccionRecursivo para ordenar v
void Ordenar(VecDin& v){

}


int main(int argc, char *argv[]){
   VecDin v= {0,0};

   if (argc==1)
      v= LeerVecDin(cin);
   else {
      ifstream f(argv[1]);
      if (!f) {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      v= LeerVecDin(f);
   }

   Mostrar(v,cout);
   Liberar(v); // Libera la memoria reservada
}
