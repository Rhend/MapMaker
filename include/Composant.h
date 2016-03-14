#ifndef COMPOSANT_H
#define COMPOSANT_H

#include <string>

using std::string;

class Composant
{
    public:
        Composant(double largeur, double longueur, string nom, string placement)
            : largeur(largeur), longueur(longueur), nom(nom), placement(placement) {};
        virtual ~Composant();
        Composant(const Composant& other);

        double getLongueur() const { return longueur; }
        void setLongueur(double val) { longueur = val; }
        double getLargeur() const { return largeur; }
        void setLargeur(double val) { largeur = val; }
        string getNom() const { return nom; }
        void setNom(string val) { nom = val; }
        string getPlacement() const { return placement; }
        void setPlacement(string val) { placement = val; }

        bool operator==(const Composant& other) const;
        bool operator!=(const Composant& other) const;

    protected:

    private:
        double largeur;
        double longueur;
        string nom;
        string placement;
};

#endif // COMPOSANT_H
