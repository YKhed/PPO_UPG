
#ifndef JEUEXTERNEADAPTATEUR_H
#define JEUEXTERNEADAPTATEUR_H
#include "Jeu.h"
#include "JeuExterne.h"

class JeuExterneAdaptateur : public Jeu {
private:
    JeuExterne jeuExterneA;

public:
    void jouer() override {
        jeuExterneA.demarrerJeu();
    }
};
#endif // JEUEXTERNEADAPTATEUR_H
