/* 
 * Alert Media Alias Information Table
 * @author ECHOES Technologies (TSA)
 * @date 25/02/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
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

std::string AlertMessageAliasInformation::toJSON() const
{
    std::string res = "{\n";
    res += Table::toJSON();
    res += "\"id\": {\n" + boost::lexical_cast<std::string>(this->pk) + " }\n";
    res += "}\n";
    return res;
}

