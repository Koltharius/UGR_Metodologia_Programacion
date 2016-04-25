#include <iostream>
#include <iosfwd>
#include <fstream>
#include "string.h"
#include "matriz_bit.h"
using namespace std;

bool Leer(std::istream& is, MatrizBit& m){
   bool exito = true;
   int columnas = 0, filas = 0;

   while(isspace(is.peek())){
      is.ignore();
   }

   if(is.peek() == 'X' || is.peek() == '.'){
      char valores[1000];
      char aux[100];

      is.getline(aux, 100);
      columnas = strlen(aux);
      filas++;
      strcpy(valores,aux);

      while((is.peek() == 'X' || is.peek() == '.') && exito){
         is.getline(aux,100);
         strcat(valores,aux);
         filas++;
         if(int(strlen(aux)) != columnas){
            exito = false;
         }
      }

      if(exito){
         exito = Inicializar(m, filas, columnas);
      }

      for(int i=0; i<filas; ++i){
         for(int j=0; j < columnas && exito; ++j){
            if(valores[i * columnas + j] == 'X'){
               Set(m, i, j, true);
            }
            else if(valores[i * columnas + j] == '.'){
               Set(m, i, j, false);
            }
            else{
               exito = false;
            }
         }
      }
   }

   else{
      is >> filas;
      is >> columnas;
      bool exito = is && Inicializar(m, filas, columnas);
      char v;

      if(exito){
         for(int i=0; i<Filas(m); ++i){
            for(int j=0; j<Columnas(m); ++j){
               is >> v;
               if(v=='1'){
                  Set(m, i, j, true);
               }
               else if(v=='0'){
                  Set(m, i, j, false);
               }
            }
           exito = !is.fail();
         }
      }
   }
   return exito;
}

bool Escribir(std::ostream& os, const MatrizBit& m) {
   os << Filas(m) << ' ' << Columnas(m) << endl;
   for(int i=0; i < Filas(m); i++){
      for(int j=0; j<Columnas(m); j++){
         bool v=Get(m, i, j);
         if(v){
            os << '1';
         }
         else{
            os << '0';
         }
         os << ' ';
      }
      cout << endl;
   }
   return os;
}

bool Leer(const char nombre[], MatrizBit& m){
   ifstream archivo(nombre);
   bool exito = false;
   if(archivo){
      exito = Leer(archivo, m);
   }
   return exito;
}

bool Escribir(const char nombre[], const MatrizBit& m){
   ofstream archivo(nombre);
   bool exito = false;
   if(archivo){
      exito = Escribir(archivo, m);
   }
   return exito;
}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
   if((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))){
      Inicializar(res, Filas(m1), Columnas(m1));
      for(int i=0; i<Filas(m1); ++i){
         for(int j=0; i<Columnas(m1); ++j){
            Set(res, i, j, (Get(m1,i,j) && Get(m2,i,j)));
         }
      }
   }
   else{
      cout << "Las matrices no tienen el mismo tamaño." << endl;
   }
}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
   if((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))){
      Inicializar(res, Filas(m1), Columnas(m1));
      for(int i=0; i<Filas(m1); i++){
         for(int j=0; j<Columnas(m1); j++){
            Set(res, i, j, (Get(m1,i,j) || Get(m2,i,j)));
         }
      }
   }
   else{
      cout << "Las matrices no tienen el mismo tamaño." << endl;
   }
}

void Not(MatrizBit& res, const MatrizBit& m){
   Inicializar(res, Filas(m), Columnas(m));
   for(int i=0; i<Filas(m); i++){
      for(int j=0; j<Columnas(m); j++){
         Set(res, i, j, !Get(m, i, j));
      }
   }
}

void Traspuesta(MatrizBit& res, const MatrizBit& m){
   Inicializar(res, Columnas(m), Filas(m));
   for(int i=0; i<Filas(m); i++){
      for(int j=0; j<Columnas(m); j++){
         Set(res, j, i, Get(m, i, j));
      }
   }
}
