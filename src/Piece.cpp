#include "Piece.h"

Piece::~Piece()
{
    //dtor
}

void Piece::addComposant(Composant composant)
{
    composants.push_back(std::make_shared<Composant>(composant));
}

void Piece::addAllComposants(vector<shared_ptr<Composant>> composantsToAdd)
{
    for (vector<shared_ptr<Composant>>::iterator it = composantsToAdd.begin(); it != composantsToAdd.end(); )
    {
        addComposant(**it);
        ++it;
    }
}

void Piece::removeComposant(shared_ptr<Composant> composantPtr)
{
    for (vector<shared_ptr<Composant>>::iterator it = composants.begin(); it != composants.end(); )
    {
        // Comparaison de pointeurs => on regarde si l'objet pointé est identique
        if (*it == composantPtr)
            it = composants.erase(it);
        else
            ++it;
    }
}

void Piece::deleteAllComposants()
{
    composants.clear();
}

