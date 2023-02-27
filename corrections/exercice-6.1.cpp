#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(int argc, char **argv)
{
  cout << "Exercice 6.1" << endl;

  int* p1 = new int;
  *p1 = 12;

  int** p2 = new int*;
  *p2 = p1;

  cout << "p1 : " << p1 << endl;
  cout << "*p1 : " << *p1 << endl;
  cout << "p2 : " << p2 << endl;
  cout << "*p2 : " << *p2 << endl;
  cout << "**p2 : " << **p2 << endl;

  cout << "MODIFICATION !" << endl;
  *p1 = 24;

  cout << "p1 : " << p1 << endl;
  cout << "*p1 : " << *p1 << endl;
  cout << "p2 : " << p2 << endl;
  cout << "*p2 : " << *p2 << endl;
  cout << "**p2 : " << **p2 << endl;

  delete p1;
  delete p2;

  p1 = (int*) 24;
  delete p1;
  
  return 0;
}