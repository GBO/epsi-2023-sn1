#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unistd.h>

#include "paquet.h"

#define DEFAULT_WAIT_TIME 3

#define NO_WHITESPACE 0
#define SMALL_WHITESPACE 1
#define MID_WHITESPACE 2
#define LARGE_WHITESPACE 3

#define SLEEP_TIME 1
using namespace std;


class Bataille {
public:

private:
    Paquet paquet;
    queue<Carte*> carte_a_jouer;
    queue<Carte*> main_joueur1;
    queue<Carte*> main_joueur2;

    // Methods
public:
    Bataille();
    ~Bataille();
    void jouer();

private:
    bool verifier_gagnant();
    void distrubuer_main();
    void game_loop();
    void donner_cartes(int *gagnant);
    void suspense(std::string msg, int temps_attente, int vert_whitespace);
};