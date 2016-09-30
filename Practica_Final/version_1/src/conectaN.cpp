#include <iostream>
#include <cctype>
#include "tablero.h"
#include "jugador.h"

using namespace std;

int main(int argc, char** argv) {
   int filas, columnas, fichas;
   char jugador1[50];
   char jugador2[50];

   do {
      cout << "Introduzca el numero de filas (4-20): ";
      cin >> filas;
   } while (filas < 4 || filas > 20);

   do {
      cout << "Introduzca el numero de columnas (4-20): ";
      cin >> columnas;
   } while (columnas < 4 || columnas > 20);

   int min;

   if (filas <= columnas) {
      min = filas;
   } else {
      min = columnas;
   }

   do {
      cout << "Introduzca el numero de fichas objetivo (3-" << min - 1 << "): ";
      cin >> fichas;
   } while (fichas < 3 || fichas >= min);

   cout << "Introduzca el nombre del primer jugador: ";
   cin >> jugador1;
   cout << "Introduzca el nombre del segundo jugador: ";
   cin >> jugador2;

   Tablero tablero(filas, columnas, fichas);
   Jugador j1(jugador1, 1);
   Jugador j2(jugador2, 2);
   bool partida;

   do {
      tablero.Vaciar();
      do {
         tablero.CambiarTurno();
         cout << "Turno de" << tablero.GetTurno() << " ";
         if (tablero.GetTurno() == 1) {
            j1.ImprimirNombre();
            cout << " (x):" << endl;
            j1.EscogerColumna(tablero);
         } else {
            j2.ImprimirNombre();
            cout << " (o):" << endl;
            j2.EscogerColumna(tablero);
         }
      } while (tablero.GetFinalizada() == 0);

      if (tablero.GetFinalizada() == 2) {
         cout << "Empate" << endl;
      } else {
         tablero.PrettyPrint();
         tablero.SetGanador();
         int puntuacion = tablero.GetPuntuacion();

         if (tablero.GetGanador() == 1) {
            j1.AddPuntuacion(puntuacion);
            j1.AddPartidaGanada();
         } else if (tablero.GetGanador() == 2) {
            j2.AddPuntuacion(puntuacion);
            j2.AddPartidaGanada();
         }

         cout << endl << "Resultados:" << endl << endl;
         j1.MostrarResultados();
         cout << endl;
         j2.MostrarResultados();
      }

      char respuesta;
      do {
         cout << "Seguir jugando? (S/N): ";
         cin >> respuesta;
         respuesta = toupper(respuesta);
      } while (respuesta != 'S' && respuesta != 'N');

      if (respuesta == 'S') {
         partida = true;
      } else {
         partida = false;
      }

   } while (partida);

   if (!partida) {
      cout << endl << "Resultados finales: " << endl;
      j1.MostrarResultados();
      cout << endl;
      j2.MostrarResultados();
   }

   return 0;
}
