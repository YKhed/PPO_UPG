
#ifndef MELANGEALEATOIRE_H
#define MELANGEALEATOIRE_H
#include "MelangeStrategie.h"
#include <random>
#include <algorithm>

class MelangeAleatoire : public MelangeStrategie {
public:
    void melanger(std::vector<Carte>& paquet) override;
};

#endif // MELANGEALEATOIRE_H
