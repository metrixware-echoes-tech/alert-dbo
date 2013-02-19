/* 
 * File:   AlertMediaSpecialization.cpp
 * Author: tsa
 * 
 * Created on 24 septembre 2012, 14:27
 */

#include "alert/AlertMediaSpecialization.h"

std::string AlertMediaSpecialization::TRIGRAM(TRIGRAM_ALERT_MEDIA_SPECIALIZATION);

AlertMediaSpecialization::AlertMediaSpecialization() {
    this->jsonName = "alertMediaSpecialization";
}

AlertMediaSpecialization::AlertMediaSpecialization(const AlertMediaSpecialization& orig) {
}

AlertMediaSpecialization::~AlertMediaSpecialization() {

}

std::string AlertMediaSpecialization::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alert);
    res += Table::formatJSONForDboPtr(this->mediaValue, false);
    
    res += "}\n";
    return res;
}