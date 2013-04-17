/* 
 * File:   SourceParameter.cpp
 * Author: tsa
 * 
 * Created on 4 juin 2012, 17:41
 */

#include "plugin/SourceParameter.h"

std::string SourceParameter::TRIGRAM(TRIGRAM_SOURCE_PARAMETER);

SourceParameter::SourceParameter()
{
    this->jsonName = "source_parameter";
}

SourceParameter::SourceParameter(const SourceParameter& orig)
{
}

SourceParameter::~SourceParameter()
{

}

std::string SourceParameter::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->Addons, "addons", false);
    
    
    res += "}";
    return res;
}