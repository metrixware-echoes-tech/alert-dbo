/* 
 * Search Type Table
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

#include "search/SearchType.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string SearchType::TRIGRAM(TRIGRAM_SEARCH_TYPE);

        SearchType::SearchType()
        {
            this->jsonName = "search_type";
        }

        SearchType::SearchType(const SearchType& orig)
        {
        }

        SearchType::~SearchType()
        {

        }

        std::string SearchType::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->searches, "searches");
            res += Table::formatJSONForDboCollection(this->searchParameters, "search_parameters");
            res += Table::formatJSONForDboCollection(this->addons, "addons", false);


            res += "}";
            return res;
        }
    }
}
