#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include <stdlib.h>
#include "tablero.h"
using namespace std;

class Jugador {
private:
   char *nombre;
   int turno, puntuacion, ganadas;

public:
   Jugador();
   Jugador(char n[], int t);
   Jugador(char n[], int t, int p, int g);
   Jugador(const Jugador &j);
   ~Jugador();
   Jugador& operator=(const Jugador &j);
   char* GetNombre() const;
   void SetNombre(char n[]);
   void ImprimirNombre(ostream &os) const;
   int GetTurno() const;
   void SetTurno(int t);
   int GetPuntuacion() const;
   void SetPuntuacion(int p);
   void AddPuntuacion(int p);
   int GetPartidaGanada() const;
   void SetPartidaGanada(int g);
   void AddPartidaGanada();
   void MostrarResultados() const;
   bool EscogerColumna(Tablero& tab);
};

ostream& operator<<(ostream &os, const Jugador &j);
istream& operator>>(istream &is, Jugador &j);

#endif
