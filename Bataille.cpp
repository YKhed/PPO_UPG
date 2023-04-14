#include "Bataille.h"
#include <iostream>
#include <algorithm>
#include <random>

Bataille::Bataille() : Jeu("Bataille", "Un jeu de cartes classique", "Les joueurs tirent une carte chacun et le joueur avec la carte la plus haute gagne", 1, 1) {
}

void Bataille::jouer() {
    std::vector<Carte> paquet = genererPaquet();
    std::vector<Carte> mainJoueur;
    std::vector<Carte> mainApp;

    distribuerCartes(paquet, mainJoueur, mainApp);

    while (!mainJoueur.empty() && !mainApp.empty()) {
        Carte carteJoueur = tirerCarte(mainJoueur);
        Carte carteApp = tirerCarte(mainApp);

        std::cout << "Le joueur a tiré la carte : " << carteJoueur.toString() << std::endl;
                std::cout << "L'application a tiré la carte : " << carteApp.toString() << std::endl;

                             comparerCartes(carteJoueur, carteApp, mainJoueur, mainApp);
    }

    if (mainJoueur.empty()) {
        std::cout << "L'application a gagné !" << std::endl;
    } else {
        std::cout << "Le joueur a gagné !" << std::endl;
    }
}

std::vector<Carte> Bataille::genererPaquet() {
    std::vector<Carte> paquet;
    for (int couleur = Carte::Coeur; couleur <= Carte::Pique; ++couleur) {
        for (int valeur = Carte::Deux; valeur <= Carte::As; ++valeur) {
            paquet.push_back(Carte(static_cast<Carte::Couleur>(couleur), static_cast<Carte::Valeur>(valeur)));
        }
    }
    std::shuffle(paquet.begin(), paquet.end(), std::mt19937(std::random_device()()));
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
    Carte carte = main.front();
    main.erase(main.begin());
    return carte;
}

void Bataille::comparerCartes(Carte carteJoueur, Carte carteApp, std::vector<Carte>& mainJoueur, std::vector<Carte>& mainApp) {
    if (carteJoueur.getValeur() > carteApp.getValeur()) {
        std::cout << "Le joueur gagne cette manche !" << std::endl;
        mainJoueur.push_back(carteJoueur);
        mainJoueur.push_back(carteApp);
    } else if (carteJoueur.getValeur() < carteApp.getValeur()) {
        std::cout << "L'application gagne cette manche !" << std::endl;
        mainApp.push_back(carteJoueur);
        mainApp.push_back(carteApp);
    } else {
        std::cout << "Égalité !" << std::endl;
    }
}
