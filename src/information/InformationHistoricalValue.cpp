#include "information/InformationHistoricalValue.h"

std::string InformationHistoricalValue::TRIGRAM(TRIGRAM_INFORMATION_HISTORICAL_VALUE);

InformationHistoricalValue::InformationHistoricalValue()
{
    this->jsonName = "information_historical_value";
    //ctor
}

InformationHistoricalValue::~InformationHistoricalValue()
{
    //dtor
}

std::string InformationHistoricalValue::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->asset);
    res += Table::formatJSONForDboPtr(this->syslogHistory);
    res += Table::formatJSONForDboPtr(this->information , false);
    
    res += "}";
    return res;
}
