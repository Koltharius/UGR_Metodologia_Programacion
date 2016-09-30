#include <iostream>
#include <cctype>
#include <fstream>
#include <string.h>
#include "tablero.h"
#include "jugador.h"

using namespace std;

bool CargarArchivo(const char *c, Jugador &j1, Jugador &j2, Tablero &t) {
   ifstream f(c, ios::in);
   if (f) {
      char tmp;
      const char* req = "#PARTIDA";
      while (f.peek() != '#') {
         f.ignore();
      }
      for (size_t i = 0; i < strlen(req); i++) {
         f >> tmp;
         if (tmp != req[i])
            return false;
      }
      f >> j1;
      f >> j2;
      f >> t;
   }
   f.close();
   return f.good();
}

bool GuardarArchivo(char c[], Jugador j1, Jugador j2, Tablero t) {
   ofstream f(c, ios::out);
   if (f) {
      f << "#PARTIDA" << endl;
      f << j1 << endl;
      f << j2 << endl;
      f << t;
      f.close();
   }
   return f.good();
}

bool JugarTurno(Jugador &j, Tablero &t) {
   cout << "Turno de ";
   j.ImprimirNombre(cout);
   switch (j.GetTurno()) {
      case 1:
         cout << " (x)" << endl;
         break;
      case 2: cout << " (o)" << endl;
         break;
   }
   return j.EscogerColumna(t);
}

int main(int argc, char** argv) {
   int f = 0, c = 0, o = 0, t = 0;
   char *nombre1 = new char[0];
   char *nombre2 = new char[0];
   bool partida;
   Jugador jugador1, jugador2;
   Tablero tablero;

   if (argc == 2) {
      CargarArchivo(argv[1], jugador1, jugador2, tablero);
   } else if (argc == 1) {
      do {
         cout << "Introduzca el numero de filas (4-20): ";
         cin >> f;
      } while (f < 4 || f > 20);

      do {
         cout << "Introduzca el numero de columnas (4-20): ";
         cin >> c;
      } while (c < 4 || c > 20);
      int min;

      if (f <= c) {
         min = f;
      } else {
         min = c;
      }

      do {
         cout << "Introduzca el numero de fichas objetivo (3-" << min - 1 << "): ";
         cin >> o;
      } while (o < 3 || o >= c);

      do {
         cout << "Introduzca el numero de fichas a insertar por turno ";
         cin >> t;

      } while (t < 1 && t > o - 2);

      cout << "Introduzca el nombre del primer jugador: ";
      cin >> nombre1;
      cout << "Introduzca el nombre del segundo jugador: ";
      cin >> nombre2;

      tablero = Tablero(f, c, o, t);
      jugador1 = Jugador(nombre1, 1);
      jugador2 = Jugador(nombre2, 2);

   } else {
      cout << "Error de ejecucion. Introduzca bien los parametros o el nombre del archivo." << endl;
   }

   do {
      do {
         bool exito = false;
         char res, archivo[100];

         if (tablero.GetFichasTurno() == tablero.GetFichasInsertadasTurno())
            tablero.CambiarTurno();

         while (!exito) {
            switch (tablero.GetTurno()) {
               case 1:
                  exito = JugarTurno(jugador1, tablero);
                  break;
               case 2:
                  exito = JugarTurno(jugador2, tablero);
                  break;
            }

            if (!exito) {
               cout << "Error en la introducción de la columna. ¿Quieres guardar la partida? (S/N) ";
               cin >> res;
               if (tolower(res) == 's') {
                  cout << "Nombre del archivo: ";
                  cin >> archivo;
                  GuardarArchivo(archivo, jugador1, jugador2, tablero);
               }
            }
            if (exito) {
               tablero.AumentarInsertadasTurno();
            }
         }
      } while (tablero.GetFinalizada() == 0);

      if (tablero.GetFinalizada() == 2) {
         cout << "Empate" << endl;
         tablero.Vaciar();
      } else {
         tablero.PrettyPrint();
         tablero.SetGanador();
         tablero.Vaciar();
         int puntuacion = tablero.GetPuntuacion();

         if (tablero.GetGanador() == 1) {
            jugador1.AddPuntuacion(puntuacion);
            jugador1.AddPartidaGanada();
         } else if (tablero.GetGanador() == 2) {
            jugador2.AddPuntuacion(puntuacion);
            jugador2.AddPartidaGanada();
         }

         cout << endl << "Resultados:" << endl << endl;
         jugador1.MostrarResultados();
         cout << endl;
         jugador2.MostrarResultados();
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

   cout << endl << "Resultados finales: " << endl;
   jugador1.MostrarResultados();
   cout << endl;
   jugador2.MostrarResultados();

   return 0;
}
