#include "Architecture.h"

Architecture::~Architecture()
{
    //dtor
}

Architecture::Architecture(const Architecture& other)
{
    setSuperficie(other.getSuperficie());
    setLargeur(other.getLargeur());
    setLongueur(other.getLongueur());
    setNom(other.getNom());
}
