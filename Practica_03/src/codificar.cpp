/**
  * @file codificar.cpp
  * @brief Fichero con definiciones para la codificación
  * de imagenes
  *
  * Permite ocultar o revelar mensajes en archivos de
  * tipos PGM o PPM
  *
  */

#include <iostream>
#include <cstring>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

// _____________________________________________________________________________

bool Ocultar(unsigned char buffer[], const char mensaje[], int num_pixeles){
   bool oculta = false;
	int tamanio_mensaje;
	tamanio_mensaje = strlen(mensaje) + 1;
	int contador = 0;

	if(tamanio_mensaje * 8 <= num_pixeles){				// Tamanio de cada letra (tamanio_mensaje * 8)
		for(int i = 0; i < tamanio_mensaje; ++i){			// Recorro el mensaje
			for(int j = 7; j >=0 ; --j){				// Recorro los bits de cada letra
				if((mensaje[i] & (1 << j)) != 0){		// Compruebo que se encuentra desactivado
					buffer[contador] = buffer[contador] | 1;	// Activo el bit del pixel
				}
				else{
					buffer[contador] = buffer[contador] &~1;	// Desactivo el bit del pixel
				}
				contador++;
			}
		}
		oculta = true;
	}

	return oculta;

}

// _____________________________________________________________________________

bool Revelar(const unsigned char buffer[], const int num_pixeles, char mensaje[], const int longitud_mensaje){
   bool revelada = true;
   unsigned char caracter;
   int bit = 0;

   if(longitud_mensaje <= (num_pixeles / 8) ){ 			// Si el tamaño del mensaje es menor que la longitud_Mensaje
      for(int i = 0; i < longitud_mensaje; ++i){
         for (int j = 0; j < 8; ++j){
            bit = buffer[ (i*8) + j] & 1; 	// aquí es donde esta el truco el cálculo del bit que estamos analizando
            if (bit == 0){
               caracter = caracter << 1;	// Desplazo el último bit una posición a la izquierda
            }
            else{
               caracter = caracter << 1;
               caracter = caracter | 1;	// Desactivo el bit
            }
         }
         if (i < longitud_mensaje){
            mensaje[i] = caracter;
         }
      }
   }
   else{
      revelada = false;
   }

   return revelada;
}

/* Fin Fichero: codificar.cpp */
