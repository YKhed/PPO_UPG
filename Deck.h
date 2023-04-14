
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Carte.h"

class Deck {
public:
    Deck();
    void melanger();
    Carte piocher();

private:
    std::vector<Carte> cartes;
};

#endif // DECK_H
