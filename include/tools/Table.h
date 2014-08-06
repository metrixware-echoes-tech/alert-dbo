/* 
 * Header of Parent Class for Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef TABLE_H
#define TABLE_H

#include <Wt/WDateTime>
#include <Wt/WString>
#include <Wt/Dbo/Dbo>

#include "tools/dboSpecialization.h"

#define BOOL_STR(b) ((b)?"true":"false")

namespace Echoes
{
  namespace Dbo
  {
    class Table //classe abstraite
    {
        public:
            Table();
            Table(const Table& orig);
            virtual ~Table();

            long long id;
            Wt::WString name;
            Wt::WDateTime deleteTag;

            template<typename T>
            std::string formatColumnName(const T &x, std::string value) const;

            template<class Action>
            void persist(Action& a);

        protected:
            std::map <std::string, Wt::WString*> mapClassAttributesStrings;
            std::map <std::string, Wt::WDateTime*> mapClassAttributesDates;
            std::map <std::string, bool*> mapClassAttributesBools;
            std::map <std::string, int*> mapClassAttributesInts;
            std::map <std::string, boost::optional<Wt::WString>* > mapClassAttributesStringsNn;
            std::map <std::string, boost::optional<int>* > mapClassAttributesIntsNn;
            std::map <std::string, short*> mapClassAttributesShorts;
            std::map <std::string, long long*> mapClassAttributesSerials;

            template<class Action, class Object>
            void fieldFiller(Action& a, Object& obj);
    };

    /**
     * Definition and implementation of template functions must be in the same file.
     * Make sure you place both between the #ifndef / #endif anchors to prevent
     * duplicates.
     */
    template<typename T>
    std::string Table::formatColumnName(const T &x, std::string value) const
    {
        return T::TRIGRAM + SEP + value;
    }
    
    template<class Action, class Object>
    void Table::fieldFiller(Action& a, Object& obj)
    {
        mapClassAttributesDates["DELETE"]=&this->deleteTag;

        std::map<std::string, Wt::WString*>::iterator itStrings;
        for (itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings)
        {
            Wt::Dbo::field(a, *itStrings->second, formatColumnName(obj, (*itStrings).first));
        }
        std::map<std::string, Wt::WDateTime*>::iterator itDates;
        for (itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates)
        {
            Wt::Dbo::field(a, *itDates->second, formatColumnName(obj, (*itDates).first));
        }
        std::map < std::string, bool*>::iterator itBools;
        for (itBools = mapClassAttributesBools.begin(); itBools != mapClassAttributesBools.end(); ++itBools)
        {
            Wt::Dbo::field(a, *itBools->second, formatColumnName(obj, (*itBools).first));
        }
        std::map<std::string, int*>::iterator itInts;
        for (itInts = mapClassAttributesInts.begin(); itInts != mapClassAttributesInts.end(); ++itInts)
        {
            Wt::Dbo::field(a, *itInts->second, formatColumnName(obj, (*itInts).first));
        }
        std::map<std::string, short*>::iterator itShorts;
        for (itShorts = mapClassAttributesShorts.begin(); itShorts != mapClassAttributesShorts.end(); ++itShorts)
        {
            Wt::Dbo::field(a, *itShorts->second, formatColumnName(obj, (*itShorts).first));
        }
        std::map<std::string, boost::optional<Wt::WString>* >::iterator itStringsNn;
        for (itStringsNn = mapClassAttributesStringsNn.begin(); itStringsNn != mapClassAttributesStringsNn.end(); ++itStringsNn)
        {
            Wt::Dbo::field(a, *itStringsNn->second, formatColumnName(obj, (*itStringsNn).first));
        }
        std::map<std::string, boost::optional<int>* >::iterator itIntsNn;
        for (itIntsNn = mapClassAttributesIntsNn.begin(); itIntsNn != mapClassAttributesIntsNn.end(); ++itIntsNn)
        {
            Wt::Dbo::field(a, *itIntsNn->second, formatColumnName(obj, (*itIntsNn).first));
        }
        std::map<std::string, long long* >::iterator itSerials;
        for (itSerials = mapClassAttributesSerials.begin(); itSerials != mapClassAttributesSerials.end(); ++itSerials)
        {
            Wt::Dbo::field(a, *itSerials->second, formatColumnName(obj, (*itSerials).first));
        }
    }
  }
}
#endif	/* TABLE_H */

