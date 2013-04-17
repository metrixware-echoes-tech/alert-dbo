#include "pack/Option.h"

std::string Option::TRIGRAM(TRIGRAM_OPTION);

Option::Option()
{
    this->jsonName = "option";
    //ctor
}

Option::~Option()
{
}

std::string Option::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->packOptions, "pack_option", false);
        
    res += "}";
    return res;
}