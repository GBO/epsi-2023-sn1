#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// On peut surcharger les fonctions :
// définir plusieurs versions d'une même fonction en changeant les paramètres
void permuter(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}
void permuter(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int main(int argc, char **argv)
{
  cout << "Exercice 6.3" << endl;

  int m = 12;
  int n = 24;
  int* mp = new int(12);
  int* np = new int(24);

  cout << "REFERENCES" << endl;
  cout << "Valeurs m / n : " << m << " / " << n << endl;
  permuter(m, n);
  cout << "Valeurs m / n : " << m << " / " << n << endl;

  cout << "REFERENCES / POINTEURS" << endl;
  cout << "Valeurs m / n : " << *mp << " / " << *np << endl;
  permuter(*mp, *np);
  cout << "Valeurs m / n : " << *mp << " / " << *np << endl;

  cout << "POINTEURS" << endl;
  cout << "Valeurs m / n : " << *mp << " / " << *np << endl;
  permuter(mp, np);
  cout << "Valeurs m / n : " << *mp << " / " << *np << endl;

  cout << "POINTEURS / REFERENCES" << endl;
  cout << "Valeurs m / n : " << m << " / " << n << endl;
  permuter(&m, &n);
  cout << "Valeurs m / n : " << m << " / " << n << endl;

  delete mp;
  delete np;

  return 0;
}