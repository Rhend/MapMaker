#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <string>

using std::string;

class ConfigReader
{
    public:
        ConfigReader(string fileLocation);
        virtual ~ConfigReader();



    protected:

    private:
        string fileLocation;
};

#endif // CONFIGREADER_H
