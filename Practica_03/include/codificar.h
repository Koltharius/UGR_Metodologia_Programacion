/**
  * @file codificar.h
  * @brief Fichero cabecera para la codificación de imágenes
  *
  * Permite ocultar o revelar mensajes en archivos de
  * tipos PGM o PPM
  *
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Oculta un mensaje en una imagen de tipo PGM o PPM
  *
  * @param buffer indica el nombre de la imagen que le pasamos
  * @param num_pixeles indica el número de píxeles de la imagen
  * @param mensaje indica el mensaje que queremos ocultar en la imagen
  * @return Devuelve si se ha ocultado con éxito el mensaje en la imagen
  */

	bool Ocultar(unsigned char buffer[],const char mensaje[], const int num_pixeles);

/**
  * @brief Revela un mensaje oculto en una imagen de tipo PGM o PPM
  *
  * @param imagen indica el nombre de la imagen que le pasamos.
  * @param num_pixeles indica el número de pixeles de la imagen
  * @param mensaje indica el mensaje revelado en la imagen
  * @param long_mensaje indica la longitud del mensaje revelado
  * @return Devuelve si se ha desvelado con éxito la imagen
  */

  bool Revelar(const unsigned char buffer[], const int num_pixeles, char mensaje[], const int longitud_Mensaje);


#endif

/* Fin Fichero: codificar.h */
