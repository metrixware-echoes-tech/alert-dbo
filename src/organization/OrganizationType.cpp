/* 
 * Organization Type Table
 * @author ECHOES Technologies (RHI)
 * @date 03/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "organization/OrganizationType.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string OrganizationType::TRIGRAM(TRIGRAM_ORGANIZATION_TYPE);

        OrganizationType::OrganizationType()
        {
            this->jsonName = "organization_type";
            //ctor
        }

        OrganizationType::~OrganizationType()
        {

        }

        std::string OrganizationType::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->organization, "organization");
            res += Table::formatJSONForDboCollection(this->organizationField, "organization_field", false);

            res += "}";
            return res;
        }
    }
}

