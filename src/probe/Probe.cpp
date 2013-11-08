/* 
 * Probe Table
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

#include "probe/Probe.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string Probe::TRIGRAM(TRIGRAM_PROBE);

        Probe::Probe()
        {
            this->jsonName = "probe";
        }

        Probe::~Probe()
        {

        }

        std::string Probe::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += this->probePackageParameter.modify()->toJSON();

            res += Table::formatJSONForDboCollection(this->syslogs, "syslogs");
            res += Table::formatJSONForDboCollection(this->assets, "assets");

            res += "}";
            return res;
        }
    }
}

