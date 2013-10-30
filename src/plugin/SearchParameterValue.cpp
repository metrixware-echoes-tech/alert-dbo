/* 
 * Search Parameter Value Table
 * @author ECHOES Technologies (TSA)
 * @date 07/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "plugin/SearchParameterValue.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string SearchParameterValue::TRIGRAM(TRIGRAM_SEARCH_PARAMETER_VALUE);

        SearchParameterValue::SearchParameterValue()
        {
            this->jsonName = "search_parameter_value";
        }

        SearchParameterValue::SearchParameterValue(const SearchParameterValue& orig)
        {
        }

        SearchParameterValue::~SearchParameterValue()
        {

        }

        std::string SearchParameterValue::toJSON() const
        {
            std::string res = "";
            res = "{\n\t";
            res += "\"id\": {" + boost::lexical_cast<std::string>(this->searchParameterValueId) + " },\n";
            res += Table::toJSON();
            res.replace(res.size() - 2, 1, "");

            res += "}";
            return res;
        }
    }
}
