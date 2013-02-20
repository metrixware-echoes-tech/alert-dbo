#include "unit/InformationUnitType.h"

std::string InformationUnitType::TRIGRAM(TRIGRAM_INFORMATION_UNIT_TYPE);

InformationUnitType::InformationUnitType()
{
    this->jsonName = "information_unit_type";
    //ctor
}

InformationUnitType::~InformationUnitType()
{

}

std::string InformationUnitType::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    
    res += Table::formatJSONForDboCollection(this->alertCriterias, "alerts_criterias");
    res += Table::formatJSONForDboCollection(this->units, "units", false);
    
    res += "}\n";
    return res;
}
