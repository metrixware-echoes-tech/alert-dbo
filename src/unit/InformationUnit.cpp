/* 
 * Information Unit Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "unit/InformationUnit.h"

std::string InformationUnit::TRIGRAM(TRIGRAM_INFORMATION_UNIT);

InformationUnit::InformationUnit()
{
    this->jsonName = "information_unit";
    //ctor
}

InformationUnit::~InformationUnit()
{
 
}

std::string InformationUnit::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->unitType);
    
    res += Table::formatJSONForDboCollection(this->searchUnits, "search_units");
    res += Table::formatJSONForDboCollection(this->informationSubUnits, "information_sub_units", false);
   
    res += "}";
    return res;
}

