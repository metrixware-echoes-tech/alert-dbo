/* 
 * Media Value Table
 * @author ECHOES Technologies (TSA)
 * @date 23/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "media/MediaValue.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string MediaValue::TRIGRAM(TRIGRAM_MEDIA_VALUE);

        MediaValue::MediaValue()
        {
            this->jsonName = "media_value";
            //ctor
        }

        MediaValue::~MediaValue()
        {
        }

        std::string MediaValue::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->media);
            res += Table::formatJSONForDboPtr(this->user);

            res += Table::formatJSONForDboCollection(this->alertTrackings, "alerts_trackings");
            res += Table::formatJSONForDboCollection(this->alertMediaSpecializations, "alerts_medias_specializations", false);

            res += "}";
            return res;
        }
    }
}

