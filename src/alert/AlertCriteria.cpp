/* 
 * Alert Criteria Table
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

#include "alert/AlertCriteria.h"

std::string AlertCriteria::TRIGRAM(TRIGRAM_ALERT_CRITERIA);

AlertCriteria::AlertCriteria()
{
    //ctor
     this->jsonName = "alertCriteria";
}

AlertCriteria::~AlertCriteria()
{

}


std::string AlertCriteria::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboCollection(this->informationUnitTypes , "information_unit_types");
    res += Table::formatJSONForDboCollection(this->alertValues, "alert_values", false);
    
    res += "}";
    return res;
}

