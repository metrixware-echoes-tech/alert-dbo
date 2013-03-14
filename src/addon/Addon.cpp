#include "addon/Addon.h"

std::string Addon::TRIGRAM(TRIGRAM_ADDON);

Addon::Addon()
{
    this->jsonName = "addon";
    //ctor
}

Addon::~Addon()
{
    //dtor
}

std::string Addon::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->sources, "sources");
    res += Table::formatJSONForDboCollection(this->sourceParameters, "sources_parameters", false);
    
    
    res += "}\n";
    return res;
}