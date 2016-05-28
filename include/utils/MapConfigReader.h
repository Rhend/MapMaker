#ifndef MAPCONFIGREADER_H
#define MAPCONFIGREADER_H

#include "Edifice.h"
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

        vector<shared_ptr<Edifice>> getEdificesFromConfig() const;

    protected:

    private:
        pugi::xml_document doc;
};

#endif // MAPCONFIGREADER_H
