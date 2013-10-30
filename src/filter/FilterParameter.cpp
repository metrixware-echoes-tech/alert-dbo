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
            this->jsonName = "filter_parameter";
        }

        FilterParameter::FilterParameter(const FilterParameter& orig)
        {
        }

        FilterParameter::~FilterParameter()
        {
        }
        
        std::string FilterParameter::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->filterTypes, "filter_types", false);

            res += "}";
            return res;
        }

    }
}


        

