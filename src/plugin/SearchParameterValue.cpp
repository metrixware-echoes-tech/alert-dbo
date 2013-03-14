/* 
 * File:   SearchParameterValue.cpp
 * Author: tsa
 * 
 * Created on 7 juin 2012, 15:27
 */

#include "plugin/SearchParameterValue.h"

std::string SearchParameterValue::TRIGRAM(TRIGRAM_SEARCH_PARAMETER_VALUE);

SearchParameterValue::SearchParameterValue()
{
    this->jsonName = "search_parameter_value";
}

SearchParameterValue::SearchParameterValue(const SearchParameterValue& orig)
{
}

SearchParameterValue::~SearchParameterValue()
{

}

std::string SearchParameterValue::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->searchParameterValueId) + " },\n";
    res += Table::toJSON();
    res.replace(res.size()-2, 1, "");
    
    
    res += "}\n";
    return res;
}