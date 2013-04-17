#include "unit/InformationUnit.h"

std::string InformationUnit::TRIGRAM(TRIGRAM_INFORMATION_UNIT);

InformationUnit::InformationUnit()
{
    this->jsonName = "information_unit";
    //ctor
}

InformationUnit::~InformationUnit()
{
 
}

std::string InformationUnit::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->unitType);
    
    res += Table::formatJSONForDboCollection(this->searchUnits, "search_units");
    res += Table::formatJSONForDboCollection(this->informationSubUnits, "information_sub_units", false);
   
    res += "}";
    return res;
}