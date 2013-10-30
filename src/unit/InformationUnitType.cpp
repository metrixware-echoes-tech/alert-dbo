/* 
 * Information Unit Type Table
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

#include "unit/InformationUnitType.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string InformationUnitType::TRIGRAM(TRIGRAM_INFORMATION_UNIT_TYPE);

        InformationUnitType::InformationUnitType()
        {
            this->jsonName = "information_unit_type";
            //ctor
        }

        InformationUnitType::~InformationUnitType()
        {

        }

        std::string InformationUnitType::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->alertCriterias, "alerts_criterias");
            res += Table::formatJSONForDboCollection(this->units, "units", false);

            res += "}";
            return res;
        }
    }
}

