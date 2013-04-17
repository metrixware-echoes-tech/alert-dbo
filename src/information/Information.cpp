#include "information/Information.h"

std::string Information2::TRIGRAM(TRIGRAM_INFORMATION);

Information2::Information2()
{
     this->jsonName = "information";
    //ctor
}

Information2::Information2(const Information2 &orig)
: Table(orig)
{
    this->alertValues = orig.alertValues;
    this->calculate = orig.calculate;
    this->desc = orig.desc;
    this->display = orig.display;
    this->pk = orig.pk;
}

Information2::~Information2()
{
}

std::string Information2::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->alertValues, "alert_values", false);
    
    res += "}";
    return res;
}