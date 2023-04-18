
#ifndef BATAILLE_H
#define BATAILLE_H
#include "Jeu.h"
#include "Carte.h"
#include "MelangeStrategie.h"
#include <vector>
#include <random>
#include <memory>

class Bataille : public Jeu {
public:
    Bataille();
    virtual ~Bataille() = default;

    void jouer() override;

    void jouerTour();

    std::shared_ptr<Carte> getCarteJoueur() const;
    std::shared_ptr<Carte> getCarteApp() const;
    std::string getResultatTour() const;

private:
    std::vector<Carte> genererPaquet();
    void distribuerCartes(std::vector<Carte>& paquet, std::vector<Carte>& mainJoueur, std::vector<Carte>& mainApp);
    Carte tirerCarte(std::vector<Carte>& main);
    void comparerCartes(Carte carteJoueur, Carte carteApp, std::vector<Carte>& mainJoueur, std::vector<Carte>& mainApp);

    std::vector<Carte> mainJoueur;
    std::vector<Carte> mainApp;
    std::shared_ptr<Carte> carteJoueur;
    std::shared_ptr<Carte> carteApp;
    std::string resultatTour;
    std::unique_ptr<MelangeStrategie> strategieMelange;
};

#endif // BATAILLE_H
