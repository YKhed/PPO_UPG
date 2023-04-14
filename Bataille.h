
#ifndef BATAILLE_H
#define BATAILLE_H

#include "Jeu.h"
#include "Carte.h"
#include <vector>
#include <random>

class Bataille : public Jeu {
public:
    Bataille();
    virtual ~Bataille() = default;

    void jouer() override;

private:
    std::vector<Carte> genererPaquet();
    void distribuerCartes(std::vector<Carte>& paquet, std::vector<Carte>& mainJoueur, std::vector<Carte>& mainApp);
    Carte tirerCarte(std::vector<Carte>& main);
    void comparerCartes(Carte carteJoueur, Carte carteApp, std::vector<Carte>& mainJoueur, std::vector<Carte>& mainApp);
};

#endif // BATAILLE_H
