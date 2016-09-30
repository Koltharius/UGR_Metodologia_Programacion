#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "tablero.h"

class Jugador {
private:
   char nombre[50];
   int turno, puntuacion, ganadas;

public:
   Jugador(char n[], int t);
   char GetNombre() const;
   void SetNombre(char n[]);
   void ImprimirNombre();
   int GetTurno() const;
   void SetTurno(int t);
   int GetPuntuacion() const;
   void SetPuntuacion(int p);
   void AddPuntuacion(int p);
   int GetPartidaGanada() const;
   void SetPartidaGanada(int g);
   void AddPartidaGanada();
   void MostrarResultados();
   void EscogerColumna(Tablero& tab);
};

#endif
