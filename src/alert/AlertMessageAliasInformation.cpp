/* 
 * File:   AlertMessageAliasInformation.cpp
 * Author: tsa
 * 
 * Created on 25 février 2013, 18:29
 */

#include "alert/AlertMessageAliasInformation.h"

std::string AlertMessageAliasInformation::TRIGRAM(TRIGRAM_ALERT_MESSAGE_ALIAS_INFORMATION);

AlertMessageAliasInformation::AlertMessageAliasInformation()
{
    this->jsonName = "alert_message_alias_information";
}

AlertMessageAliasInformation::AlertMessageAliasInformation(const AlertMessageAliasInformation& orig)
{
}

AlertMessageAliasInformation::~AlertMessageAliasInformation()
{
}

std::string AlertMessageAliasInformation::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    
    
    res += "}\n";
    return res;
}