#include "alert/AlertValue.h"

std::string AlertValue::TRIGRAM(TRIGRAM_ALERT_VALUE);

AlertValue::AlertValue()
{
    this->jsonName = "alertValue";
    //ctor
}

AlertValue::~AlertValue()
{
}

std::string AlertValue::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->information, true, true);
    res += Table::formatJSONForDboPtr(this->alertCriteria);
   
    res += Table::formatJSONForDboCollection(this->alerts, "alerts");
    res += Table::formatJSONForDboCollection(this->alertSequences, "alerts_sequences", false);
    
    res += "}\n";
    return res;
}