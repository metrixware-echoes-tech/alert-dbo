#include "organization/Organization.h"

std::string Organization::TRIGRAM(TRIGRAM_ORGANIZATION);

Organization::Organization()
{
    this->jsonName = "user";
    //ctor
}

Organization::~Organization()
{
}

std::string Organization::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->pack);
    res += Table::formatJSONForDboPtr(this->organizationType);
    
    res += Table::formatJSONForDboCollection(this->users, "user");
    res += Table::formatJSONForDboCollection(this->probes, "probes");
    res += Table::formatJSONForDboCollection(this->assets, "assets", false);
    
    res += "}";
    return res;
}