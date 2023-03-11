

#include <iostream>

using namespace std;

int main()
{

int J;
int O;

J = rand() %6 + 1;
O = rand() %6 + 1;

cout << "Le joueur a tire un " << J << endl;
cout << "L'ordinateur a tire un " << O << endl;

if (J > O){
cout << "Le joueur a gagne";
}
if (O > J){
cout << "L'ordinateur a gagne";
}
if (J == O) {
cout << "Il y a egalite";
}


    return 0;
}