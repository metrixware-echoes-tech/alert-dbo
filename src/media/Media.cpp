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

std::string Media::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->mediaValues, "media_values", false);
    
    
    res += "}";
    return res;
}