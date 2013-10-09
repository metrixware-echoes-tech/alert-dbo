/* 
 * Search Table
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

#include "plugin/Search.h"

std::string Search::TRIGRAM(TRIGRAM_SEARCH);

Search::Search()
{
    this->jsonName = "search";
}

Search::Search(const Search& orig)
{
}

Search::~Search()
{

}

std::string Search::toJSON() const
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->searchType, false);    
    
    res += "}";
    return res;
}

