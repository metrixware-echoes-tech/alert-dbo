/* 
 * File:   SourceParameterValue.cpp
 * Author: tsa
 * 
 * Created on 4 juin 2012, 17:25
 */

#include "plugin/SourceParameterValue.h"

std::string SourceParameterValue::TRIGRAM(TRIGRAM_SOURCE_PARAMETER_VALUE);

SourceParameterValue::SourceParameterValue()
{
    this->jsonName = "source_parameter_value";
}

SourceParameterValue::SourceParameterValue(const SourceParameterValue& orig)
{
}

SourceParameterValue::~SourceParameterValue()
{

}

std::string SourceParameterValue::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res.replace(res.size()-2, 1, "");
    
    
    res += "}";
    return res;
}