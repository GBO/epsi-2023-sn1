#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void permuter(int& a, int& b) {
  // Inversons !
  int c = a;
  a = b;
  b = c;
}

int main(int argc, char **argv)
{
  cout << "Exercice 5.4" << endl;

  int o = 12;
  int p = 24;

  permuter(o, p);
  cout << "O : " << o << endl;
  cout << "P : " << p << endl;

  permuter(o, p);
  cout << "O : " << o << endl;
  cout << "P : " << p << endl;

  // Ne compile pas (la constante 13 ne peut pas entrer dans un paramètre typé int&)
  // permuter(13, 14);
  // cout << "O : " << o << endl;
  // cout << "P : " << p << endl;

  return 0;
}