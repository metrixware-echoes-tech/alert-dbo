/* 
 * File:   AlertMessageDefinition.cpp
 * Author: tsa
 * 
 * Created on 22 février 2013, 16:35
 */

#include "alert/AlertMessageDefinition.h"

std::string AlertMessageDefinition::TRIGRAM(TRIGRAM_ALERT_MESSAGE_DEFINITION);

AlertMessageDefinition::AlertMessageDefinition()
{
    this->jsonName = "alert_message_definition";
}

AlertMessageDefinition::AlertMessageDefinition(const AlertMessageDefinition& orig)
{
}

AlertMessageDefinition::~AlertMessageDefinition()
{
}

std::string AlertMessageDefinition::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alert);
    res += Table::formatJSONForDboPtr(this->userRole);
    res += Table::formatJSONForDboPtr(this->media);
    res += "}\n";
    return res;
}


