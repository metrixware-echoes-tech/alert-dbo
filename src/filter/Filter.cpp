/* 
 * Filgooetr Table
 * @author ECHOES Technologies (TSA)
 * @date 30/10/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "filter/Filter.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string Filter::TRIGRAM(TRIGRAM_FILTER);

        Filter::Filter()
        {
            
        }

        Filter::Filter(const Filter& orig)
        {
        }

        Filter::~Filter()
        {
        }
    }
}

