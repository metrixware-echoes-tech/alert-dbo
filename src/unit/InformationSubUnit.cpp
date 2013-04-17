/* 
 * File:   InformationSubUnit.cpp
 * Author: tsa
 * 
 * Created on 8 novembre 2012, 17:36
 */

#include "unit/InformationSubUnit.h"

std::string InformationSubUnit::TRIGRAM(TRIGRAM_INFORMATION_SUB_UNIT);

InformationSubUnit::InformationSubUnit() {
    this->jsonName = "information_sub_unit";
}

InformationSubUnit::InformationSubUnit(const InformationSubUnit& orig) {
}

InformationSubUnit::~InformationSubUnit() 
{

}

std::string InformationSubUnit::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->informationUnit , false);
    
    res += "}";
    return res;
}