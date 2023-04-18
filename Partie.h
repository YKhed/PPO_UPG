
#ifndef PARTIE_H
#define PARTIE_H
#include <string>
#include <QString>
#include "Jeu.h"

class Partie {
public:
    // Partie(const std::string& nomPartie, Jeu* jeu);
    Partie(const std::string& nomPartie, std::unique_ptr<Jeu> jeu)
        : nomPartie(nomPartie), jeu(std::move(jeu)) {}
    ~Partie();

    const std::string& getNomPartie() const;
    Jeu* getJeu() const;

private:
    std::string nomPartie;
    std::unique_ptr<Jeu> jeu;
};

#endif // PARTIE_H
