#include "media/MediaValue.h"

std::string MediaValue::TRIGRAM(TRIGRAM_MEDIA_VALUE);

MediaValue::MediaValue()
{
    this->jsonName = "media_value";
    //ctor
}

MediaValue::~MediaValue()
{
}

std::string MediaValue::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->media);
    res += Table::formatJSONForDboPtr(this->user);
    
    res += Table::formatJSONForDboCollection(this->alertTrackings, "alerts_trackings");
    res += Table::formatJSONForDboCollection(this->alertMediaSpecializations, "alerts_medias_specializations", false);
    
    
    res += "}\n";
    return res;
}