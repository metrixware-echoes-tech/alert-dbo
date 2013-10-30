/* 
 * Source Parameter Table
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

#include "plugin/SourceParameter.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string SourceParameter::TRIGRAM(TRIGRAM_SOURCE_PARAMETER);

        SourceParameter::SourceParameter()
        {
            this->jsonName = "source_parameter";
        }

        SourceParameter::SourceParameter(const SourceParameter& orig)
        {
        }

        SourceParameter::~SourceParameter()
        {

        }

        std::string SourceParameter::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->Addons, "addons", false);

            res += "}";
            return res;
        }
    }
}
