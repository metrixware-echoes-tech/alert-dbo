#include "alert/AlertTracking.h"

std::string AlertTracking::TRIGRAM(TRIGRAM_ALERT_TRACKING);

AlertTracking::AlertTracking()
{
    this->jsonName = "alertTracking";
    //ctor
}

AlertTracking::~AlertTracking()
{

}

std::string AlertTracking::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alert);
    res += Table::formatJSONForDboPtr(this->mediaValue);
   
    res += Table::formatJSONForDboCollection(this->alertTrackingEvents, "alert_tracking_event" , false);
    
    res += "}";
    return res;
}