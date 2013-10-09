/* 
 * Alert Media Alias Asset Table
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

#include "alert/AlertMessageAliasAsset.h"

std::string AlertMessageAliasAsset::TRIGRAM(TRIGRAM_ALERT_MESSAGE_ALIAS_ASSET);

AlertMessageAliasAsset::AlertMessageAliasAsset()
{
    this->jsonName = "alert_message_alias_asset";
}

AlertMessageAliasAsset::AlertMessageAliasAsset(const AlertMessageAliasAsset& orig)
{
}

AlertMessageAliasAsset::~AlertMessageAliasAsset()
{
}

std::string AlertMessageAliasAsset::toJSON() const
{
    std::string res = "{\n";
    res += Table::toJSON();
    res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " }\n";
    res += "}\n";
    return res;
}

