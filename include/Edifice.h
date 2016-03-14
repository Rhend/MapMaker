#ifndef EDIFICE_H
#define EDIFICE_H

#include "Architecture.h"
#include "Etage.h"
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;

class Edifice : public Architecture
{
    public:
        Edifice(const Architecture& arch, int nbAccess = 1) : Architecture(arch), nbAccess(nbAccess) {};
        Edifice(double superficie, double largeur, double longueur, string nom, int nbAccess = 1)
            : Architecture(superficie, largeur, longueur, nom), nbAccess(nbAccess) {};
        Edifice(double superficie, string nom, int nbAccess = 1) : Architecture(superficie, nom), nbAccess(nbAccess) {};
        virtual ~Edifice();
        Edifice(const Edifice& other) : Architecture(other), nbAccess(other.getNbAccess()) {};

        int getNbAccess() const { return nbAccess; }
        void setNbAccess(int val) { nbAccess = val; }

        void addEtage(Etage etage);
        void addAllEtages(vector<shared_ptr<Etage>> etagesToAdd);
        vector<shared_ptr<Etage>> getEtages() const { return etages; }
        void removeEtage(shared_ptr<Etage> etagePtr);
        void deleteAllEtages();

    protected:

    private:
        int nbAccess;
        vector<shared_ptr<Etage>> etages;
};

#endif // EDIFICE_H
