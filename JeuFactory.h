
#ifndef JEUFACTORY_H
#define JEUFACTORY_H
#include <memory>
#include <stdexcept>
#include "Jeu.h"
#include "Bataille.h"


class JeuFactory {
public:
    enum TypeJeu { BATAILLE };

    static std::unique_ptr<Jeu> creerJeu(TypeJeu type) {
        switch (type) {
        case BATAILLE:
            return std::unique_ptr<Jeu>(new Bataille());
        default:
            throw std::runtime_error("Type de jeu non pris en charge");
        }
    }
};
#endif // JEUFACTORY_H
