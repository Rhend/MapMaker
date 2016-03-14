#ifndef QUARTIER_H
#define QUARTIER_H

#include "Architecture.h"
#include "Edifice.h"
#include <memory>
#include <string>
#include <vector>

using std::vector;
using std::shared_ptr;

class Quartier : public Architecture
{
    public:
        Quartier(const Architecture& arch, string environnement, int nbSorties = 1)
            : Architecture(arch), environnement(environnement), nbSorties(nbSorties) {};
        Quartier(double superficie, double largeur, double longueur, string nom, string environnement, int nbSorties = 1)
            : Architecture(superficie, largeur, longueur, nom), environnement(environnement), nbSorties(nbSorties) {};
        Quartier(double superficie, string nom, string environnement, int nbSorties = 1)
            : Architecture(superficie, nom), environnement(environnement), nbSorties(nbSorties) {};
        virtual ~Quartier();
        Quartier(const Quartier& other)
            : Architecture(other), environnement(other.getEnvironnement()), nbSorties(other.getNbSorties()) {};

        int getNbSorties() const { return nbSorties; }
        void setNbSorties(int val) { nbSorties = val; }
        string getEnvironnement() const { return environnement; }
        void setEnvironnement(string val) { environnement = val; }
        vector<shared_ptr<Edifice>> getEdifices() const { return edifices; }

        void addEdifice(Edifice edifice);
        void addAllEdifices(vector<shared_ptr<Edifice>> edificesToAdd);
        void removeEdifice(shared_ptr<Edifice> edificePtr);
        void deleteAllEdifices();

    protected:

    private:
        string environnement;
        int nbSorties;
        vector<shared_ptr<Edifice>> edifices;
};

#endif // QUARTIER_H
