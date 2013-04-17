/* 
 * File:   SyslogHistory.cpp
 * Author: tsa
 * 
 * Created on 5 juin 2012, 17:44
 */

#include "information/SyslogHistory.h"

std::string SyslogHistory::TRIGRAM(TRIGRAM_SYSLOG_HISTORY);

SyslogHistory::SyslogHistory()
{
    this->jsonName = "syslog_history";
}

SyslogHistory::SyslogHistory(const SyslogHistory& orig)
{
}

SyslogHistory::~SyslogHistory()
{
}

std::string SyslogHistory::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->probe);
  
    res += Table::formatJSONForDboCollection(this->values, "information_values");
    res += Table::formatJSONForDboCollection(this->historicalValues, "historical_information_values", false);
        
    res += "}";
    return res;
}