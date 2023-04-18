
#ifndef JEU_H
#define JEU_H
#include <string>
#include <vector>


class Jeu {
public:
    Jeu(const std::string& nomJeu, const std::string& description, const std::string& reglesJeu, int nbJoueursMin, int nbJoueursMax);
    virtual ~Jeu() = default;

    virtual void jouer() = 0;

    std::string getNomJeu() const;
    std::string getDescription() const;
    std::string getReglesJeu() const;
    int getNbJoueursMin() const;
    int getNbJoueursMax() const;



private:
    std::string nomJeu;
    std::string description;
    std::string reglesJeu;
    int nbJoueursMin;
    int nbJoueursMax;
};

#endif // JEU_H


