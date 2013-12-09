/* 
 * Filter Parameter Table
 * @author ECHOES Technologies (TSA)
 * @date 30/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "filter/FilterParameter.h"

namespace Echoes
{
    namespace Dbo
    {

        std::string FilterParameter::TRIGRAM(TRIGRAM_FILTER_PARAMETER);
        
        FilterParameter::FilterParameter()
        {
        }

        FilterParameter::FilterParameter(const FilterParameter& orig)
        {
        }

        FilterParameter::~FilterParameter()
        {
        }
        

    }
}


        

