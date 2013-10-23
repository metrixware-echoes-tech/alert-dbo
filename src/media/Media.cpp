/* 
 * Media Table
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

#include "media/Media.h"

std::string Media::TRIGRAM(TRIGRAM_MEDIA);

Media::Media()
{
    this->jsonName = "media";
    //ctor
}

Media::~Media()
{

}

std::string Media::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->mediaValues, "media_values", false);
    
    
    res += "}";
    return res;
}

