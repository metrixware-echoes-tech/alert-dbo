/* 
 * Information Value Table
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

#include "information/InformationValue.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string InformationValue::TRIGRAM(TRIGRAM_INFORMATION_VALUE);

        InformationValue::InformationValue() : Table()
        {
            this->jsonName = "information_value";
            //ctor
        }

        InformationValue::~InformationValue()
        {
            //dtor
        }

        std::string InformationValue::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->asset);
            res += Table::formatJSONForDboPtr(this->syslog);
            res += Table::formatJSONForDboPtr(this->information, false, true);

            res += "}";
            return res;
        }
    }
}

