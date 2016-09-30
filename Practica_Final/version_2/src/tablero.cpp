#include <iostream>
#include "tablero.h"
using namespace std;

Tablero::Tablero() {
   tablero = Matriz(0, 0);
   SetFichasObjetivo(0);
   SetFichasTurno(0);
   VaciarInsertadasTurno();
   SetTurno(0);
   ganador = 0;
}

Tablero::Tablero(int f, int c, int fichas, int fichas_turno) {
   tablero = Matriz(f, c);
   SetFichasObjetivo(fichas);
   SetFichasTurno(fichas_turno);
   VaciarInsertadasTurno();
   SetTurno(1);
   ganador = 0;
}

int Tablero::GetFilas() const {
   return tablero.GetFilas();
}

int Tablero::GetColumnas() const {
   return tablero.GetColumnas();
}

int Tablero::GetFichasObjetivo() const {
   return fichas_objetivo;
}

void Tablero::SetFichasObjetivo(int f) {
   fichas_objetivo = f;
}

int Tablero::GetFichasTurno() const {
   return fichas_turno;
}

void Tablero::SetFichasTurno(int f) {
   fichas_turno = f;
}

int Tablero::GetFichasInsertadasTurno() const {
   return insertadas_turno;
}

void Tablero::SetFichasInsertadasTurno(int f) {
   insertadas_turno = f;
}

void Tablero::AumentarInsertadasTurno() {
   insertadas_turno++;
}

void Tablero::VaciarInsertadasTurno() {
   insertadas_turno = 0;
}

int Tablero::GetTurno() const {
   return turno;
}

void Tablero::SetTurno(int n) {
   turno = n;
}

void Tablero::CambiarTurno() {
   turno = turno == 2 ? 1 : 2;
   VaciarInsertadasTurno();
}

int Tablero::GetPuntuacion() {
   return (fichas_objetivo * 10 + ((GetFilas() * GetColumnas() / 2) - tablero.GetFichasTotales()));
}

int Tablero::GetGanador() const {
   return ganador;
}

void Tablero::SetGanador() {
   ganador = GetTurno();
   CambiarTurno();
}

int Tablero::GetTipoFicha(int f, int c) const {
   return tablero.GetElementoPosicion(f, c);
}

bool Tablero::ComprobarHorizontal(int f, int c) {
   for (int i = 0; i < GetFichasObjetivo() - 1; ++i) {
      if (GetTipoFicha(f, c + i) != GetTipoFicha(f, c + i + 1)) {
         return false;
      }
   }
   return true;
}

bool Tablero::ComprobarVertical(int f, int c) {
   for (int i = 0; i < GetFichasObjetivo() - 1; ++i) {
      if (GetTipoFicha(f + i, c) != GetTipoFicha(f + i + 1, c)) {
         return false;
      }
   }
   return true;
}

bool Tablero::ComprobarDiagonal(int f, int c) {
   for (int i = 0; i < GetFichasObjetivo() - 1; ++i) {
      if (GetTipoFicha(f + i, c + i) != GetTipoFicha(f + i + 1, c + i + 1)) {
         return false;
      }
   }
   return true;
}

bool Tablero::ComprobarDiagonalInvertida(int f, int c) {
   for (int i = 0; i < GetFichasObjetivo() - 1; ++i) {
      if (GetTipoFicha(f - i, c + i) != GetTipoFicha(f - i - 1, c + i + 1)) {
         return false;
      }
   }
   return true;
}

bool Tablero::EnLinea() {
   int n = GetFichasObjetivo();
   for (int fil = 0; fil < GetFilas(); fil++) {
      for (int col = 0; col < GetColumnas(); col++) {

         if (GetTipoFicha(fil, col) != 0) {

            if (col <= GetColumnas() - n && ComprobarHorizontal(fil, col))
               return true;
            if (fil <= GetFilas() - n && ComprobarVertical(fil, col))
               return true;
            if (col <= GetColumnas() - n && fil <= GetFilas() - n && ComprobarDiagonal(fil, col))
               return true;
            if (col <= GetColumnas() - n && fil >= n - 1 && ComprobarDiagonalInvertida(fil, col))
               return true;
         }
      }
   }

   return false;
}

int Tablero::GetFinalizada() {
   if (EnLinea())
      return 1;
   if (tablero.GetFichasTotales() == GetFilas() * GetColumnas())
      return 2;
   else
      return 0;
}

bool Tablero::InsertarFichaPosicion(int c) {
   if (c < 0 || c >= GetColumnas())
      return false;
   for (int i = 0; i < GetFilas(); i++) {

      if (GetTipoFicha(i, c) == 0) {
         tablero.SetElementoPosicion(i, c, GetTurno());
         return true;
      }
   }
   return false;
}

void Tablero::Vaciar() {
   tablero.VaciarMatriz();
}

void Tablero::LeerMatrizTablero(istream& is) {
   is >> tablero;
}

void Tablero::EscribirMatrizTablero(ostream& os) const {
   os << tablero;
}

void Tablero::PrettyPrint(ostream &os) {
   os << endl;
   char letra;
   os << " ";

   for (int i = 0; i < GetColumnas(); i++) {
      letra = ('a' + i);
      os << letra << " ";
   }
   os << endl;

   for (int i = GetFilas() - 1; i >= 0; i--) {

      os << "|";
      for (int j = 0; j < GetColumnas(); j++) {
         if (GetTipoFicha(i, j) == 1) {
            os << "x";
         } else if (GetTipoFicha(i, j) == 2) {
            os << "o";
         } else {
            os << " ";
         }
         os << "|";
      }
      os << endl;
   }
   for (int i = 0; i < 2 * GetColumnas() + 1; i++) {
      os << "=";
   }

   os << endl;
}

ostream& operator<<(ostream &os, const Tablero &tab) {
   os << tab.GetFichasObjetivo() << " ";
   os << tab.GetFichasTurno() << " ";
   os << tab.GetFichasInsertadasTurno() << " ";
   os << tab.GetTurno() << " ";
   os << tab.GetGanador() << "\n";
   tab.EscribirMatrizTablero(os);
   return os;
}

istream& operator>>(istream &is, Tablero &tab) {
   int o, tu, f, i, g;
   is >> o >> f >> i >> tu >> g;
   tab.SetFichasObjetivo(o);
   tab.SetFichasTurno(f);
   tab.SetFichasInsertadasTurno(i);
   tab.SetTurno(tu);
   tab.LeerMatrizTablero(is);
   return is;
}
