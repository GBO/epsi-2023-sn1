#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Humain {
public:
    Humain(string nom) : m_nom(nom) {}
    string getNom() const { return m_nom; }
private:
    string m_nom;
};

class Zombie {
public:
    Zombie(string nom) : m_nom(nom) {}
    string getNom() const { return m_nom; }
    void mangerHumain() {
        if (!m_humains.empty()) {
            int index = rand() % m_humains.size();
            cout << m_nom << " mange " << m_humains[index]->getNom() << endl;
            m_humains.erase(m_humains.begin() + index);
        }
    }
    void ajouterHumain(Humain* humain) {
        m_humains.push_back(humain);
    }
    void debutDeLaFin() {
        if (!m_humains.empty()) {
            int index = rand() % m_humains.size();
            Humain* humain = m_humains[index];
            m_humains.erase(m_humains.begin() + index);
            cout << humain->getNom() << " devient " << m_nom << endl;
        }
    }
private:
    string m_nom;
    vector<Humain*> m_humains;
};

class FinDuMonde {
public:
    FinDuMonde() {
        srand(time(NULL));
    }
    void ajouterHumain(Humain* humain) {
        m_humains.push_back(humain);
    }
    void debutDeLaFin() {
        if (!m_humains.empty()) {
            int index = rand() % m_humains.size();
            Humain* humain = m_humains[index];
            m_humains.erase(m_humains.begin() + index);
            m_zombies.push_back(new Zombie(humain->getNom()));
            cout << humain->getNom() << " devient " << m_zombies.back()->getNom() << endl;
        }
    }
    void fin() {
        int tour = 1;
        while (!m_humains.empty()) {
            cout << "Tour " << tour++ << endl;
            for (auto zombie : m_zombies) {
                zombie->mangerHumain();
            }
        }
        cout << "Fin du monde en " << tour - 1 << " tours" << endl;
    }
private:
    vector<Humain*> m_humains;
    vector<Zombie*> m_zombies;
};

int main() {
    string prenoms[] = { "Emma", "Liam", "Olivia", "Noah", "Ava", "Ethan", "Isabella", "Lucas", "Mia", "Mason" };
    FinDuMonde finDuMonde;
    for (int i = 0; i < 10; i++) {
        finDuMonde.ajouterHumain(new Humain(prenoms[i]));
    }
    finDuMonde.debutDeLaFin();
    finDuMonde.fin();
    return 0;
}
