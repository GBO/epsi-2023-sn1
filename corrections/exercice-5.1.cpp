#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


double calculer_distance(int x1, int y1, int x2, int y2) {
  x1 = 1;
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(int argc, char **argv)
{
  cout << "Exercice 5.1" << endl;

  int x1 = 0;
  int y1 = 0;

  cout << "Distance : " << calculer_distance(x1, y1, 0, 1) << endl;
  cout << "Distance : " << calculer_distance(x1, y1, 1, 1) << endl;
  cout << "Distance : " << calculer_distance(x1, y1, 3, 4) << endl;

  cout << x1;


  return 0;
}