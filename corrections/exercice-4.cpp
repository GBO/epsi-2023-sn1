#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
  cout << "Exercice 4" << endl;

  int t[10];
  vector<int> v;

  cout << "Taille du vector : " << v.size() << endl;

  v.push_back(12);
  v.push_back(34);
  v.push_back(7);
  v.push_back(8000);

  v.insert(v.begin(), 13);
  v.insert(v.begin() + 4, 4);
  v.insert(v.end() - 2, 2);

  cout << "Taille du vector : " << v.size() << endl;

  for (int i = 0; i < v.size(); i++) {
    cout << "Element " << i << " : " << v[i] << endl;
  }

  v.erase(v.begin());
  v.erase(v.begin());


  cout << "Taille du vector : " << v.size() << endl;

  for (int i = 0; i < v.size(); i++) {
    cout << "Element " << i << " : " << v[i] << endl;
  }


  return 0;
}