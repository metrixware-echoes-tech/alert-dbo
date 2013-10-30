/* 
 * Option Table
 * @author ECHOES Technologies (TSA)
 * @date 03/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "pack/Option.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string Option::TRIGRAM(TRIGRAM_OPTION);

        Option::Option()
        {
            this->jsonName = "option";
            //ctor
        }

        Option::~Option()
        {
        }

        std::string Option::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->packOptions, "pack_option", false);

            res += "}";
            return res;
        }
    }
}

