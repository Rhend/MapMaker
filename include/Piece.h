#ifndef PIECE_H
#define PIECE_H

#include "Architecture.h"
#include "Composant.h"
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::shared_ptr;

class Piece : public Architecture
{
    public:
        Piece(const Architecture& archi, int nbAccess = 1)
            : Architecture(archi), nbAccess(nbAccess) {};
        Piece(double superficie, double largeur, double longueur, string nom, int nbAccess = 1)
            : Architecture(superficie, largeur, longueur, nom), nbAccess(nbAccess) {};
        Piece(double superficie, string nom, int nbAccess = 1)
            : Architecture(superficie, nom), nbAccess(nbAccess) {};
        virtual ~Piece();
        Piece(const Piece& other) : Architecture(other), nbAccess(other.getNbAccess()) { addAllComposants(other.getComposants()); };

        int getNbAccess() const { return nbAccess; }
        void setNbAccess(int val) { nbAccess = val; }

        void addComposant(Composant composant);
        void addAllComposants(vector<shared_ptr<Composant>> composantsToAdd);
        vector<shared_ptr<Composant>> getComposants() const { return composants; }
        void removeComposant(shared_ptr<Composant> composantPtr);
        void deleteAllComposants();

    protected:

    private:
        int nbAccess;
        vector<shared_ptr<Composant>> composants;
};

#endif // PIECE_H
