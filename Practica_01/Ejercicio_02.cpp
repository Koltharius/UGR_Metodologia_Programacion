#include <iostream>
#include <limits>
using namespace std;

int main(){
   cout << "signed short int: " << numeric_limits<signed short int>::min() << endl;
   cout << "signed short int: " << numeric_limits<signed short int>::max() << endl;

   cout << "signed int: " << numeric_limits<signed int>::min() << endl;
   cout << "signed int: " << numeric_limits<signed int>::max() << endl;

   cout << "signed long: " << numeric_limits<signed long>::min() << endl;
   cout << "signed long: " << numeric_limits<signed long>::max() << endl;

   cout << "signed long int: " << numeric_limits<signed long int>::min() << endl;
   cout << "signed long int: " << numeric_limits<signed long int>::max() << endl;

   cout << "unsigned short int: " << numeric_limits<unsigned short int>::min() << endl;
   cout << "unsigned short int: " << numeric_limits<unsigned short int>::max() << endl;

   cout << "unsigned int: " << numeric_limits<unsigned int>::min() << endl;
   cout << "unsigned int: " << numeric_limits<unsigned int>::max() << endl;

   cout << "unsigned long int:" << numeric_limits<unsigned long int>::min() << endl;
   cout << "unsigned long int:" << numeric_limits<unsigned long int>::max() << endl;

   cout << "float: " << numeric_limits<float>::min() << endl;
   cout << "float: " << numeric_limits<float>::max() << endl;

   cout << "double: " << numeric_limits<double>::min() << endl;
   cout << "double: " << numeric_limits<double>::max() << endl;

   cout << "long double: " << numeric_limits<long double>::min() << endl;
   cout << "long double: " << numeric_limits<long double>::max() << endl;
}
