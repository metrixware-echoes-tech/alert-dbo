/* 
 * File:   SearchType.cpp
 * Author: tsa
 * 
 * Created on 7 juin 2012, 15:26
 */

#include "plugin/SearchType.h"

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

std::string SearchType::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
 
    res += Table::formatJSONForDboCollection(this->searches, "searches");
    res += Table::formatJSONForDboCollection(this->searchParameters, "search_parameters");
    res += Table::formatJSONForDboCollection(this->addons, "addons", false);
    
    
    res += "}";
    return res;
}
