#include "Quartier.h"

Quartier::~Quartier()
{
    //dtor
}

void Quartier::addEdifice(Edifice edifice)
{
    edifices.push_back(std::make_shared<Edifice>(edifice));
}

void Quartier::addAllEdifices(vector<shared_ptr<Edifice>> edificesToAdd)
{
    for (vector<shared_ptr<Edifice>>::iterator it = edificesToAdd.begin(); it != edificesToAdd.end(); )
    {
        addEdifice(**it);
        ++it;
    }
}

void Quartier::removeEdifice(shared_ptr<Edifice> edificePtr)
{
    for (vector<shared_ptr<Edifice>>::iterator it = edifices.begin(); it != edifices.end(); )
    {
        // Comparaison de pointeurs => on regarde si l'objet pointé est identique
        if (*it == edificePtr)
            it = edifices.erase(it);
        else
            ++it;
    }
}

void Quartier::deleteAllEdifices()
{
    edifices.clear();
}
