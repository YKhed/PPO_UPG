#include "Carte.h"
#include <iostream>
#include <sstream>


Carte::Carte(int valeur, int couleur)
    : Carte(static_cast<Valeur>(valeur), static_cast<Couleur>(couleur)) {
}

Carte::Carte(Valeur valeur, Couleur couleur)
    : couleur(couleur), valeur(valeur) {
}

Carte::Couleur Carte::getCouleur() const {
    return couleur;
}

Carte::Valeur Carte::getValeur() const {
    return valeur;
}

std::string Carte::toString() const {
    std::ostringstream oss;

    switch (valeur) {
    case Deux:   oss << "2"; break;
    case Trois:  oss << "3"; break;
    case Quatre: oss << "4"; break;
    case Cinq:   oss << "5"; break;
    case Six:    oss << "6"; break;
    case Sept:   oss << "7"; break;
    case Huit:   oss << "8"; break;
    case Neuf:   oss << "9"; break;
    case Dix:    oss << "10"; break;
    case Valet:  oss << "Valet"; break;
    case Dame:   oss << "Dame"; break;
    case Roi:    oss << "Roi"; break;
    case As:     oss << "As"; break;
    }

    oss << " de ";

    switch (couleur) {
    case Coeur:  oss << "Coeur"; break;
    case Carreau: oss << "Carreau"; break;
    case Trefle: oss << "Trèfle"; break;
        case Pique:  oss << "Pique"; break;
    }

    return oss.str();
}
