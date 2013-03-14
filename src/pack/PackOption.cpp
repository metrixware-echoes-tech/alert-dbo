/* 
 * File:   PackOption.cpp
 * Author: rhi
 * 
 * Created on 10 septembre 2012, 22:07
 */

#include "pack/PackOption.h"

std::string PackOption::TRIGRAM(TRIGRAM_PACK_OPTION);


PackOption::PackOption() 
{
    this->jsonName = "pack_option";
    //ctor
}

PackOption::~PackOption() 
{

}

std::string PackOption::toJSON()
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res.replace(res.size()-2, 1, "");
    res += "}\n";
    return res;
}