#include "alert/AlertAcknowledge.h"

std::string AlertAcknowledge::TRIGRAM(TRIGRAM_ALERT_ACKNOWLEDGE);

AlertAcknowledge::AlertAcknowledge()
{
    this->jsonName = "alertAcknoledge";
    //ctor
}

AlertAcknowledge::~AlertAcknowledge()
{
}


std::string AlertAcknowledge::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alert);
    res += Table::formatJSONForDboPtr(this->user, false);
    
    
    res += "}\n";
    return res;
}