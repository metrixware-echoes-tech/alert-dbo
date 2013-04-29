/* 
 * File:   Syslog.cpp
 * Author: tsa
 * 
 * Created on 5 juin 2012, 17:44
 */

#include "information/Syslog.h"

std::string Syslog::TRIGRAM(TRIGRAM_SYSLOG);

Syslog::Syslog()
{
    this->jsonName = "syslog";
}

Syslog::Syslog(const Syslog& orig)
{
}

Syslog::~Syslog()
{
}

std::string Syslog::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->probe, false);
    res += Table::formatJSONForDboCollection(this->values, "information_values");
    res += Table::formatJSONForDboCollection(this->historicalValues, "historical_information_values", false);
    
    res += "}";
    return res;
}
