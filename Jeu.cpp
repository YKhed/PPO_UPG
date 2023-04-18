#include "Jeu.h"
#include <algorithm>

Jeu::Jeu(const std::string& nomJeu, const std::string& description, const std::string& reglesJeu, int nbJoueursMin, int nbJoueursMax)
    : nomJeu(nomJeu), description(description), reglesJeu(reglesJeu), nbJoueursMin(nbJoueursMin), nbJoueursMax(nbJoueursMax) {
}

std::string Jeu::getNomJeu() const {
    return nomJeu;
}

std::string Jeu::getDescription() const {
    return description;
}

std::string Jeu::getReglesJeu() const {
    return reglesJeu;
}

int Jeu::getNbJoueursMin() const {
    return nbJoueursMin;
}

int Jeu::getNbJoueursMax() const {
    return nbJoueursMax;
}


