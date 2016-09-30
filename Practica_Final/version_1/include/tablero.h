#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "matriz.h"

class Tablero {
private:
   Matriz tablero;
   int turno, fichas_objetivo, ganador;

public:
   Tablero(int f, int c, int fichas);
   int GetFilas();
   int GetColumnas();
   int GetFichasObjetivo() const;
   void SetFichasObjetivo(int f);
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
   void PrettyPrint();
};

#endif
