/**
  * @file ocultar.cpp
  * @brief Programa para ocultar un mensaje en una imagen
  * de tipo PGM o PPM
  *
  */

#include <iostream>
#include <cstring>
#include "codificar.h"
#include "imagenES.h"

using namespace std;

int main(){

	const int MAXBUFFER = 1000000;
	const int MAXNOMBRE = 100;
	const int MAXMENSAJE = 125000;
	char nombre_imagen[MAXNOMBRE];
	unsigned char buffer[MAXBUFFER];
	char mensaje[MAXMENSAJE];
	TipoImagen imagen;
	bool leido, ocultada, escrita_imagen;
	int filas = 0, columnas = 0;

	cout << "Introduzca la imagen de entrada: ";
	cin.getline(nombre_imagen, MAXNOMBRE);

	imagen = LeerTipoImagen(nombre_imagen, filas, columnas);

	switch (imagen) {
      case IMG_PGM : leido = LeerImagenPGM(nombre_imagen,filas,columnas,buffer);
         break;
      case IMG_PPM : leido = LeerImagenPPM(nombre_imagen,filas,columnas,buffer);
         break;
      case IMG_DESCONOCIDO : cout << "Imagen desconocida" << endl;
         break;
   }

   if(!leido){
	   cout << "Error no se ha podido leer la imagen " << endl;
		return -1;
	}

	do{
		cout << "Introduzca la imagen de salida: ";
		cin.getline(nombre_imagen, MAXNOMBRE);
	}while(strlen(nombre_imagen) < 1);

	do{
		cout << "Introduzca el mensaje: ";
		cin.getline(mensaje, MAXMENSAJE);
	}while(strlen(mensaje) < 1);

	cout << "Ocultando..." << endl;

	ocultada = Ocultar(buffer, mensaje, filas*columnas);

	if(ocultada){
		cout << "Se ha ocultado el mensaje en la imagen con éxito " << endl;
	}
	else{
		cout << "No se ha ocultado el mensaje en la imagen " << endl;
	}

	switch(imagen){
		case IMG_PGM : escrita_imagen = EscribirImagenPGM (nombre_imagen, buffer, filas, columnas);
			break;
		case IMG_PPM : escrita_imagen = EscribirImagenPPM(nombre_imagen, buffer, filas, columnas);
			break;
		case IMG_DESCONOCIDO:
			break;
	}

	if(!escrita_imagen){
		cout << "Error no se ha podido escribir la imagen " << endl;
	}

}

/* Fin Fichero: ocultar.cpp */
