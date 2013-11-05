/* 
 * Asset Table
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

#include "asset/Asset.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string Asset::TRIGRAM(TRIGRAM_ASSET);

        Asset::Asset()
        {
            this->jsonName = "asset";
        }

        Asset::~Asset()
        {

        }

        std::string Asset::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->probe);
            res += Table::formatJSONForDboPtr(this->assetArchitecture);
            res += Table::formatJSONForDboPtr(this->assetDistribution);
            res += Table::formatJSONForDboPtr(this->assetRelease);

            res += Table::formatJSONForDboCollection(this->values, "information_values");
            res += Table::formatJSONForDboCollection(this->historicalValues, "historical_information_values", false);

            res += "}";
            return res;
        }
    }
}

