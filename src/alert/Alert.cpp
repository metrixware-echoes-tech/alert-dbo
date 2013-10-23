/* 
 * Alert Table
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

#include "alert/Alert.h"

std::string Alert::TRIGRAM(TRIGRAM_ALERT);

Alert::Alert()
{
    //ctor
    this->jsonName = "alert";
}

Alert::~Alert()
{
    //dtor
}


std::string Alert::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alertValue, true);
    res += Table::formatJSONForDboPtr(this->alertSequence, true);
    res += Table::formatJSONForDboPtr(this->engine, true);
   
    res += Table::formatJSONForDboCollection(this->alertAcks, "alerts");
    res += Table::formatJSONForDboCollection(this->alertTrackings, "alert_tracking");
    res += Table::formatJSONForDboCollection(this->alertMediaSpecializations, "alert_media_specializations", false);    
    
    res += "}";
    return res;
}

