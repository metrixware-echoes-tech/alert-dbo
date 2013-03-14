/* 
 * File:   Source.cpp
 * Author: tsa
 * 
 * Created on 4 juin 2012, 14:15
 */

#include "plugin/Source.h"

std::string Source::TRIGRAM(TRIGRAM_SOURCE);

Source::Source()
{
    this->jsonName = "source";
}

Source::Source(const Source& orig)
{
}

Source::~Source()
{

}

std::string Source::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->addon, false);
   
    res += "}\n";
    return res;
}