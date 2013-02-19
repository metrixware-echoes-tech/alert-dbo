#include "alert/Alert.h"

std::string Alert::TRIGRAM(TRIGRAM_ALERT);

Alert::Alert()
{
    //ctor
    this->jsonName = "alert";
}

Alert::~Alert()
{
    //dtor
}


std::string Alert::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alertValue, true);
    res += Table::formatJSONForDboPtr(this->alertSequence, true);
    res += Table::formatJSONForDboPtr(this->engine, true);
   
    res += Table::formatJSONForDboCollection(this->assets, "assets");
    res += Table::formatJSONForDboCollection(this->alertAcks, "alerts");
    res += Table::formatJSONForDboCollection(this->alertTrackings, "plugins");
    res += Table::formatJSONForDboCollection(this->alertMediaSpecializations, "information_values", false);    
    
    res += "}\n";
    return res;
}