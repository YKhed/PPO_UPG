#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Joueur.h"

void Joueur::ajouterCarte(const Carte& carte) {
    m_main.push_back(carte);
}

Carte Joueur::jouerCarte() {
    Carte carte = m_main.back();
    m_main.pop_back();
    return carte;
}

Carte Joueur::jouerCarteAleatoire() {
    std::srand(static_cast<unsigned>(std::time(0)));
    int index = std::rand() % m_main.size();
    Carte carte = m_main[index];
    m_main.erase(m_main.begin() + index);
    return carte;
}
