/* 
 * Alert Sequence Table
 * @author ECHOES Technologies (TSA)
 * @date 15/08/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "alert/AlertSequence.h"

namespace Echoes
{
    namespace Dbo
    {
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

        std::string AlertSequence::toJSON() const
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
    }
}

