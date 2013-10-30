/* 
 * Alert Value Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "alert/AlertValue.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string AlertValue::TRIGRAM(TRIGRAM_ALERT_VALUE);

        AlertValue::AlertValue()
        {
            this->jsonName = "alertValue";
            //ctor
        }

        AlertValue::~AlertValue()
        {
        }

        std::string AlertValue::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->information, true, true);
            res += Table::formatJSONForDboPtr(this->alertCriteria);
            res += Table::formatJSONForDboPtr(this->asset);

            res += Table::formatJSONForDboCollection(this->alerts, "alerts");
            res += Table::formatJSONForDboCollection(this->alertSequences, "alerts_sequences", false);

            res += "}";
            return res;
        }
    }
}

