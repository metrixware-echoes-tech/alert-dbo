/* 
 * Syslog Table
 * @author ECHOES Technologies (TSA)
 * @date 05/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "information/Syslog.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string Syslog::TRIGRAM(TRIGRAM_SYSLOG);

        Syslog::Syslog()
        {
            this->jsonName = "syslog";
        }

        Syslog::Syslog(const Syslog& orig)
        {
        }

        Syslog::~Syslog()
        {
        }

        std::string Syslog::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->probe, false);
            res += Table::formatJSONForDboCollection(this->values, "information_values");
            res += Table::formatJSONForDboCollection(this->historicalValues, "historical_information_values", false);

            res += "}";
            return res;
        }
    }
}

