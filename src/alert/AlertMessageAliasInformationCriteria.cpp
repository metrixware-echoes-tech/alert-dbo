/* 
 * Alert Media Alias Information Criteria Table
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

#include "alert/AlertMessageAliasInformationCriteria.h"

std::string AlertMessageAliasInformationCriteria::TRIGRAM(TRIGRAM_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA);

AlertMessageAliasInformationCriteria::AlertMessageAliasInformationCriteria()
{
    this->jsonName = "alert_message_alias_information_criteria";
}

AlertMessageAliasInformationCriteria::AlertMessageAliasInformationCriteria(const AlertMessageAliasInformationCriteria& orig)
{
}

AlertMessageAliasInformationCriteria::~AlertMessageAliasInformationCriteria()
{
}

std::string AlertMessageAliasInformationCriteria::toJSON() const
{
    std::string res = "{\n";
    res += Table::toJSON();
    res += "\"id\": {\n" + boost::lexical_cast<std::string>(this->pk) + " }\n";
    res += "}\n";
    return res;
}

