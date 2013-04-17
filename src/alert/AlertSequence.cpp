/* 
 * File:   AlertSequence.cpp
 * Author: tsa
 * 
 * Created on 15 août 2012, 15:21
 */

#include "alert/AlertSequence.h"

std::string AlertSequence::TRIGRAM(TRIGRAM_ALERT_SEQUENCE);

AlertSequence::AlertSequence()
{
    this->jsonName = "alertSequence";
}

AlertSequence::AlertSequence(const AlertSequence& orig)
{
}

AlertSequence::~AlertSequence()
{

}

std::string AlertSequence::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alertValue);
    res += Table::formatJSONForDboPtr(this->alertSequence);
    res += Table::formatJSONForDboPtr(this->alertSequenceBelongTo);
    
    res += Table::formatJSONForDboCollection(this->alerts, "alerts", false);
 
    res += "}";
    return res;
}