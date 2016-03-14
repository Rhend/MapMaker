#include "Edifice.h"

Edifice::~Edifice()
{
    //dtor
}

void Edifice::addEtage(Etage etage)
{
    etages.push_back(std::make_shared<Etage>(etage));
}

void Edifice::addAllEtages(vector<shared_ptr<Etage>> etagesToAdd)
{
    for (vector<shared_ptr<Etage>>::iterator it = etagesToAdd.begin(); it != etagesToAdd.end(); )
    {
        addEtage(**it);
        ++it;
    }
}

void Edifice::removeEtage(shared_ptr<Etage> etagePtr)
{
    for (vector<shared_ptr<Etage>>::iterator it = etages.begin(); it != etages.end(); )
    {
        // Comparaison de pointeurs => on regarde si l'objet pointé est identique
        if (*it == etagePtr)
            it = etages.erase(it);
        else
            ++it;
    }
}

void Edifice::deleteAllEtages()
{
    etages.clear();
}

