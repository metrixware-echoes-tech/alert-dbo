/* 
 * Alert Tracking Event Table
 * @author ECHOES Technologies (TSA)
 * @date 30/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "alert/AlertTrackingEvent.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string AlertTrackingEvent::TRIGRAM(TRIGRAM_ALERT_TRACKING_EVENT);

        AlertTrackingEvent::AlertTrackingEvent()
        {
            this->jsonName = "alertTrackingEvent";
        }

        AlertTrackingEvent::AlertTrackingEvent(const AlertTrackingEvent& orig)
        {
        }

        AlertTrackingEvent::~AlertTrackingEvent()
        {
        }

        std::string AlertTrackingEvent::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->alertTracking, false);

            res += "}";
            return res;
        }
    }
}

