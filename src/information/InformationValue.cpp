#include "information/InformationValue.h"

std::string InformationValue::TRIGRAM(TRIGRAM_INFORMATION_VALUE);

InformationValue::InformationValue() : Table()
{
    this->jsonName = "information_value";
    //ctor
}

InformationValue::~InformationValue()
{
    //dtor
}

std::string InformationValue::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->asset);
    res += Table::formatJSONForDboPtr(this->syslog);
    res += Table::formatJSONForDboPtr(this->information ,false, true);
    
    res += "}";
    return res;
}