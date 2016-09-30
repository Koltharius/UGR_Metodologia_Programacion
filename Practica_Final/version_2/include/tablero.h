#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <iostream>
#include "matriz.h"

using namespace std;

class Tablero {
private:
   Matriz tablero;
   int turno, fichas_objetivo, ganador, fichas_turno, insertadas_turno;

public:
   Tablero();
   Tablero(int f, int c, int fichas, int ft);
   int GetFilas() const;
   int GetColumnas() const;
   int GetFichasObjetivo() const;
   void SetFichasObjetivo(int f);
   int GetFichasTurno() const;
   void SetFichasTurno(int f);
   int GetFichasInsertadasTurno() const;
   void SetFichasInsertadasTurno(int f);
   void AumentarInsertadasTurno();
   void VaciarInsertadasTurno();
   int GetTurno() const;
   void SetTurno(int n);
   void CambiarTurno();
   int GetPuntuacion();
   int GetGanador() const;
   void SetGanador();
   int GetTipoFicha(int f, int c) const;
   bool InsertarFichaPosicion(int c);
   bool ComprobarHorizontal(int f, int c);
   bool ComprobarVertical(int f, int c);
   bool ComprobarDiagonal(int f, int c);
   bool ComprobarDiagonalInvertida(int f, int c);
   bool EnLinea();
   int GetFinalizada();
   void Vaciar();
   void PrettyPrint(ostream &os = cout);
   void LeerMatrizTablero(istream &is);
   void EscribirMatrizTablero(ostream &os) const;
};

ostream& operator<<(ostream &os, const Tablero &tab);
istream& operator>>(istream &is, Tablero &tab);

#endif
