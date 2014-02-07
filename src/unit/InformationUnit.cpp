/* 
 * Information Unit Table
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

#include "unit/InformationUnit.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string InformationUnit::TRIGRAM(TRIGRAM_INFORMATION_UNIT);

        InformationUnit::InformationUnit()
        {
            this->jsonName = "information_unit";
            //ctor
        }

        InformationUnit::~InformationUnit()
        {

        }

    }
}

