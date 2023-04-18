#include "Partie.h"

Partie::~Partie() {}

const std::string& Partie::getNomPartie() const {
    return nomPartie;
}

Jeu* Partie::getJeu() const {
    return jeu.get();
}
