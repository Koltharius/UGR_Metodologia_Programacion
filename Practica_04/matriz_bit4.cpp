#include "matriz_bit4.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
   bool exito = false;
   if(fils * cols <= 128){
      m.filas_columnas = 0;
      m.filas_columnas = ((m.filas_columnas | fils) << 8) | cols;
      for(int i=0; i<(fils * cols) / 32; ++i){
         m.matriz[i] = 0;
      }
      exito = true;
   }
   return exito;
}

int Filas(const MatrizBit& m){
   int filas = 0;
   for(int i=0; i<8; ++i){
      if(m.filas_columnas&(1<<i) != 0){
         filas = filas | (1<<(i));
      }
   }
   return filas;
}

int Columnas(const MatrizBit& m){
   int columnas = 0;
   for(int i=8; i<16; ++i){
      if(m.filas_columnas&(1<<i) != 0){
         columnas = columnas | (1<<(i-8));
      }
   }
   return columnas;
}

bool Get(const MatrizBit& m, int f, int c){
   bool exito = true;
   int bit = f * Columnas(m) + c;
   int indice = bit / 32;

   if ((m.matriz[indice] & (1<<(bit - 32 * indice))) == 0){
      exito = false;
   }
   return exito;
}

void Set(MatrizBit& m, int f, int c, bool v){
   int bit = f * Columnas(m) + c;
   int indice = bit / 32;

   if(v){
      m.matriz[indice] = m.matriz[indice] | (1 << (bit - 32 * indice));
   }
   else{
      m.matriz[indice] = m.matriz[indice] & ~ (1 << (bit - 32 * indice));
   }
}
