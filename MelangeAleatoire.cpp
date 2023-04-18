#include "MelangeAleatoire.h"

void MelangeAleatoire::melanger(std::vector<Carte>& paquet) {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(paquet.begin(), paquet.end(), g);
}
