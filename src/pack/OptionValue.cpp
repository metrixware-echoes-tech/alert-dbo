/* 
 * Option Value Table
 * @author ECHOES Technologies (RHI)
 * @date 10/09/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
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

std::string OptionValue::toJSON() const
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res.replace(res.size()-2, 1, "");
    res += "}";
    return res;
}

