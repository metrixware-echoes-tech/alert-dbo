/* 
 * Organization Field Table
 * @author ECHOES Technologies (TSA)
 * @date 09/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "organization/OrganizationField.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string OrganizationField::TRIGRAM(TRIGRAM_ORGANIZATION_FIELD);

        OrganizationField::OrganizationField()
        {
            //ctor
        }

        OrganizationField::~OrganizationField()
        {
        }
    }
}

