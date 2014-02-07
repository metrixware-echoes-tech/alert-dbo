/* 
 * Source Parameter Value Table
 * @author ECHOES Technologies (TSA)
 * @date 04/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "source/SourceParameterValue.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string SourceParameterValue::TRIGRAM(TRIGRAM_SOURCE_PARAMETER_VALUE);

        SourceParameterValue::SourceParameterValue()
        {
            this->jsonName = "source_parameter_value";
        }

        SourceParameterValue::SourceParameterValue(const SourceParameterValue& orig)
        {
        }

        SourceParameterValue::~SourceParameterValue()
        {

        }

        std::string SourceParameterValue::toJSON() const
        {
            std::string res = "";
            res = "{\n\t";
            res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
            res += Table::toJSON();
            res.replace(res.size() - 2, 1, "");

            res += "}";
            return res;
        }
    }
}
