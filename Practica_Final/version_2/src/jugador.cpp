#include <iostream>
#include <string.h>
#include "jugador.h"

using namespace std;

Jugador::Jugador() {
   nombre = 0;
   SetTurno(0);
   SetPuntuacion(0);
   SetPartidaGanada(0);
}

Jugador::Jugador(char n[], int t) {
   SetNombre(n);
   SetTurno(t);
   SetPuntuacion(0);
   SetPartidaGanada(0);
}

Jugador::Jugador(char n[], int t, int p, int g) {
   SetNombre(n);
   SetTurno(t);
   SetPuntuacion(p);
   SetPartidaGanada(g);
}

Jugador::Jugador(const Jugador& j) {
   nombre = new char[strlen(j.nombre)];
   for (size_t i = 0; i < strlen(j.nombre); i++) {
      nombre[i] = j.nombre[i];
   }
   turno = j.turno;
   puntuacion = j.puntuacion;
   ganadas = j.ganadas;
}

Jugador::~Jugador() {
   delete[] nombre;
   turno = 0;
   puntuacion = 0;
   ganadas = 0;
}

Jugador& Jugador::operator=(const Jugador& j) {
   SetNombre(j.GetNombre());
   SetTurno(j.GetTurno());
   SetPuntuacion(j.GetPuntuacion());
   SetPartidaGanada(j.GetPartidaGanada());
   return *this;
}

char* Jugador::GetNombre() const {
   return nombre;
}

void Jugador::SetNombre(char n[]) {
   nombre = new char[strlen(n)];
   strcpy(nombre, n);
}

void Jugador::ImprimirNombre(ostream &os) const {
   for (int i = 0; nombre[i] != '\0'; ++i) {
      os << nombre[i];
   }
}

int Jugador::GetTurno() const {
   return turno;
}

void Jugador::SetTurno(int t) {
   turno = t;
}

int Jugador::GetPuntuacion() const {
   return puntuacion;
}

void Jugador::SetPuntuacion(int p) {
   puntuacion = p;
}

void Jugador::AddPuntuacion(int p) {
   puntuacion += p;
}

int Jugador::GetPartidaGanada() const {
   return ganadas;
}

void Jugador::SetPartidaGanada(int g) {
   ganadas = g;
}

void Jugador::AddPartidaGanada() {
   ganadas++;
}

void Jugador::MostrarResultados() const {
   ImprimirNombre(cout);
   cout << endl << "\t -" << GetPuntuacion() << " puntos" << endl;
   cout << "\t -" << GetPartidaGanada() << " partidas ganadas" << endl;
}

bool Jugador::EscogerColumna(Tablero& tab) {
   bool exito = false;
   tab.PrettyPrint();
   if (nombre[0] == '@') {
      while (!exito) {
         exito = tab.InsertarFichaPosicion(rand() % tab.GetColumnas());
      }
   } else {
      char col;
      ImprimirNombre(cout);
      cout << " escoja una columna: ";
      cin >> col;
      exito = tab.InsertarFichaPosicion(col - 'a');
   }

   return exito;
}

ostream& operator<<(ostream &os, const Jugador &j) {
   os << '#';
   j.ImprimirNombre(os);
   os << "\n";
   os << j.GetTurno() << " ";
   os << j.GetPuntuacion() << " ";
   os << j.GetPartidaGanada() << " ";
   return os;
}

istream& operator>>(istream &is, Jugador &j) {
   char *n = new char[0];
   int t = 0;
   int p = 0;
   int g = 0;

   while (is.peek() != '#') {
      is.ignore();
   }
   is.ignore();
   is >> n >> t >> p >> g;
   j.SetNombre(n);
   j.SetTurno(t);
   j.SetPuntuacion(p);
   j.SetPartidaGanada(g);

   delete[] n;
   return is;
}
