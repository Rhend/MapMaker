#include "MapConfigReader.h"
#include "xmlParsing/pugixml.hpp"

MapConfigReader::MapConfigReader(string fileLocation)
{
    this->doc.load_file(fileLocation.c_str());
}

MapConfigReader::~MapConfigReader()
{
    //dtor
}

pugi::xml_node MapConfigReader::getRootNode() const
{
    return this->doc.child("MapRoot");
}

pugi::xml_node MapConfigReader::getQuartiersNode() const
{
    return getRootNode().child("Quartiers");
}

vector<shared_ptr<Quartier>> MapConfigReader::getQuartiersFromConfig() const
{
    vector<shared_ptr<Quartier>> quartiers;
    pugi::xml_node quartiersNodes = getQuartiersNode();

    for (pugi::xml_node quartierNode = quartiersNodes.first_child(); quartierNode; quartierNode = quartierNode.next_sibling())
    {
        Architecture archi = getArchitectureFromNode(quartierNode);
        vector<shared_ptr<Edifice>> edifices = getEdificesFromQuartier(quartierNode);
        string environnement = quartierNode.attribute("environnement").as_string();
        Quartier quartier(archi, environnement);
        quartier.addAllEdifices(edifices);
        quartiers.push_back(std::make_shared<Quartier>(quartier));
    }

    return quartiers;
}

vector<shared_ptr<Edifice>> MapConfigReader::getEdificesFromQuartier(pugi::xml_node quartierNode) const
{
    vector<shared_ptr<Edifice>> edifices;

    pugi::xml_node edificesNodes = quartierNode.child("Edifices");

    for (pugi::xml_node edificeNode = edificesNodes.first_child(); edificeNode; edificeNode = edificeNode.next_sibling())
    {
        Architecture archi = getArchitectureFromNode(edificeNode);
        vector<shared_ptr<Etage>> etages = getEtagesFromEdifice(edificeNode);
        Edifice edifice(archi);
        edifice.addAllEtages(etages);
        edifices.push_back(std::make_shared<Edifice>(edifice));
    }

    return edifices;
}

vector<shared_ptr<Etage>> MapConfigReader::getEtagesFromEdifice(pugi::xml_node edificeNode) const
{
    vector<shared_ptr<Etage>> etages;

    pugi::xml_node etagesNodes = edificeNode.child("Etages");

    for (pugi::xml_node etageNode = etagesNodes.first_child(); etageNode; etageNode = etageNode.next_sibling())
    {
        int nbAccessEtageSup = etageNode.attribute("nbAccessEtageSup").as_int();
        Architecture archi = getArchitectureFromNode(etageNode);
        vector<shared_ptr<Piece>> pieces = getPiecesFromEtage(etageNode);
        Etage etage(archi, nbAccessEtageSup);
        etage.addAllPieces(pieces);
        etages.push_back(std::make_shared<Etage>(etage));
    }

    return etages;
}

vector<shared_ptr<Piece>> MapConfigReader::getPiecesFromEtage(pugi::xml_node etageNode) const
{
    vector<shared_ptr<Piece>> pieces;

    pugi::xml_node piecesNodes = etageNode.child("Pieces");

    for (pugi::xml_node pieceNode = piecesNodes.first_child(); pieceNode; pieceNode = pieceNode.next_sibling())
    {
        int nbAccessEtageSup = pieceNode.attribute("nbAccessEtageSup").as_int();
        Architecture archi = getArchitectureFromNode(pieceNode);
        Piece piece(archi, nbAccessEtageSup);
        pieces.push_back(std::make_shared<Piece>(piece));
    }

    return pieces;
}

Architecture MapConfigReader::getArchitectureFromNode(pugi::xml_node node) const
{
    string name;
    double superficie;
    double longueur;
    double largeur;

    superficie = node.attribute("superficie").as_double();
    longueur = node.attribute("longueur").as_double();
    largeur = node.attribute("largeur").as_double();
    name = node.attribute("nom").as_string();

    return Architecture(superficie, largeur, longueur, name);
}
