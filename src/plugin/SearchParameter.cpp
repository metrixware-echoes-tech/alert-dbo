/* 
 * Search Parameter Table
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

#include "plugin/SearchParameter.h"

std::string SearchParameter::TRIGRAM(TRIGRAM_SEARCH_PARAMETER);

SearchParameter::SearchParameter()
{
    this->jsonName = "search_parameter";
}

SearchParameter::SearchParameter(const SearchParameter& orig)
{
}

SearchParameter::~SearchParameter()
{
}

std::string SearchParameter::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->searchTypes, "search_types", false);
    
    
    res += "}";
    return res;
}

