/* 
 * Addon Table
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

#include "addon/Addon.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string Addon::TRIGRAM(TRIGRAM_ADDON);

        Addon::Addon()
        {
            this->jsonName = "addon";
            //ctor
        }

        Addon::~Addon()
        {
            //dtor
        }

        std::string Addon::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->sources, "sources");
            res += Table::formatJSONForDboCollection(this->searchTypes, "search_types");
            res += Table::formatJSONForDboCollection(this->sourceParameters, "sources_parameters", false);


            res += "}";
            return res;
        }
    }
}

