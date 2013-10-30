/* 
 * File:   FilterType.cpp
 * Author: tsa
 * 
 * Created on 30 octobre 2013, 17:53
 */

#include "filter/FilterType.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string FilterType::TRIGRAM(TRIGRAM_FILTER_TYPE);

        FilterType::FilterType()
        {
            this->jsonName = "filter_type";
        }

        FilterType::FilterType(const FilterType& orig)
        {
        }

        FilterType::~FilterType()
        {
        }

        std::string FilterType::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->filters, "filters");
            res += Table::formatJSONForDboCollection(this->filterParameters, "filter_parameters");


            res += "}";
            return res;
        }

    }
}




