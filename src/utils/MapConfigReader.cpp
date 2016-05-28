#include "MapConfigReader.h"
#include "xmlParsing/pugixml.hpp"

MapConfigReader::MapConfigReader(string fileLocation)
{
    pugi::xml_parse_result result = this->doc.load_file(fileLocation.c_str());
}

MapConfigReader::~MapConfigReader()
{
    //dtor
}

vector<shared_ptr<Edifice>> MapConfigReader::getEdificesFromConfig() const
{
    vector<shared_ptr<Edifice>> edifices;
    pugi::xml_node edificesNodes = this->doc.child("Edifices");

    return edifices;
}
