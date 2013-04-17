/* 
 * File:   AlertAcknowledgeEvent.cpp
 * Author: tsa
 * 
 * Created on 30 juillet 2012, 17:02
 */

#include "alert/AlertTrackingEvent.h"

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

std::string AlertTrackingEvent::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alertTracking , false);
    
    res += "}";
    return res;
}