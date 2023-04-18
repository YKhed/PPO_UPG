#include "Soiree.h"

Soiree::Soiree(const std::string& nom, const std::string& codeSoiree)
    : nom(nom), codeSoiree(codeSoiree) {}

const std::string& Soiree::getNom() const {
    return nom;
}

const std::string& Soiree::getCodeSoiree() const {
    return codeSoiree;
}

void Soiree::ajouterPartie(std::shared_ptr<Partie> partie) {
    parties.push_back(partie);
}

const std::vector<std::shared_ptr<Partie>>& Soiree::getParties() const {
    return parties;
}
