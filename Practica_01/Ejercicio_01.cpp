/*
  Programa que impirme ordenandamente los tamaños de los distintos tipos
  para la plataforma en la que se está trabajando
*/

#include <iostream>
using namespace std;

int main(){
   cout << "char: " << sizeof(char) << endl;
   cout << "short int: " << sizeof(short int) << endl;
   cout << "int: " << sizeof(int) << endl;
   cout << "long int: " << sizeof(long int) << endl;
   cout << "float: " << sizeof(float) << endl;
   cout << "double: " << sizeof(double) << endl;
   cout << "long double: " << sizeof(long double) << endl;
   cout << "long long: " << sizeof(long long) << endl;
}
