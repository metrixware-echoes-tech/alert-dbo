/* 
 * Alert Acknowledge Table
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

#include "alert/AlertAcknowledge.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string AlertAcknowledge::TRIGRAM(TRIGRAM_ALERT_ACKNOWLEDGE);

        AlertAcknowledge::AlertAcknowledge()
        {
            this->jsonName = "alertAcknoledge";
            //ctor
        }

        AlertAcknowledge::~AlertAcknowledge()
        {
        }

        std::string AlertAcknowledge::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->alert);
            res += Table::formatJSONForDboPtr(this->user, false);

            res += "}";
            return res;
        }
    }
}

