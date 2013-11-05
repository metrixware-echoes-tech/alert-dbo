/* 
 * Organization Table
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

#include "organization/Organization.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string Organization::TRIGRAM(TRIGRAM_ORGANIZATION);

        Organization::Organization()
        {
            this->jsonName = "user";
            //ctor
        }

        Organization::~Organization()
        {
        }

        std::string Organization::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->pack);
            res += Table::formatJSONForDboPtr(this->organizationType);

            res += Table::formatJSONForDboCollection(this->users, "user");
            res += Table::formatJSONForDboCollection(this->probes, "probes");
            res += Table::formatJSONForDboCollection(this->plugins, "plugins");
            res += Table::formatJSONForDboCollection(this->assets, "assets", false);

            res += "}";
            return res;
        }
    }
}

