/* 
 * Search Unit Table
 * @author ECHOES Technologies (RHI)
 * @date 09/10/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "plugin/SearchUnit.h"

std::string SearchUnit::TRIGRAM(TRIGRAM_SEARCH_UNIT);

SearchUnit::SearchUnit() 
{
    this->jsonName = "search_unit";
        //ctor
}


SearchUnit::~SearchUnit() 
{

}

std::string SearchUnit::toJSON() const
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->informationUnit, false);
    
    res += "}";
    return res;
}

