/* 
 * Alert Message Definition Table
 * @author ECHOES Technologies (TSA)
 * @date 22/02/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "alert/AlertMessageDefinition.h"

namespace Echoes
{
    namespace Dbo
    {
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

        std::string AlertMessageDefinition::toJSON() const
        {
            std::string res = "";
            res = "{\n\t";
            res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->pk.alert);
            res += Table::formatJSONForDboPtr(this->pk.userRole);
            res += Table::formatJSONForDboPtr(this->pk.mediaType);
            res += "}\n";
            return res;
        }
    }
}

