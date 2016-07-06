#ifndef MAPCONFIGREADER_H
#define MAPCONFIGREADER_H

#include "Architecture.h"
#include "Edifice.h"
#include "Etage.h"
#include "Piece.h"
#include "Quartier.h"
#include "xmlParsing/pugixml.hpp"
#include <memory>
#include <string>
#include <vector>
#include <string>
using std::vector;
using std::shared_ptr;
using std::string;

class MapConfigReader
{
    public:
        MapConfigReader(string fileLocation);
        virtual ~MapConfigReader();

        vector<shared_ptr<Quartier>> getQuartiersFromConfig() const;

    protected:

    private:
        vector<shared_ptr<Edifice>> getEdificesFromQuartier(pugi::xml_node quartierNode) const;
        vector<shared_ptr<Etage>> getEtagesFromEdifice(pugi::xml_node edificeNode) const;
        vector<shared_ptr<Piece>> getPiecesFromEtage(pugi::xml_node etageNode) const;
        Architecture getArchitectureFromNode(pugi::xml_node node) const;
        pugi::xml_node getRootNode() const;
        pugi::xml_node getQuartiersNode() const;
        string fileLocation;
        pugi::xml_document doc;
};

#endif // MAPCONFIGREADER_H
