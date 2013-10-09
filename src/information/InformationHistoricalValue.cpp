/* 
 * Information Historical Value Table
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

#include "information/InformationHistoricalValue.h"

std::string InformationHistoricalValue::TRIGRAM(TRIGRAM_INFORMATION_HISTORICAL_VALUE);

InformationHistoricalValue::InformationHistoricalValue()
{
    this->jsonName = "information_historical_value";
    //ctor
}

InformationHistoricalValue::~InformationHistoricalValue()
{
    //dtor
}

std::string InformationHistoricalValue::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->asset);
    res += Table::formatJSONForDboPtr(this->syslog);
    res += Table::formatJSONForDboPtr(this->information , false);
    
    res += "}";
    return res;
}

