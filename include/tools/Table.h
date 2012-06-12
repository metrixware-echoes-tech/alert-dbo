#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "dboSpecialization.h"

#include <Wt/WDateTime>

class Table //classe abstraite
{
    public:
        Table();
        virtual ~Table();

        static std::string SEP;
        static std::string TABLE_PREFIX;
        
        Wt::WDateTime deleteTag;

        template<typename T>
        std::string formatColumnName(const T &x, std::string value);
        
        
        template<class Action>
        void persist(Action& a)
        {
            
            std::map<std::string,std::string>::iterator itStrings;
            for(itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings)
            {
                Wt::Dbo::field(a, (*itStrings).second, formatColumnName(*this,(*itStrings).first));
            }

            std::map<std::string,Wt::WDateTime>::iterator itDates;
            for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates)
            {
                Wt::Dbo::field(a, (*itDates).second, formatColumnName(*this,(*itDates).first));
            }
        }
    protected:
        std::map <std::string,std::string> mapClassAttributesStrings;
        std::map <std::string,Wt::WDateTime> mapClassAttributesDates;

};


/**
 * Definition and implementation of template functions must be in the same file.
 * Make sure you place both between the #ifndef / #endif anchors to prevent
 * duplicates.
 */

template<typename T>
std::string Table::formatColumnName(const T &x, std::string value)
{
    return T::TRIGRAM + Table::SEP + value;
}
#endif


