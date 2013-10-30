/* 
 * Alert Media Specialization Table
 * @author ECHOES Technologies (TSA)
 * @date 24/09/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "alert/AlertMediaSpecialization.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string AlertMediaSpecialization::TRIGRAM(TRIGRAM_ALERT_MEDIA_SPECIALIZATION);

        AlertMediaSpecialization::AlertMediaSpecialization()
        {
            this->jsonName = "alertMediaSpecialization";
        }

        AlertMediaSpecialization::AlertMediaSpecialization(const AlertMediaSpecialization& orig)
        {
        }

        AlertMediaSpecialization::~AlertMediaSpecialization()
        {

        }

        std::string AlertMediaSpecialization::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->alert);
            res += Table::formatJSONForDboPtr(this->mediaValue, false);

            res += "}";
            return res;
        }
    }
}

