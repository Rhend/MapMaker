#include "Etage.h"

Etage::~Etage()
{
    //dtor
}

void Etage::addPiece(Piece piece)
{
    pieces.push_back(std::make_shared<Piece>(piece));
}

void Etage::addAllPieces(vector<shared_ptr<Piece>> piecesToAdd)
{
    for (vector<shared_ptr<Piece>>::iterator it = piecesToAdd.begin(); it != piecesToAdd.end(); )
    {
        addPiece(**it);
        ++it;
    }
}

void Etage::removePiece(shared_ptr<Piece> piecePtr)
{
    for (vector<shared_ptr<Piece>>::iterator it = pieces.begin(); it != pieces.end(); )
    {
        // Comparaison de pointeurs => on regarde si l'objet pointé est identique
        if (*it == piecePtr)
            it = pieces.erase(it);
        else
            ++it;
    }
}

void Etage::deleteAllPieces()
{
    pieces.clear();
}
