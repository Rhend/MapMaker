#include "Composant.h"

Composant::~Composant()
{
    //dtor
}

Composant::Composant(const Composant& other)
{
    setLargeur(other.getLargeur());
    setLongueur(other.getLongueur());
    setNom(other.getNom());
    setPlacement(other.getPlacement());
}

bool Composant::operator==(const Composant& other) const
{
    return largeur == other.getLargeur() &&
            longueur == other.getLongueur() &&
            nom == other.getNom() &&
            placement == other.getPlacement();
}

bool Composant::operator!=(const Composant& other) const
{
    return !(*this == other);
}

