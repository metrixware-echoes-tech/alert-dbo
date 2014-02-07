/* 
 * Alert Media Alias Plugin Table
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

#include "alert/AlertMessageAliasPlugin.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string AlertMessageAliasPlugin::TRIGRAM(TRIGRAM_ALERT_MESSAGE_ALIAS_PLUGIN);

        AlertMessageAliasPlugin::AlertMessageAliasPlugin()
        {
            this->jsonName = "alert_message_alias_plugin";
        }

        AlertMessageAliasPlugin::AlertMessageAliasPlugin(const AlertMessageAliasPlugin& orig)
        {
        }

        AlertMessageAliasPlugin::~AlertMessageAliasPlugin()
        {
        }

        std::string AlertMessageAliasPlugin::toJSON() const
        {
            std::string res = "{\n";
            res += Table::toJSON();
            res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " }\n";
            res += "}\n";
            return res;
        }
    }
}

