#include "information/Information.h"

std::string Information2::TRIGRAM(TRIGRAM_INFORMATION);

Information2::Information2()
{
     this->jsonName = "information2";
    //ctor
}

Information2::~Information2()
{
}

std::string Information2::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->alertValues, "alert_values", false);
    
    res += "}\n";
    return res;
}