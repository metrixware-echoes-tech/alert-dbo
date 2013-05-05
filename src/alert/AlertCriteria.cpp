#include "alert/AlertCriteria.h"

std::string AlertCriteria::TRIGRAM(TRIGRAM_ALERT_CRITERIA);

AlertCriteria::AlertCriteria()
{
    //ctor
     this->jsonName = "alertCriteria";
}

AlertCriteria::~AlertCriteria()
{

}


std::string AlertCriteria::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboCollection(this->informationUnitTypes , "information_unit_types");
    res += Table::formatJSONForDboCollection(this->alertValues, "alert_values", false);
    
    res += "}";
    return res;
}