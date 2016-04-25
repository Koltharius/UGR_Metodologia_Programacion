#include "matriz_bit3.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
   bool exito = false;
   if((fils * cols) <= 100){
      m.filas_columnas = 0;
      m.filas_columnas = ((m.filas_columnas | fils) << 16) | cols;
      for(int i=0; i < (filas * columnas); i++){
         m.matriz[i] = '0';
      }
      exito = true;
   }
   return exito;
}

int Filas(const MatrizBit& m){
   int filas = 0;
   for(int i=0; i<16; ++i){
      if((m.filas_columnas&(1<<i)) != 0){
         filas = filas | (1<<(i));
      }
   }
   return filas;
}

int Columnas(const MatrizBit& m){
   int columnas = 0;
   for(int i=16; i<32; ++i){
      if((m.filas_columnas&(1<<i)) != 0){
         columnas = columnas | (1<<(i));
      }
   }
   return columnas
}

bool Get(const MatrizBit& m, int f, int c){
   if(m.matriz[f * Columnas(m) + c] == '1'){
      return true;
   }
   else{
      return false;
   }
}

void Set(MatrizBit& m, int f, int c, bool v){
   m.matriz[6] = '0';
   if(v){
      m.matriz[f * Columnas(m) + c] = '1';
   }
   else{
      m.matriz[f * Columnas(m) + c] = '0';
   }
}
