

#include <iostream>

using namespace std;

bool EstPremier(int n) {

    for (int i = 2; i <= n/2; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Entrez un nombre : ";
    cin >> n;
    if (EstPremier(n)) {
        cout << n << " est un nombre premier." << endl;
    } else {
        cout << n << " n'est pas un nombre premier." << endl;
    }


    int nmbr;
    cout << "Entrez le nombre de nombres premiers a afficher : ";
    cin >> nmbr;
    int m = 0;
    int a = 2;
    while (m < nmbr) {
        if (EstPremier(a)) {
            cout << a << " ";
            m++;
        }
        a++;
    }

    return 0;
}
