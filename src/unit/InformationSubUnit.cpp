/* 
 * Information Sub Unit Table
 * @author ECHOES Technologies (TSA)
 * @date 08/11/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "unit/InformationSubUnit.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string InformationSubUnit::TRIGRAM(TRIGRAM_INFORMATION_SUB_UNIT);

        InformationSubUnit::InformationSubUnit()
        {
            this->jsonName = "information_sub_unit";
        }

        InformationSubUnit::InformationSubUnit(const InformationSubUnit& orig)
        {
        }

        InformationSubUnit::~InformationSubUnit()
        {

        }

        std::string InformationSubUnit::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->informationUnit, false);

            res += "}";
            return res;
        }
    }
}

