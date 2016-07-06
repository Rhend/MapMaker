#ifndef ETAGE_H
#define ETAGE_H

#include "Architecture.h"
#include "Piece.h"
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;

class Etage : public Architecture
{
    public:
        Etage(const Architecture& archi, int nbAccessEtageSup = 1)
            : Architecture(archi), nbAccessEtageSup(nbAccessEtageSup) {};
        Etage(double superficie, double largeur, double longueur, string nom, int nbAccessEtageSup = 1)
            : Architecture(superficie, largeur, longueur, nom), nbAccessEtageSup(nbAccessEtageSup) {};
        Etage(double superficie, string nom, int nbAccessEtageSup = 1)
            : Architecture(superficie, nom), nbAccessEtageSup(nbAccessEtageSup) {};
        virtual ~Etage();
        Etage(const Etage& other) : Architecture(other), nbAccessEtageSup(other.getNbAccessEtageSup()) { addAllPieces(other.getPieces()); };

        int getNbAccessEtageSup() const { return nbAccessEtageSup; }
        void setNbAccessEtageSup(int val) { nbAccessEtageSup = val; }

        void addPiece(Piece piece);
        void addAllPieces(vector<shared_ptr<Piece>> piecesToAdd);
        vector<shared_ptr<Piece>> getPieces() const { return pieces; }
        void removePiece(shared_ptr<Piece> piecePtr);
        void deleteAllPieces();

    protected:

    private:
        int nbAccessEtageSup;
        vector<shared_ptr<Piece>> pieces;
};

#endif // ETAGE_H
