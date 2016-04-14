/**
  * @file revelar.cpp
  * @brief Programa para revelar un mensaje oculto en una
  * imagen de tipo PPM o PGM
  */

#include <iostream>
#include <cstring>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

int main(){

	const int MAXBUFFER = 1000000;
	const int MAXNOMBRE = 100;
	const int MAXMENSAJE = 125000;
	char nombre_imagen[MAXNOMBRE];
	unsigned char buffer[MAXBUFFER];
	char mensaje[MAXMENSAJE];
	TipoImagen imagen;
	bool leido, revelada;
	int filas = 0, columnas = 0;

   cout << "Introduzca la imagen de entrada: ";
	cin.getline(nombre_imagen, MAXNOMBRE);

	imagen = LeerTipoImagen(nombre_imagen, filas, columnas);

	switch (imagen) {
      case IMG_PGM : leido = LeerImagenPGM(nombre_imagen,filas,columnas,buffer);
         break;
      case IMG_PPM : leido = LeerImagenPPM(nombre_imagen,filas,columnas,buffer);
         break;
      default: cout << "Imagen desconocida";
         return -1;
   }

   if(!leido){
	   cout << "Error no se ha podido leer la imagen " << endl;
      return -1;
   }

   cout << "Revelando..." << endl;

   revelada = Revelar(buffer,filas*columnas, mensaje, MAXMENSAJE);

   if(revelada){
   	cout << "Se ha revelado el mensaje de la imagen con éxito " << endl;
   	cout << "El mensaje obtenido es: " << endl;
      cout << mensaje << endl;
   }
   else{
   	cout << "No se ha revelado el mensaje de la imagen con éxito " << endl;
   }
}

/* Fin Fichero: revelar.cpp */
