#ifndef TABLE_H
#define TABLE_H

#include <string>

#include "tools/dboSpecialization.h"
#include "boost/optional.hpp"

#include <Wt/WDateTime>

class Table //classe abstraite
{
    public:
        Table();
        virtual ~Table();

        static std::string TABLE_PREFIX;
        
        Wt::WDateTime deleteTag;

        template<typename T>
        std::string formatColumnName(const T &x, std::string value);
        
        template<typename T>
        std::string formatIdColumnName(const T &x);
        
        
        template<class Action>
        void persist(Action& a)
        {
            
        }
    protected:
        std::map <std::string,std::string> mapClassAttributesStrings;
        std::map <std::string,Wt::WDateTime> mapClassAttributesDates;
        std::map <std::string,bool> mapClassAttributesBools;
        std::map <std::string,int> mapClassAttributesInts;
        std::map <std::string,boost::optional<std::string> > mapClassAttributesStringsNn;

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
#endif


