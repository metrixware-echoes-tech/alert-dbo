#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <sstream>

#include "tools/dboSpecialization.h"
#include "boost/optional.hpp"

#include <Wt/WDateTime>

#define BOOL_STR(b) ((b)?"true":"false")
#define quote(x) #x

template<typename T>
std::string to_string( const T & Value )
{
    // utiliser un flux de sortie pour créer la chaîne
    std::ostringstream oss;
    // écrire la valeur dans le flux
    oss << Value;
    // renvoyer une string
    return oss.str();
}

class Table //classe abstraite
{
    public:
        Table();
        virtual ~Table();

        static std::string TABLE_PREFIX;
        
        Wt::WDateTime deleteTag;
        std::string jsonName;
        
        template<typename T>
        std::string formatColumnName(const T &x, std::string value);
        
        template<typename T>
        std::string formatIdColumnName(const T &x);
        
        template<typename T>
        std::string formatJSONForDboPtr(const T &x, bool column = true);
        
        template<typename T>
        std::string formatJSONForDboCollection(const T &x, std::string name, bool column = true);
        
        template<class Action>
        void persist(Action& a)
        {
            
        }
        
        virtual std::string toJSON();
        
        
        std::string produceResString(std::string key, std::string value, bool quote = true, bool column = true);
        
        
    protected:
        std::map <std::string,Wt::WString*> mapClassAttributesStrings;
        std::map <std::string,Wt::WDateTime*> mapClassAttributesDates;
        std::map <std::string,bool*> mapClassAttributesBools;
        std::map <std::string,int*> mapClassAttributesInts;
        std::map <std::string,boost::optional<Wt::WString>* > mapClassAttributesStringsNn;
        std::map <std::string,boost::optional<int>* > mapClassAttributesIntsNn;
        std::map <std::string,short*> mapClassAttributesShorts;
        std::map <std::string,long long*> mapClassAttributesSerials;
        
};


/**
 * Definition and implementation of template functions must be in the same file.
 * Make sure you place both between the #ifndef / #endif anchors to prevent
 * duplicates.
 */

template<typename T>
std::string Table::formatColumnName(const T &x, std::string value)
{
    return T::TRIGRAM + SEP + value;
}

template<typename T>
std::string Table::formatJSONForDboPtr(const T &x, bool column)
{
    std::string res = "";
    std::string key1 = "ID";
    std::string value1 = boost::lexical_cast<std::string>(x.id());
    std::string key2 = "NAME";
    std::string value2 = x->name.toUTF8();
    res += "\t\"" + x->jsonName + "\" : ";
    res += "{\n";
    res += "\t " + produceResString(key1,value1,false);
    res += "\t " + produceResString(key2,value2, true, false);
    res += "\t}";
    if (column)
    {
        res += ",";
    }
    res += "\n";
    return res;
}

template<typename T>
std::string Table::formatJSONForDboCollection(const T &x, std::string name, bool column)
{
    std::string res = "";
    std::string size = boost::lexical_cast<std::string>(x.size());
    res += produceResString(name, size, false, column);
    return res;
}
#endif


