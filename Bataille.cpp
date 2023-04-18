#include "Bataille.h"
#include "MelangeAleatoire.h"
#include <iostream>
#include <algorithm>
#include <random>

Bataille::Bataille() : Jeu("Bataille", "Un jeu de cartes classique", "Les joueurs tirent une carte chacun et le joueur avec la carte la plus haute gagne", 1, 1), strategieMelange(std::make_unique<MelangeAleatoire>()) {
    std::vector<Carte> paquet = genererPaquet();
    distribuerCartes(paquet, mainJoueur, mainApp);
}

void Bataille::jouer() {
    jouerTour();
}

void Bataille::jouerTour() {
    if (!mainJoueur.empty() && !mainApp.empty()) {
        carteJoueur = std::make_shared<Carte>(tirerCarte(mainJoueur));
        carteApp = std::make_shared<Carte>(tirerCarte(mainApp));
        comparerCartes(*carteJoueur, *carteApp, mainJoueur, mainApp);
    } else {
        resultatTour = mainJoueur.empty() ? "L'application a gagné !" : "Le joueur a gagné !";
    }
}

std::shared_ptr<Carte> Bataille::getCarteJoueur() const {
    return carteJoueur;
}

std::shared_ptr<Carte> Bataille::getCarteApp() const {
    return carteApp;
}

std::string Bataille::getResultatTour() const {
    return resultatTour;
}

std::vector<Carte> Bataille::genererPaquet() {
    std::vector<Carte> paquet;
    for (int i = 2; i <= 14; ++i) {
        for (int j = 0; j <= 3; ++j) {
            paquet.push_back(Carte(static_cast<Carte::Valeur>(i), static_cast<Carte::Couleur>(j)));
        }
    }
    strategieMelange->melanger(paquet);
    return paquet;
}

void Bataille::distribuerCartes(std::vector<Carte>& paquet, std::vector<Carte>& mainJoueur, std::vector<Carte>& mainApp) {
    for (size_t i = 0; i < paquet.size(); ++i) {
        if (i % 2 == 0) {
            mainJoueur.push_back(paquet[i]);
        } else {
            mainApp.push_back(paquet[i]);
        }
    }
}

Carte Bataille::tirerCarte(std::vector<Carte>& main) {
    Carte carte = main.back();
    main.pop_back();
    return carte;
}

void Bataille::comparerCartes(Carte carteJoueur, Carte carteApp, std::vector<Carte>& mainJoueur, std::vector<Carte>& mainApp) {
    if (carteJoueur.getValeur() > carteApp.getValeur()) {
        mainJoueur.insert(mainJoueur.begin(), carteJoueur);
        mainJoueur.insert(mainJoueur.begin(), carteApp);
        resultatTour = "Vous avez gagné ce tour.";
    } else if (carteJoueur.getValeur() < carteApp.getValeur()) {
        mainApp.insert(mainApp.begin(), carteJoueur);
        mainApp.insert(mainApp.begin(), carteApp);
        resultatTour = "L'application a gagné ce tour.";
    } else {
        resultatTour = "Égalité.";
    }
}
