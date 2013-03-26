/* 
 * File:   SearchParameter.cpp
 * Author: tsa
 * 
 * Created on 7 juin 2012, 15:26
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

std::string SearchParameter::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->searchTypes, "search_types", false);
    
    
    res += "}\n";
    return res;
}