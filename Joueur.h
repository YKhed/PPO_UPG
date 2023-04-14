
#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "Carte.h"

class Joueur {
public:
    void ajouterCarte(const Carte& carte);
    Carte jouerCarte();
    Carte jouerCarteAleatoire(); // Nouvelle méthode pour jouer une carte aléatoire

private:
    std::vector<Carte> m_main;
};

#endif // JOUEUR_H
