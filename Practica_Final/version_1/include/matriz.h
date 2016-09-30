#ifndef _MATRIZ_H_
#define _MATRIZ_H_

class Matriz {
private:
   int datos[20][20];
   int filas, columnas;

public:
   Matriz();
   int GetFilas() const;
   void SetFilas(int f);
   int GetColumnas() const;
   void SetColumnas(int c);
   int GetElementoPosicion(int f, int c) const;
   void SetElementoPosicion(int f, int c, int v);
   int GetFichasTotales() const;
   void VaciarMatriz();
};

#endif
