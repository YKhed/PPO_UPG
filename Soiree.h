
#ifndef SOIREE_H
#define SOIREE_H
#include <string>
#include <QString>
#include <vector>
#include "Partie.h"

class Soiree {
public:
    Soiree(const std::string& nom, const std::string& codeSoiree);
    Soiree(const QString &nomSoiree, const QString &codeSoiree) {}
    const std::string& getNom() const;
    const std::string& getCodeSoiree() const;
    void ajouterPartie(std::shared_ptr<Partie> partie);
    const std::vector<std::shared_ptr<Partie>>& getParties() const;

private:
    std::string nom;
    std::string codeSoiree;
    std::vector<std::shared_ptr<Partie>> parties;
};

#endif // SOIREE_H
