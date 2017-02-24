/**
 * @file Table.h
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
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
