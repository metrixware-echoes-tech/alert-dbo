#include "tools/Table.h"

std::string Table::TABLE_PREFIX("T");


Table::Table()
{
    this->name = "";
    this->jsonName = "should_be_overriden";
    this->id = -2;
}

Table::~Table()
{

}

void Table::setId(long long idTmp)
{
    this->id = idTmp;
}

std::string Table::toJSON()
{
    std::string resString = "";
    if (this->id != -2)
    {
        resString = "{\n";
        resString += "\t\"id\" : " + boost::lexical_cast<std::string>(this->id) + ",\n";
    }
    std::map<std::string,Wt::WString*>::iterator itStrings;
    for(itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings)
    {
        std::string key = itStrings->first;
        std::string value = itStrings->second->toUTF8();
        resString += produceResString(key,value);
    }

    std::map<std::string,Wt::WDateTime*>::iterator itDates;
    for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates)
    {
        std::string key = itDates->first;
        std::string value = itDates->second->toString().toUTF8();
        resString += produceResString(key,value);
    }

    std::map<std::string,bool*>::iterator itBools;
    for(itBools = mapClassAttributesBools.begin(); itBools != mapClassAttributesBools.end(); ++itBools)
    {
        std::string key = itBools->first;
        std::string value = BOOL_STR(*itBools->second);
        resString += produceResString(key,value,false);
    }

    std::map<std::string,int*>::iterator itInts;
    for(itInts = mapClassAttributesInts.begin(); itInts != mapClassAttributesInts.end(); ++itInts)
    {
        std::string key = itInts->first;
        std::string value = to_string(*itInts->second);
        resString += produceResString(key,value,false);
    }

    std::map<std::string,boost::optional<Wt::WString>*>::iterator itOptStrings;
    for(itOptStrings = mapClassAttributesStringsNn.begin(); itOptStrings != mapClassAttributesStringsNn.end(); ++itOptStrings)
    {
        std::string key = itOptStrings->first;
        if (*itOptStrings->second)
        {
            std::string value = (*itOptStrings->second).get().toUTF8();
            resString += produceResString(key,value);
        }
    }

    std::map<std::string,boost::optional<int>*>::iterator itOptInts;
    for(itOptInts = mapClassAttributesIntsNn.begin(); itOptInts != mapClassAttributesIntsNn.end(); ++itOptInts)
    {
        std::string key = itOptInts->first;
        if (*itOptInts->second)
        {
            std::string value = to_string(*itOptInts->second);
            resString += produceResString(key,value,false);
        }
    }

    std::map<std::string,short*>::iterator itShorts;
    for(itShorts = mapClassAttributesShorts.begin(); itShorts != mapClassAttributesShorts.end(); ++itShorts)
    {
        std::string key = itShorts->first;
        std::string value = to_string(*itShorts->second);
        resString += produceResString(key,value,false);
    }

    std::map<std::string,long long*>::iterator itLongs;
    for(itLongs = mapClassAttributesSerials.begin(); itLongs != mapClassAttributesSerials.end(); ++itLongs)
    {
        std::string key = itLongs->first;
        std::string value = to_string(*itLongs->second);
        resString += produceResString(key,value,false);
    }
    
   
    // concatenate everything
    
     std::string res = resString;
//    res += "}\n";

    return res;
}

std::string Table::produceResString(std::string key, std::string value, bool quote, bool column, bool composite)
{
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);
    std::string resString = "\t";
    resString += "\"" + key +"\"";
    resString += ": ";
    if (composite) // si c'est une pk composée
    {
        resString += "{\n\t\t";
    }
    if (quote) 
    {
        resString += "\"";
    }
    resString += value;
    if (quote)
    {
        resString += "\"";
    }
    if (composite)
    {
        resString += "\n\t\t}";
    }
    if (column)
    {
        resString += ",";
    }
    resString += "\n";  
    return resString;
}




