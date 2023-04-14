#include <algorithm>
#include <random>
#include "Deck.h"

Deck::Deck() {
    for (int i = Carte::Deux; i <= Carte::As; ++i) {
        for (int j = Carte::Coeur; j <= Carte::Pique; ++j) {
            cartes.push_back(Carte(static_cast<Carte::Valeur>(i), static_cast<Carte::Couleur>(j)));
        }
    }
}

void Deck::melanger() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cartes.begin(), cartes.end(), g);
}

Carte Deck::piocher() {
    Carte carte = cartes.back();
    cartes.pop_back();
    return carte;
}
