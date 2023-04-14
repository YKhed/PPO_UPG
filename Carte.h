
#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte {
public:
    enum Couleur { Coeur, Carreau, Trefle, Pique };
    enum Valeur { Deux = 2, Trois, Quatre, Cinq, Six, Sept, Huit, Neuf, Dix, Valet, Dame, Roi, As };

    Carte(int valeur, int couleur);
    Carte(Valeur valeur, Couleur couleur);
    Couleur getCouleur() const;
    Valeur getValeur() const;
    std::string toString() const;

private:
    Couleur couleur;
    Valeur valeur;
};
#endif // CARTE_H
