#include <iostream>
using namespace std;

int main(){
   int num;
   cout << "Introduzca un numero entre 0 y 25: ";
   cin >> num;

   while(num < 0 || num > 25){
      cout << "Introduzca un numero entre 0 y 25: ";
      cin >> num;
   }

   

}
