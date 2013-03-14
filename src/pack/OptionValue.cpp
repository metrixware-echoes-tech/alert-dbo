/* 
 * File:   OptionValue.cpp
 * Author: rhi
 * 
 * Created on 10 septembre 2012, 22:26
 */

#include "pack/OptionValue.h"

std::string OptionValue::TRIGRAM(TRIGRAM_OPTION_VALUE);

OptionValue::OptionValue()
{
    this->jsonName = "option_value";
    //ctor
}

OptionValue::~OptionValue()
{

}

std::string OptionValue::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res.replace(res.size()-2, 1, "");
    res += "}\n";
    return res;
}