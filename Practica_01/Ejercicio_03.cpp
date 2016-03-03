#include <iostream>
#include <limits>
using namespace std;

int main(){
   int maximo = numeric_limits<int>::max();
   int minimo = numeric_limits<int>::min();

   cout << "maximo + 1 = " << maximo + 1 << endl;
   cout << "minimo - 1 = " << minimo - 1 << endl;
}
