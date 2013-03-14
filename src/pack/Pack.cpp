#include "pack/Pack.h"

std::string Pack::TRIGRAM(TRIGRAM_PACK);

Pack::Pack()
{
    this->jsonName = "pack";
    //ctor
}

Pack::~Pack()
{

}

std::string Pack::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->organizations, "organizations");
    res += Table::formatJSONForDboCollection(this->packOptions, "pack_options", false);
    
    
    res += "}\n";
    return res;
}