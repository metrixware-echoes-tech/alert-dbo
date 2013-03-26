/* 
 * File:   SearchUnit.cpp
 * Author: rhi
 * 
 * Created on 9 octobre 2012, 10:28
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

std::string SearchUnit::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->informationUnit, false);
    
    res += "}\n";
    return res;
}