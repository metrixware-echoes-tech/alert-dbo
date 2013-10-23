/* 
 * Source Table
 * @author ECHOES Technologies (TSA)
 * @date 04/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
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

std::string Source::toJSON() const
{
    std::string res = "";
    res = "{\n\t";
    res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->addon, false);
   
    res += "}";
    return res;
}

