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

void Architecture::toString()
{
    std::cout<<"Architecture : "<<getNom()<<std::endl;
    std::cout<<"Superficie : "<<getSuperficie()<<std::endl;
    std::cout<<"Longueur : "<<getLongueur()<<std::endl;
    std::cout<<"Largeur : "<<getLargeur()<<std::endl;
}
