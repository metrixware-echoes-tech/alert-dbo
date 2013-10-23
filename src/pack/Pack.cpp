/* 
 * Pack Table
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

#include "pack/Pack.h"

std::string Pack::TRIGRAM(TRIGRAM_PACK);

Pack::Pack()
{
    this->jsonName = "pack";
    //ctor
}

Pack::~Pack()
{

}

std::string Pack::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->organizations, "organizations");
    res += Table::formatJSONForDboCollection(this->packOptions, "pack_options", false);
    
    
    res += "}";
    return res;
}

