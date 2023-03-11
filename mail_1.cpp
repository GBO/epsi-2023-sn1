// Exercice 1

#include <iostream>
using namespace std;

bool est_premier(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Entrez le nombre de nombres premiers à afficher : ";
    cin >> n;
    int i = 2;
    while (n > 0) {
        if (est_premier(i)) {
            cout << i << " ";
            n--;
        }
        i++;
    }
    cout << endl;
    return 0;
}
