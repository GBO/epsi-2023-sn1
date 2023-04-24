#pragma once

#include <algorithm> // melanger
#include <chrono>    // chrono::system_clock
#include <iostream>  // count
#include <random>    // default_random_engine
#include <stack>
#include <vector>

#include "carte.h"

#define NUM_SUITS 4
#define NUM_CARDS 52
#define CARD_ENUM_START 2
#define CARD_ENUM_END 15

using namespace std;

class Paquet {
public:

private:
    vector<Carte*> cartes;
    stack<Carte*> paquet;

    // Methods
public:
    Paquet();
    ~Paquet();
    bool est_vide();
    void melanger();
    Carte* egalite(); // Change to return a Card* to the top of the card drawn deck
    void print();

private:
    void reset_paquet();
};