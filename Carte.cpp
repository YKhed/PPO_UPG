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

QString Carte::getNomFichierImage() {


    QString couleurStr;
    QString valeurStr;

    switch (getCouleur()) {
    case Couleur::Coeur:
        couleurStr = "h";
        break;
    case Couleur::Carreau:
        couleurStr = "d";
        break;
    case Couleur::Trefle:
        couleurStr = "c";
        break;
    case Couleur::Pique:
        couleurStr = "s";
        break;
    }

    switch (getValeur()) {
    case Valeur::Deux:
        valeurStr = "02";
        break;
    case Valeur::Trois:
        valeurStr = "03";
        break;
    case Valeur::Quatre:
        valeurStr = "04";
        break;
    case Valeur::Cinq:
        valeurStr = "05";
        break;
    case Valeur::Six:
        valeurStr = "06";
        break;
    case Valeur::Sept:
        valeurStr = "07";
        break;
    case Valeur::Huit:
        valeurStr = "08";
        break;
    case Valeur::Neuf:
        valeurStr = "09";
        break;
    case Valeur::Dix:
        valeurStr = "10";
        break;
    case Valeur::Valet:
        valeurStr = "11";
        break;
    case Valeur::Dame:
        valeurStr = "12";
        break;
    case Valeur::Roi:
        valeurStr = "13";
        break;
    case Valeur::As:
        valeurStr = "01";
        break;
    }

    return ":/cartes/C:/Users/Admin/Desktop/cartes/" + couleurStr + valeurStr + ".png";
}
