/* 
 * Plugin Table
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

#include "plugin/Plugin.h"

std::string Plugin::TRIGRAM(TRIGRAM_PLUGIN);

Plugin::Plugin()
{
    this->jsonName = "plugin";
    //ctor
}

Plugin::~Plugin()
{

}

std::string Plugin::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();
    
    res += Table::formatJSONForDboCollection(this->assets, "assets", false);

    res += "}";
    return res;
}

