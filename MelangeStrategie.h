
#ifndef MELANGESTRATEGIE_H
#define MELANGESTRATEGIE_H
#include <vector>
#include "Carte.h"

class MelangeStrategie {
public:
    virtual ~MelangeStrategie() = default;
    virtual void melanger(std::vector<Carte>& paquet) = 0;
};
#endif // MELANGESTRATEGIE_H
