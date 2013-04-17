/* 
 * File:   Search.cpp
 * Author: tsa
 * 
 * Created on 7 juin 2012, 15:23
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

std::string Search::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->searchType, false);    
    
    res += "}";
    return res;
}