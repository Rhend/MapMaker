#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <string>

using std::string;

class Architecture
{
    public:
        Architecture(double superficie, string nom) : superficie(superficie), nom(nom) {};
        Architecture(double superficie, double largeur, double longueur, string nom)
            : superficie(superficie), largeur(largeur), longueur(longueur), nom(nom) {};
        virtual ~Architecture();
        Architecture(const Architecture& other);

        double getSuperficie() const { return superficie; }
        void setSuperficie(double val) { superficie = val; }
        double getLargeur() const { return largeur; }
        void setLargeur(double val) { largeur = val; }
        double getLongueur() const { return longueur; }
        void setLongueur(double val) { longueur = val; }
        string getNom() const { return nom; }
        void setNom(string val) { nom = val; }

    protected:

    private:
        double superficie;
        double largeur;
        double longueur;
        string nom;
};

#endif // ARCHITECTURE_H
