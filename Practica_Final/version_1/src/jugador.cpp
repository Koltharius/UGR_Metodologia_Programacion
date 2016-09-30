#include <iostream>
#include "jugador.h"

using namespace std;

Jugador::Jugador(char n[], int t) {
   SetNombre(n);
   SetTurno(t);
   SetPuntuacion(0);
   SetPartidaGanada(0);
}

char Jugador::GetNombre() const {
   return *nombre;
}

void Jugador::SetNombre(char n[]) {
   for (int i = 0; i < 50; ++i) {
      nombre[i] = n[i];
   }
}

void Jugador::ImprimirNombre() {
   for (int i = 0; i < 50 && nombre[i] != '\0'; ++i) {
      cout << nombre[i];
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

void Jugador::MostrarResultados() {
   ImprimirNombre();
   cout << endl << "\t -" << GetPuntuacion() << " puntos" << endl;
   cout << "\t -" << GetPartidaGanada() << " partidas ganadas" << endl;
}

void Jugador::EscogerColumna(Tablero& tablero) {
   tablero.PrettyPrint();
   char columna;
   do {
      ImprimirNombre();
      cout << " elija una columna: ";
      cin >> columna;
   } while (!tablero.InsertarFichaPosicion(columna - 'a'));
}
